#include "Thor/timer.h"

#include <GLFW/glfw3.h>

float m_LastCalledTime = 0;

float GetTimeStep()
{
    float time = glfwGetTime();
    float timestep = time - m_LastCalledTime;
    m_LastCalledTime = time;
    return timestep;
}