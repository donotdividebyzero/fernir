#include "window.h"
#include "camera.h"
#include "timer.h"

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

        CameraUpdate(ts);
        RenderApplication(&window, ts);
        WindowUpdate();
    }

    DestroyApplication();
    WindowDestroy(&window);
    return 0;
}