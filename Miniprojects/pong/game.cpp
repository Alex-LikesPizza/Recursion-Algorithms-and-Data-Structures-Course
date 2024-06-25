#pragma once

#define is_down(button_key) input->buttons[button_key].is_down
#define pressed(button_key) (input->buttons[button_key].is_down && input->buttons[button_key].changed)
#define pressed(button_key) (!input->buttons[button_key].is_down && input->buttons[button_key].changed)

#include "platform_common.cpp"
#include "utility.cpp"

internal void simulate_game(Input* input){
    if (is_down(BUTTON_UP))
        draw_rect(20, 20, 50, 50, 0xFF0000);
    draw_rect(50, 50, 50, 50, 0xFFFF00);
}