-- stop: lsp
-- stop: format


local build_dir = ".build/%{cfg.system == 'emscripten' and 'web' or cfg.system}-%{cfg.architecture}"
local bin_dir = build_dir .. "/bin/%{cfg.buildcfg}"
local obj_dir = build_dir .. "/obj/%{cfg.buildcfg}/%{prj.name}"


premake.api.register {
    name = "clangd",
    scope = "config",
    kind = "boolean",
}


workspace "runnr"
    configurations { "debug", "release" }
    targetdir(bin_dir)
    objdir(obj_dir)

    filter "system:linux"
        architecture "x86_64"
        toolset "clang"
        defines { "PLATFORM_LINUX" }

    filter "system:emscripten"
        architecture "wasm32"
        toolset "emcc"
        defines { "PLATFORM_WEB" }

    filter "configurations:debug"
        defines { "DEBUG" }
        symbols "On"

    filter "configurations:release"
        defines { "NDEBUG" }
        optimize "On"

    filter {}


project "runnr"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++23"
    warnings "Extra"

    files { "include/**.hpp", "src/**.hpp", "src/**.cpp" }
    includedirs { "src", "include" }
    externalincludedirs { "vendor/include" }
    links { "raylib" }

    filter "system:linux"
        links { "GL", "m", "pthread", "dl", "rt", "X11" }
        clangd "On"

    filter "system:emscripten"
        targetextension ".html"
        linkoptions {
            "-sUSE_GLFW=3",
            "-sALLOW_MEMORY_GROWTH=1",
            "--shell-file scripts/web/shell.html",
            "--preload-file assets",
        }
        postbuildcommands {
            "{COPYFILE} scripts/web/favicon.svg %{cfg.targetdir}",
            "{COPYFILE} scripts/web/favicon.ico %{cfg.targetdir}",
        }

    filter { "system:emscripten", "configurations:release" }
        postbuildcommands {
            "rsvg-convert scripts/web/preview.svg -o %{cfg.targetdir}/preview.png",
        }

    filter "configurations:release"
        postbuildcommands {
            "{DELETE} %{cfg.targetdir}/*.a",
        }

    filter {}


project "raylib"
    kind "StaticLib"
    language "C"
    cdialect "C99"
    warnings "Off"

    files {
        "vendor/upstream/raylib/src/rcore.c",
        "vendor/upstream/raylib/src/rshapes.c",
        "vendor/upstream/raylib/src/rtextures.c",
        "vendor/upstream/raylib/src/rtext.c",
        "vendor/upstream/raylib/src/rmodels.c",
        "vendor/upstream/raylib/src/raudio.c",
    }

    includedirs { "vendor/upstream/raylib/src" }

    filter "system:linux"
        files { "vendor/upstream/raylib/src/rglfw.c" }
        includedirs { "vendor/upstream/raylib/src/external/glfw/include" }
        defines { "PLATFORM_DESKTOP_GLFW", "GRAPHICS_API_OPENGL_33", "_GLFW_X11" }

    filter "system:emscripten"
        cdialect "gnu99"
        defines { "PLATFORM_WEB", "GRAPHICS_API_OPENGL_ES2" }

    filter {}


premake.override(premake.main, "postAction", function(base)
    base()

    if _ACTION == "clean" then
        return
    end

    for wks in premake.global.eachWorkspace() do
        for prj in premake.workspace.eachproject(wks) do
            local cfg = premake.project.getconfig(prj, "debug")
            if not cfg.clangd then
                goto continue
            end

            local flags = { "-xc++", "-std=" .. cfg.cppdialect:lower() }

            for _, dir in ipairs(cfg.includedirs) do
                table.insert(flags, "-I" .. path.getrelative(prj.basedir, dir))
            end
            for _, dir in ipairs(cfg.externalincludedirs) do
                table.insert(flags, "-isystem" .. path.getrelative(prj.basedir, dir))
            end

            if cfg.warnings == "Extra" then
                table.insert(flags, "-Wall")
                table.insert(flags, "-Wextra")
            end

            for _, define in ipairs(cfg.defines) do
                table.insert(flags, "-D" .. define)
            end

            local file = path.join(prj.basedir, "compile_flags.txt")
            io.writefile(file, table.concat(flags, "\n") .. "\n")
            printf("Generated %s...", path.getrelative(os.getcwd(), file))

            ::continue::
        end
    end
end)


newaction {
    trigger = "clean",
    description = "Remove all generated build files",
    execute = function()
        os.execute("git clean -fdX")
    end,
}
