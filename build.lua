-- stop: lsp
-- stop: format


local build_dir = ".build/%{cfg.system == 'emscripten' and 'web' or cfg.system}-%{cfg.architecture}"
local bin_dir = build_dir .. "/bin/%{cfg.buildcfg}"
local obj_dir = build_dir .. "/obj/%{cfg.buildcfg}/%{prj.name}"


workspace "runnr"
    configurations { "debug", "release" }
    targetdir(bin_dir)
    objdir(obj_dir)

    filter "system:linux"
        architecture "x86_64"
        toolset "gcc"

    filter "system:emscripten"
        architecture "wasm32"
        toolset "emcc"

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

    filter "system:emscripten"
        targetextension ".html"
        linkoptions {
            "-sUSE_GLFW=3",
            "-sALLOW_MEMORY_GROWTH=1",
            "--shell-file vendor/upstream/raylib/src/minshell.html",
            "--preload-file assets",
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


newaction {
    trigger = "clean",
    description = "Remove all generated build files",
    execute = function()
        os.rmdir(".build")
        os.rmdir(".cache")
        os.remove("Makefile")
        os.remove("*.make")
        os.remove("*.sln")
        os.remove("*.slnx")
        os.remove("*.vcxproj")
        os.remove("*.vcxproj.filters")
        os.remove("*.vcxproj.user")
        os.rmdir(".vs")
        for _, dir in ipairs(os.matchdirs("*.xcodeproj")) do os.rmdir(dir) end
        for _, dir in ipairs(os.matchdirs("*.xcworkspace")) do os.rmdir(dir) end
        os.remove("*.ninja")
        os.remove(".ninja_deps")
        os.remove(".ninja_log")
        os.remove("*.workspace")
        os.remove("*.project")
    end,
}
