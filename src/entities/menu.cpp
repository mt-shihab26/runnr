#include <raylib/raylib.h>

#include "menu.hpp"

namespace runnr {

void Menu::update([[maybe_unused]] float dt) {
    if (m_mode != Mode::MENU) {
        return;
    }

    m_play_hovered = CheckCollisionPointRec(GetMousePosition(), get_play_button());
    SetMouseCursor(m_play_hovered ? MOUSE_CURSOR_POINTING_HAND : MOUSE_CURSOR_DEFAULT);

    bool clicked = m_play_hovered && IsMouseButtonPressed(MOUSE_BUTTON_LEFT);
    if (clicked || IsKeyPressed(KEY_ENTER) || IsKeyPressed(KEY_SPACE)) {
        m_mode = Mode::PLAY;
        m_play_hovered = false;
        SetMouseCursor(MOUSE_CURSOR_DEFAULT);
    }
}

void Menu::ui() {
    if (m_mode != Mode::MENU) {
        return;
    }

    constexpr int font_size = 60;
    constexpr Color color = {234, 88, 12, 255};
    constexpr Color hover_color = {249, 115, 22, 255};
    constexpr Color text_color = {255, 255, 255, 255};

    Rectangle button = get_play_button();
    DrawRectangleRounded(button, 0.3f, 8, m_play_hovered ? hover_color : color);

    const char *text = "PLAY";
    int text_width = MeasureText(text, font_size);
    int text_x = static_cast<int>(button.x + (button.width - text_width) / 2.0f);
    int text_y = static_cast<int>(button.y + (button.height - font_size) / 2.0f);
    DrawText(text, text_x, text_y, font_size, text_color);
}

Rectangle Menu::get_play_button() const {
    constexpr float width = 360.0f;
    constexpr float height = 120.0f;
    constexpr float offset_y = 150.0f;

    float x = (GetScreenWidth() - width) / 2.0f;
    float y = (GetScreenHeight() - height) / 2.0f + offset_y;
    return Rectangle{x, y, width, height};
}

}
