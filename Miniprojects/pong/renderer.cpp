#include <windows.h>
#include "utility.cpp"

internal void clear_screen() {
    unsigned int* pixel = (u32*)render_state.memory;
    for (int y = 0; y < render_state.height; y++) {
        for (int x = 0; x < render_state.width; x++) {
            *pixel++ = 0xAAAAAA;
        }
    }
}

internal void draw_rect_pixel(int poz_x, int poz_y, int poz_x_fin, int poz_y_fin, u32 color) {
    poz_x = clamp(0, poz_x, render_state.width);
    poz_x_fin = clamp(0, poz_x_fin, render_state.width);
    poz_y = clamp(0, poz_y, render_state.height);
    poz_y_fin = clamp(0, poz_y_fin, render_state.height);
    for (int y =  poz_y; y < poz_y_fin; y++) {
        u32* pixel = (u32*)render_state.memory + poz_x + y*render_state.width;
        for (int x = poz_x; x < poz_x_fin; x++) {
            *pixel++ = color;
        }
    }
}
internal void draw_rect(float poz_x, float poz_y, float size_x, float size_y, u32 color) { //precentage
    poz_x /= 100;   poz_x *= render_state.height;
    poz_y /= 100;   poz_y *= render_state.height;
    size_x /= 100;  size_x *= render_state.height;
    size_y /= 100;  size_y *= render_state.height;

    u16 x0 = poz_x;
    u16 x1 = poz_x + size_x;
    u16 y0 = poz_y;
    u16 y1 = poz_y + size_y;

    draw_rect_pixel(x0, y0, x1, y1, color);
}