#pragma once
#include <windows.h>
#include "utility.cpp"

internal void clear_screen(u32 color = 0xAAAAAA) {
    unsigned int* pixel = (u32*)render_state.memory;
    for (int y = 0; y < render_state.height; y++) {
        for (int x = 0; x < render_state.width; x++) {
            *pixel++ = color;
        }
    }
}

internal void draw_rect_pixel(u32 poz_x, u32 poz_y, u32 poz_x_fin, u32 poz_y_fin, u32 color) {
    s32 x0 = clamp(0, poz_x, render_state.width);
    s32 x1 = clamp(0, poz_x_fin, render_state.width);
    s32 y0 = clamp(0, poz_y, render_state.height);
    s32 y1 = clamp(0, poz_y_fin, render_state.height);
    for (u32 y =  y0; y < y1; y++) {
        u32* pixel = (u32*)render_state.memory + x0 + y*render_state.width;
        for (u32 x = x0; x < x1; x++) {
            *pixel++ = color;
        }
    }
}

global_variable float render_scale = 0.01f;
internal void draw_rect(float poz_x, float poz_y, float half_size_x, float half_size_y, u32 color) { //precentage
    poz_x *= render_state.height * render_scale;
    poz_y *= render_state.height * render_scale;
    half_size_x *= render_state.height * render_scale;
    half_size_y *= render_state.height * render_scale;

    poz_x += render_state.width / 2.f; // offset to middle
    poz_y += render_state.height / 2.f;

    s32 x0 = (poz_x - half_size_x);
    s32 x1 = (poz_x + half_size_x);
    s32 y0 = (poz_y - half_size_y);
    s32 y1 = (poz_y + half_size_y);

    draw_rect_pixel(x0, y0, x1, y1, color);
}