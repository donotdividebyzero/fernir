#pragma once

#include <GLFW/glfw3.h>

#include "cube.h"

#include <cglm/cglm.h>

class Game
{
public:
    Game();
    ~Game();
    void GameOnUpdate(float ts);
    void KeyPressed(int key);
    void KeyReleased(int key);
private:
    unsigned int m_PressedKeys[GLFW_KEY_LAST];
    Cube* m_Light;
    Shader m_LightShader;
    vec3 m_LightPosition;

    Cube* m_Cube;
    Shader m_CubeShader;
};