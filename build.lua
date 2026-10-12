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

    filter "configurations:debug"
        defines { "DEBUG" }
        symbols "On"

    filter "configurations:release"
        defines { "NDEBUG" }
        optimize "On"

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
