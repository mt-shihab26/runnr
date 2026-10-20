project "raylib"
    kind "StaticLib"
    language "C"
    cdialect "C23"
    warnings "Off"

    files {
        upstream("raylib/src/rcore.c"),
        upstream("raylib/src/rshapes.c"),
        upstream("raylib/src/rtextures.c"),
        upstream("raylib/src/rtext.c"),
        upstream("raylib/src/rmodels.c"),
        upstream("raylib/src/raudio.c"),
    }

    includedirs { upstream("raylib/src") }

    filter "system:linux"
        files { upstream("raylib/src/rglfw.c") }
        includedirs { upstream("raylib/src/external/glfw/include") }
        defines { "PLATFORM_DESKTOP_GLFW", "GRAPHICS_API_OPENGL_33", "_GLFW_X11" }

    filter "system:emscripten"
        cdialect "gnu23"
        defines { "PLATFORM_WEB", "GRAPHICS_API_OPENGL_ES2" }

    filter {}
