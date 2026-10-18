#pragma once

#include <raylib/raylib.h>

namespace runnr {

inline constexpr const char *GAME_TITLE = "runnr. - A 3D endless runner game written in C/C++ with raylib.";

inline constexpr float LANE_WIDTH = 4.0f;
inline constexpr float LANE_MIN_X = -LANE_WIDTH;
inline constexpr float LANE_MAX_X = LANE_WIDTH;

inline constexpr float PLAYER_ANIMATION_SPEED = 60.0f;
inline constexpr float PLAYER_SWITCH_SPEED = 15.0f;

inline constexpr Color FLOOR_COLOR = {51, 65, 85, 255};
inline constexpr Color LANE_LINE_COLOR = {100, 116, 139, 255};
inline constexpr Color BACKGROUND_COLOR = {15, 23, 42, 255};

}
