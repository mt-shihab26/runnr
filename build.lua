include "tools/vendor.lua"
include "tools/clangd.lua"
include "tools/clean.lua"


local build_dir = ".build/%{cfg.system == 'emscripten' and 'web' or cfg.system}-%{cfg.architecture}"
local bin_dir = build_dir .. "/bin/%{cfg.buildcfg}"
local obj_dir = build_dir .. "/obj/%{cfg.buildcfg}/%{prj.name}"


workspace "runnr"
    configurations { "debug", "release" }
    location "."
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


include "vendor/build/raylib.lua"


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

