#pragma once

#include <format>
#include <utility>

#include <raylib/raylib.h>

// Logging with std::format style messages, routed through raylib's TraceLog:
//
//   log_info("Registering test '{}' (key: {})", name, key);
//   log_warn("Uniform '{}' doesn't exist", name);
//   log_error("Failed to open shader '{}'", path);
//
// raylib adds the level prefix and respects SetTraceLogLevel / SetTraceLogCallback.

template <typename... Args>
void log_info(std::format_string<Args...> format, Args &&...args) {
    // pass the message as a "%s" argument so any '%' in it isn't treated as printf formatting
    TraceLog(LOG_INFO, "%s", std::format(format, std::forward<Args>(args)...).c_str());
}

template <typename... Args>
void log_warn(std::format_string<Args...> format, Args &&...args) {
    TraceLog(LOG_WARNING, "%s", std::format(format, std::forward<Args>(args)...).c_str());
}

template <typename... Args>
void log_error(std::format_string<Args...> format, Args &&...args) {
    TraceLog(LOG_ERROR, "%s", std::format(format, std::forward<Args>(args)...).c_str());
}
