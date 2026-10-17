#pragma once

#include <string>

// Directory assets are loaded from: next to the executable in release, the project root in debug,
// and the root of the virtual filesystem on the web.
std::string project_dir();

// Joins a path relative to the project root onto project_dir().
std::string project_path(const std::string &relative_path);

// define PATH_IMPLEMENTATION in one .cpp before including this
#ifdef PATH_IMPLEMENTATION

#include <filesystem>

#if defined(_WIN32)
// avoids <windows.h>, which clashes with raylib
extern "C" __declspec(dllimport) unsigned long __stdcall GetModuleFileNameW(void *module, wchar_t *filename, unsigned long size);
#elif defined(__APPLE__)
#include <cstdint>
#include <mach-o/dyld.h>
#endif

std::string project_dir() {
#if defined(__EMSCRIPTEN__)
    // --preload-file assets mounts them at /assets in the browser's virtual filesystem
    return "/";
#elif defined(NDEBUG) && defined(_WIN32)
    wchar_t buffer[260];
    GetModuleFileNameW(nullptr, buffer, 260);
    return std::filesystem::path(buffer).parent_path().string();
#elif defined(NDEBUG) && defined(__APPLE__)
    char buffer[4096];
    uint32_t size = sizeof(buffer);
    _NSGetExecutablePath(buffer, &size);
    return std::filesystem::canonical(buffer).parent_path().string();
#elif defined(NDEBUG)
    return std::filesystem::canonical("/proc/self/exe").parent_path().string();
#else
    return std::filesystem::path(__FILE__).lexically_normal().parent_path().parent_path().parent_path().string();
#endif
}

std::string project_path(const std::string &relative_path) {
    return (std::filesystem::path(project_dir()) / relative_path).string();
}

#endif
