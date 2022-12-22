#pragma once

#include "Thor/renderer.h"

class Player {
public:
    Player();
    ~Player();
    Mesh* GetMesh();
private:
    Mesh m_Mesh;
    float m_Vertices[28] = {
        -0.5f,   0.5f, 1.0f, 1.0f, 0.24f, 0.0f, 1.0f,
         0.5f,   0.5f, 1.0f, 1.0f, 0.24f, 0.0f, 1.0f,
        -0.5f,  -0.5f, 1.0f, 1.0f, 0.24f, 0.0f, 1.0f,
         0.5f,  -0.5f, 1.0f, 1.0f, 0.24f, 0.0f, 1.0f
    };
    Index m_Indicies[6] = {
        0, 1, 2, 2, 1, 3
    };
};