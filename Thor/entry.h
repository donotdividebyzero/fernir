#include "window.h"
#include "camera.h"
#include "timer.h"
#include "renderer.h"

extern Window WindowConfig();
extern void CreateApplication(Window *);
extern void RenderApplication(Window *, Timestep);
extern void DestroyApplication();

int main(void) {
    Window window = WindowConfig();
    WindowInitialize(&window);
    CreateApplication(&window);
    
    Timestep ts;
    while (!WindowShouldClose()) {
        ts = GetTimeStep();
        BeginDraw();
        CameraUpdate(ts);
        RenderApplication(&window, ts);
        EndDraw();
        WindowUpdate();
    }

    DestroyApplication();
    WindowDestroy(&window);
    return 0;
}