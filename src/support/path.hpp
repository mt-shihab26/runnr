#pragma once

#include <string>

// Returns the directory that asset paths are resolved against.
//
// Release: the directory containing the executable, where the build copies the assets folder,
// so the binary runs from any working directory.
//
// Debug: the project root, derived from this header's location (<project>/src/support).
// The build compiles by relative path, so this is usually an empty string and paths built
// from it only resolve when running from the project root.
std::string project_dir();

// Returns `relative_path` joined onto the project root.
//
//   project_path("assets/shaders/basic.glsl")
std::string project_path(const std::string &relative_path);

// stb-style implementation: define PATH_IMPLEMENTATION in exactly one .cpp before including this
#ifdef PATH_IMPLEMENTATION

#include <filesystem>

#if defined(_WIN32)
// declared by hand: <windows.h> defines CloseWindow, DrawText, etc. which clash with raylib
extern "C" __declspec(dllimport) unsigned long __stdcall GetModuleFileNameW(void *module, wchar_t *filename, unsigned long size);
#elif defined(__APPLE__)
#include <cstdint>
#include <mach-o/dyld.h>
#endif

static std::filesystem::path executable_path() {
#if defined(_WIN32)
    wchar_t buffer[260];
    GetModuleFileNameW(nullptr, buffer, 260);
    return buffer;
#elif defined(__APPLE__)
    char buffer[4096];
    uint32_t size = sizeof(buffer);
    _NSGetExecutablePath(buffer, &size);
    return std::filesystem::canonical(buffer);
#else
    return std::filesystem::canonical("/proc/self/exe");
#endif
}

std::string project_dir() {
#if defined(NDEBUG)
    return executable_path().parent_path().string();
#else
    // lexically_normal() folds away "../" when the header was included through a relative path
    return std::filesystem::path(__FILE__).lexically_normal().parent_path().parent_path().parent_path().string();
#endif
}

std::string project_path(const std::string &relative_path) {
    return (std::filesystem::path(project_dir()) / relative_path).string();
}

#endif
