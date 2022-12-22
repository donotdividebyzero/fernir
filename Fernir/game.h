#pragma once

#include "player.h"

#include <GLFW/glfw3.h>
#include <cglm/cglm.h>

class Game
{
public:
    Game();
    ~Game();
    Mesh *GetMesh();
    void GameOnUpdate(float ts);
    void KeyPressed(int key);
    void KeyReleased(int key);
private:
    Player *m_Player;
    float m_Rotation;
    vec3 m_PlayerHeight;
    unsigned int m_PressedKeys[GLFW_KEY_LAST];
};