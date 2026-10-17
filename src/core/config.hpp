#pragma once

#include <raylib/raylib.h>

namespace runnr {

inline constexpr float LANE_WIDTH = 4.0f;
inline constexpr float LANE_MIN_X = -LANE_WIDTH;
inline constexpr float LANE_MAX_X = LANE_WIDTH;

inline constexpr float PLAYER_ANIMATION_SPEED = 60.0f;
inline constexpr float PLAYER_SWITCH_SPEED = 15.0f;

inline constexpr Color FLOOR_COLOR = {30, 41, 59, 255};
inline constexpr Color LANE_LINE_COLOR = {71, 85, 105, 255};
inline constexpr Color BACKGROUND_COLOR = {148, 163, 184, 255};

}
