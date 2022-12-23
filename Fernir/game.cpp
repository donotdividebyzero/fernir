#include "game.h"

Game::Game()
{
    m_Player = new Player();
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
    m_Player->OnUpdate(ts);
}

void Game::KeyPressed(int key)
{
    m_PressedKeys[key] = 1;
}

void Game::KeyReleased(int key)
{
    m_PressedKeys[key] = 0;
}
