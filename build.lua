-- stop: lsp
-- stop: format

local build_dir = "build/%{cfg.system}-%{cfg.architecture}"
local bin_dir = build_dir .. "/bin/%{cfg.buildcfg}"
local obj_dir = build_dir .. "/obj/%{cfg.buildcfg}/%{prj.name}"

workspace "runnr"
    configurations { "debug", "release" }
    architecture "x86_64"
    targetdir(bin_dir)
    objdir(obj_dir)


project "runnr"
    kind "ConsoleApp"
    language "C"
    cdialect "C23"

    files { "src/**.h", "src/**.c" }
    includedirs { "vendor/raylib/src" }
    links { "raylib" }

    filter "system:linux"
        links { "GL", "m", "pthread", "dl", "rt", "X11" }

    filter "configurations:debug"
        defines { "DEBUG" }
        symbols "On"

    filter "configurations:release"
        defines { "NDEBUG" }
        optimize "On"

    filter {}


project "raylib"
    kind "StaticLib"
    language "C"
    cdialect "C99"
    warnings "Off"

    local raylib_dir = "vendor/raylib/src"

    files {
        raylib_dir .. "/rcore.c",
        raylib_dir .. "/rshapes.c",
        raylib_dir .. "/rtextures.c",
        raylib_dir .. "/rtext.c",
        raylib_dir .. "/rmodels.c",
        raylib_dir .. "/raudio.c",
        raylib_dir .. "/utils.c",
        raylib_dir .. "/rglfw.c",
    }

    includedirs {
        raylib_dir,
        raylib_dir .. "/external/glfw/include",
    }

    defines { "PLATFORM_DESKTOP", "GRAPHICS_API_OPENGL_33" }

    filter {}


newaction {
    trigger = "clean",
    description = "Remove all generated build files",
    execute = function()
        os.rmdir("build")
        os.remove("Makefile")
        os.remove("*.make")
    end,
}
