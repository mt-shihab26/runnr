-- stop: lsp
-- stop: format


local build_dir = ".build/%{cfg.system}-%{cfg.architecture}"
local bin_dir = build_dir .. "/bin/%{cfg.buildcfg}"
local obj_dir = build_dir .. "/obj/%{cfg.buildcfg}/%{prj.name}"


workspace "runnr"
    configurations { "debug", "release" }
    architecture "x86_64"
    targetdir(bin_dir)
    objdir(obj_dir)

    filter "system:linux"
        toolset "gcc"

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

    filter "configurations:release"
        postbuildcommands {
            -- the static libraries are linked into the binary, so they are not needed to run it
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

    filter {}


newaction {
    trigger = "clean",
    description = "Remove all generated build files",
    execute = function()
        os.rmdir(".build")
        os.rmdir(".cache")
        -- GNU Make
        os.remove("Makefile")
        os.remove("*.make")
        -- Visual Studio
        os.remove("*.sln")
        os.remove("*.slnx")
        os.remove("*.vcxproj")
        os.remove("*.vcxproj.filters")
        os.remove("*.vcxproj.user")
        os.rmdir(".vs")
        -- Xcode
        for _, dir in ipairs(os.matchdirs("*.xcodeproj")) do os.rmdir(dir) end
        for _, dir in ipairs(os.matchdirs("*.xcworkspace")) do os.rmdir(dir) end
        -- Ninja
        os.remove("*.ninja")
        os.remove(".ninja_deps")
        os.remove(".ninja_log")
        -- CodeLite
        os.remove("*.workspace")
        os.remove("*.project")
    end,
}
