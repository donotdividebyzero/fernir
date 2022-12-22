#ifndef __THOR_WINDOW_H
#define __THOR_WINDOW_H

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <Thor/core.h>

#ifdef __cplusplus
extern "C" {
#endif

THAPI typedef struct {
    int width;
    int height;
    const char *title;
    int vsync;
    struct {
        int width;
        int height;
    } frame_buffer;
} Window;

THAPI void WindowInitialize(Window *);

THAPI void WindowDestroy(Window *);

THAPI int WindowShouldClose();

THAPI void WindowUpdate();

#ifdef __cplusplus
}
#endif
#endif