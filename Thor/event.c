#include "event.h"
#include "window.h"
#include <GLFW/glfw3.h>

#define MAX_EVENT_SIZE_ARRAY 1000

/**
 * @brief KeyCallback Event 
 */
KeyCallback KeyCallbackEvents[MAX_EVENT_SIZE_ARRAY];
size_t KeyCallbackEventsSize = 0;

void EventRegisterKeyCallback(KeyCallback callback)
{
    KeyCallbackEvents[KeyCallbackEventsSize++] = callback;
}
/**
 * @brief Internal implementation of key callback event
 */
void m_KeyCallback(GLFWwindow *window, int key, int scancode, int action, int mods)
{
    (void)window;
    (void)scancode;
    for(size_t i=0; i < KeyCallbackEventsSize; i++) {
        KeyCallback callback = KeyCallbackEvents[i];
        callback(key, action, mods);
    }
}

/**
 * @brief Window Resize Event
 */
WindowResizeCallback WindowResizeCallbackEvents[MAX_EVENT_SIZE_ARRAY];
size_t WindowResizeCallbackEventsCount = 0;

void EventRegisterWindowResizeCallback(WindowResizeCallback callback)
{
    WindowResizeCallbackEvents[WindowResizeCallbackEventsCount++] = callback;
}
/**
 * @brief Internal implementation of window resize event
 */
void m_WindowSizeCallback(GLFWwindow* window, int width, int height) 
{
    (void)window;
    for(size_t i=0; i<WindowResizeCallbackEventsCount; i++) {
        WindowResizeCallback callback = WindowResizeCallbackEvents[i];
        callback(width, height);
    }
}


/**
 * @brief MouseButtonCallback Event
 * 
 */
MouseButtonCallback MouseButtonCallbackEvents[MAX_EVENT_SIZE_ARRAY];
size_t MouseButtonCallbackEventsCount = 0;
void EventRegisterMousButtonCallback(MouseButtonCallback callback)
{
    MouseButtonCallbackEvents[MouseButtonCallbackEventsCount++] = callback;
}

void m_MouseButtonCallback(GLFWwindow* window, int button, int action, int mode) 
{
    (void)window;
    for(size_t i=0; i < MouseButtonCallbackEventsCount; i++) {
        MouseButtonCallback callback = MouseButtonCallbackEvents[i];
        callback(button, action, mode);
    }
}

/**
 * @brief Mouse Scroll Event 
 * 
 */
MouseScrollCallback MouseScrollCallbackEvents[MAX_EVENT_SIZE_ARRAY];
size_t MouseScrollCallbackEventsCount = 0;
void EventRegisterMouseScrollCallback(MouseScrollCallback callback)
{
    MouseScrollCallbackEvents[MouseScrollCallbackEventsCount++] = callback;
}

void m_MouseScrollCallback(GLFWwindow* window, double xoffset, double yoffset)
{
    (void)window;
        for(size_t i=0; i<MouseScrollCallbackEventsCount; i++) {
        MouseScrollCallback callback = MouseScrollCallbackEvents[i];
        callback(xoffset, yoffset);
    }
}


WindowSetFrameBufferSizeCallback WindowSetFrameBufferSizeCallbackEvents[MAX_EVENT_SIZE_ARRAY];
size_t WindowSetFrameBufferSizeCallbackEventsCount = 0;

void EventRegisterWindowSetFrameBufferSizeCallback(WindowSetFrameBufferSizeCallback callback)
{
    WindowSetFrameBufferSizeCallbackEvents[WindowSetFrameBufferSizeCallbackEventsCount++] = callback;
}

void m_WindowSetFrameBufferSizeCallback(GLFWwindow* window, int width, int height)
{
    for(size_t i=0;i<WindowSetFrameBufferSizeCallbackEventsCount;i++) {
        WindowSetFrameBufferSizeCallback callback = WindowSetFrameBufferSizeCallbackEvents[i];
        callback(width, height);
    }
}

MousePosCallback MousePosCallbackEvents[MAX_EVENT_SIZE_ARRAY];
size_t MousePosCallbackEventsCount = 0;

void EventRegisterMousePosCallback(MousePosCallback callback)
{
    MousePosCallbackEvents[MousePosCallbackEventsCount++] = callback;
}

void m_MousePosCallback(GLFWwindow* window, double xpos, double ypos)
{
        for(size_t i=0;i<MousePosCallbackEventsCount;i++) {
        MousePosCallback callback = MousePosCallbackEvents[i];
        callback(xpos, ypos);
    }
}

void EventInitialize(GLFWwindow *window) 
{
    glfwSetKeyCallback(window, m_KeyCallback);
    glfwSetWindowSizeCallback(window, m_WindowSizeCallback);
    glfwSetFramebufferSizeCallback(window, m_WindowSetFrameBufferSizeCallback);
    glfwSetMouseButtonCallback(window, m_MouseButtonCallback);
    glfwSetScrollCallback(window, m_MouseScrollCallback);
    glfwSetCursorPosCallback(window, m_MousePosCallback);  
}

void EventDeinitialize()
{

}