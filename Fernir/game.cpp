#include "game.h"

Game::Game()
{
    m_Player = new Player();
    m_Rotation = 0.0f;
    glm_vec3_add(m_PlayerHeight, (vec3){200.0f, 50.0f, 0}, m_PlayerHeight);
}

Game::~Game()
{
    delete m_Player;
}

Mesh *Game::GetMesh()
{
    return m_Player->GetMesh();
}

void Game::GameOnUpdate(float ts)
{
    (void)ts;
    if (m_PressedKeys[GLFW_KEY_A]) {
        
    }
    // mat4 trans;
    // glm_mat4_identity(trans);
    // if (m_PressedKeys[GLFW_KEY_SPACE]) {
    //     glm_vec3_add(m_PlayerHeight, (vec3){0.0f, 6.0f,0}, m_PlayerHeight);
    // } else {
    //     glm_vec3_add(m_PlayerHeight, (vec3){0.0f, -3.0f,0}, m_PlayerHeight);
    // }

    // glm_translate(trans, m_PlayerHeight);
    // glm_rotate_z(trans, m_Rotation, m_Player->GetMesh()->transform);

    // m_Rotation += 0.01f;
    // if (m_Rotation > 360.0f) { 
    //     m_Rotation = 0.01f;
    // }
}

void Game::KeyPressed(int key)
{
    m_PressedKeys[key] = 1;
}

void Game::KeyReleased(int key)
{
    m_PressedKeys[key] = 0;
}
