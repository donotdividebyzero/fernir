#include "player.h"
#include "Thor/timer.h"

#include <string>

#include <cglm/cglm.h>

Player::Player()
{
    m_Mesh.verticies.data = (Vertex *)m_Vertices;
    m_Mesh.verticies.size = sizeof(m_Vertices);
    m_Mesh.verticies.count = m_Mesh.verticies.size/sizeof(Vertex);

    m_Mesh.indicies.data = nullptr;
    m_Mesh.indicies.size = 0;
    m_Mesh.indicies.count = 0;

    m_Mesh.textures[0] = LoadTexture("Fernir/assets/textures/wall.jpg");
    m_Mesh.textures[1] = LoadTexture("Fernir/assets/textures/face.jpg");
 
    Textures textures;
    textures.textures = m_Mesh.textures;
    textures.count = 2; 

    m_Mesh.shader = CreateShader(
        "Fernir/shader/basic/vertex.glsl",
        "Fernir/shader/basic/fragment.glsl",
        &textures
    );

    m_Mesh.positions.count = 10;
    m_Mesh.positions.data = (mat4*)malloc(sizeof(mat4) * m_Mesh.positions.count);  
}

Player::~Player()
{
    delete[] m_Mesh.positions.data;
}

Mesh* Player::GetMesh()
{
    return &m_Mesh;
}

void Player::OnUpdate(float ts)
{
    for(size_t i=0;i<m_Mesh.positions.count;i++) {
        mat4 posModel;
        float angle = 20.0f * i;
        glm_mat4_identity(posModel);
        glm_translate(posModel, (float*)&m_CubePositions[i]);
        if (i%3 == 0) {
            angle = GetTime() * glm_rad(angle);
        }
        glm_rotate(posModel, angle, (vec3){1.0f, 0.3f, 0.5f});
        glm_mat4_copy(posModel, m_Mesh.positions.data[i]);
    }
}
