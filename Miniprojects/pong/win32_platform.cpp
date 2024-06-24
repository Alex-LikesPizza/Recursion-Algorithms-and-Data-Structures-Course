#include <windows.h>
#include <winuser.h>
#include "utility.cpp"

#pragma comment(lib, "Gdi32.lib")

global_variable bool running = true;

struct Render_State {
    int height, width;
    void* memory;

    BITMAPINFO bitmap_info;
};

global_variable Render_State render_state;

#include "renderer.cpp"

LRESULT CALLBACK window_callback(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    LRESULT result = 0;
    switch (uMsg) {
        case WM_CLOSE:
        case WM_DESTROY:
        {
            running = false;
        } break;
        case WM_SIZE: {
            RECT rect;
            GetClientRect(hwnd, &rect);
            render_state.width = rect.right - rect.left;
            render_state.height = rect.bottom - rect.top;

            int size = render_state.width * render_state.height * sizeof(unsigned int);

            if (render_state.memory) VirtualFree(render_state.memory, 0, MEM_RELEASE);
            render_state.memory = VirtualAlloc(0, size, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);

            render_state.bitmap_info.bmiHeader.biSize = sizeof(render_state.bitmap_info.bmiHeader);
            render_state.bitmap_info.bmiHeader.biWidth = render_state.width;
            render_state.bitmap_info.bmiHeader.biHeight = render_state.height;
            render_state.bitmap_info.bmiHeader.biPlanes = 1;
            render_state.bitmap_info.bmiHeader.biBitCount = 32;
            render_state.bitmap_info.bmiHeader.biCompression = BI_RGB;
        } break;
        default: {
            result = DefWindowProc(hwnd, uMsg, wParam, lParam);
        }
    }
    return result;
}

int  WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd
) {
	// Create Window Class
	WNDCLASS window_class = {};
	window_class.style = CS_HREDRAW | CS_VREDRAW;
	window_class.lpszClassName = L"Game Window Class";
	window_class.lpfnWndProc = window_callback;
	
	// Registrer Class
	RegisterClass(&window_class);

    HWND window = CreateWindowW(
        window_class.lpszClassName,  // Window class name
        L"My Pong Game",              // Window title
        WS_OVERLAPPEDWINDOW | WS_VISIBLE, // Window style
        CW_USEDEFAULT,               // X position
        CW_USEDEFAULT,               // Y position
        1280,                        // Width
        720,                         // Height
        NULL,                        // Parent window
        NULL,                        // Menu handle
        hInstance,                   // Instance handle
        NULL                         // Additional application data
    );
    HDC hdc = GetDC(window);
    while (running) {
        // Input
        MSG message;
        while (PeekMessage(&message, window, 0, 0, PM_REMOVE)) {
            TranslateMessage(&message);
            DispatchMessage(&message);
        }

        // Simulate
        clear_screen();
        draw_rect(0, 0, 50, 50, 0xFF0000);

        // Render
        StretchDIBits(
            hdc,
            0, 0, render_state.width, render_state.height,
            0, 0, render_state.width, render_state.height,
            render_state.memory,
            &render_state.bitmap_info,
            DIB_RGB_COLORS, SRCCOPY);
    }
}