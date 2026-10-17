#pragma once

#include <format>
#include <string>
#include <utility>

// Logging with std::format style messages, routed through raylib's TraceLog:
//
//   log_info("Registering test '{}' (key: {})", name, key);
//   log_warn("Uniform '{}' doesn't exist", name);
//   log_error("Failed to open shader '{}'", path);
//
// raylib adds the level prefix and respects SetTraceLogLevel / SetTraceLogCallback.

enum class LogLevel { Info, Warn, Error };

// Sends an already formatted message to raylib's TraceLog.
void log_write(LogLevel level, const std::string &message);

template <typename... Args>
void log_info(std::format_string<Args...> format, Args &&...args) {
    log_write(LogLevel::Info, std::format(format, std::forward<Args>(args)...));
}

template <typename... Args>
void log_warn(std::format_string<Args...> format, Args &&...args) {
    log_write(LogLevel::Warn, std::format(format, std::forward<Args>(args)...));
}

template <typename... Args>
void log_error(std::format_string<Args...> format, Args &&...args) {
    log_write(LogLevel::Error, std::format(format, std::forward<Args>(args)...));
}

// define LOG_IMPLEMENTATION in one .cpp before including this
#ifdef LOG_IMPLEMENTATION

#include <raylib/raylib.h>

void log_write(LogLevel level, const std::string &message) {
    int raylib_level = LOG_INFO;
    if (level == LogLevel::Warn) raylib_level = LOG_WARNING;
    if (level == LogLevel::Error) raylib_level = LOG_ERROR;

    // pass the message as a "%s" argument so any '%' in it isn't treated as printf formatting
    TraceLog(raylib_level, "%s", message.c_str());
}

#endif
