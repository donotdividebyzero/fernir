#include "player.h"

#include <string>

#include <cglm/cglm.h>

Player::Player()
{
    m_Mesh.indicies.data = m_Indicies;
    m_Mesh.indicies.size = sizeof(m_Indicies);
    m_Mesh.indicies.count = m_Mesh.indicies.size/sizeof(Index);
    m_Mesh.verticies.data = (Vertex *)m_Vertices;
    m_Mesh.verticies.size = sizeof(m_Vertices);
    m_Mesh.verticies.count = m_Mesh.verticies.size/sizeof(Vertex);

    m_Mesh.shader = CreateShader(
        "Fernir/shader/basic/vertex.glsl",
        "Fernir/shader/basic/fragment.glsl"
    );
}

Player::~Player()
{
}

Mesh* Player::GetMesh()
{
    return &m_Mesh;
}
