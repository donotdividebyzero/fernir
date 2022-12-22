#include "window.h"
#include "event.h"
#include "graphic.h"

#include <stdio.h>
#include <stdlib.h>

GLFWwindow* s_NativeWindow = NULL;
Window *m_Window = NULL;

void m_WindowWindowResizeEvent(int width, int height)
{
    if (m_Window) {
        glfwGetFramebufferSize(s_NativeWindow, &m_Window->width, &m_Window->height);
    }
}

void error_handler(int error, const char* description)
{
    (void)error;
    fprintf(stderr, "Error: %s\n", description);
}

int WindowShouldClose()
{   
    return glfwWindowShouldClose(s_NativeWindow);
}

void WindowSwapBuffers()
{
    glfwSwapBuffers(s_NativeWindow);
}

void WindowPoolEvents()
{
    glfwPollEvents();
}

void WindowInitialize(Window *window)
{
    m_Window = window;
    if (!glfwInit())
    {
        error_handler(0, "Failed to initializer glfw!");
        exit(EXIT_FAILURE);
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, 1);
#endif 

    glfwSetErrorCallback(error_handler);

    s_NativeWindow = glfwCreateWindow(window->width, window->height, window->title, NULL, NULL);

    if (!s_NativeWindow)
    {
        glfwTerminate();
        error_handler(0, "Failed to create window");
        exit(EXIT_FAILURE);
    }

    glfwMakeContextCurrent(s_NativeWindow);
    if (window->vsync) {
        glfwSwapInterval(1);
    }

    glfwGetFramebufferSize(s_NativeWindow, &window->width, &window->height);
    GraphicApiInitialize(window);
    EventInitialize(s_NativeWindow);
    EventRegisterWindowSetFrameBufferSizeCallback(m_WindowWindowResizeEvent);
}

void WindowUpdate()
{
    WindowPoolEvents();
    WindowSwapBuffers();
}

void WindowDestroy(Window *window)
{
    GraphicApiDestroy(window);
    glfwDestroyWindow(s_NativeWindow);
    glfwTerminate();
}
