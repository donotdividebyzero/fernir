#include "Thor/timer.h"

#include <GLFW/glfw3.h>

#include <stdio.h>

float m_LastCalledTime = 0;

float GetTimeStep()
{
    float time = GetTime();
    float timestep = time - m_LastCalledTime;
    m_LastCalledTime = time;
    return timestep;
}

float GetTime()
{
    return (float)glfwGetTime();
}