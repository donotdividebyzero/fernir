#ifndef __THOR_EVENT_H
#define __THOR_EVENT_H

#include <GLFW/glfw3.h>
#include <Thor/core.h>

#ifdef __cplusplus
extern "C" {
#endif

void EventInitialize(GLFWwindow *);
void EventDeinitialize();

/**
 *  @param[in] key The [keyboard key](@ref keys) that was pressed or released.
 *  @param[in] action `TH_KEY_PRESS`, `TH_KEY_RELEASE` or `TH_KEY_REPEAT`.  Future
 *  releases may add more actions.
 *  @param[in] mods Bit field describing which [modifier keys](@ref mods) were
 *  held down.
*/
THAPI typedef void (*KeyCallback)(int, int, int);
THAPI void EventRegisterKeyCallback(KeyCallback);

/**
 * @brief Window resize event
 * 
 */
THAPI typedef void (*WindowResizeCallback)(int, int);
THAPI void EventRegisterWindowResizeCallback(WindowResizeCallback);

/**
 * @brief Mouse Button Event
 * 
 */
THAPI typedef void (*MouseButtonCallback)(int, int, int);
THAPI void EventRegisterMousButtonCallback(MouseButtonCallback);

/**
 * @brief Mouse Position Event
 * 
 */
THAPI typedef void (*MousePosCallback)(double, double);
THAPI void EventRegisterMousePosCallback(MousePosCallback);

/**
 * @brief Mouse Scroll Event
 * 
 */
THAPI typedef void (*MouseScrollCallback)(double, double);
THAPI void EventRegisterMouseScrollCallback(MouseScrollCallback);

THAPI typedef void (*WindowSetFrameBufferSizeCallback)(int, int);
THAPI void EventRegisterWindowSetFrameBufferSizeCallback(WindowSetFrameBufferSizeCallback);

#ifdef __cplusplus
}
#endif

#endif