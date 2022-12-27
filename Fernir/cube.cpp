#include "cube.h"

#include "Thor/mesh.h"
#include "Thor/shader.h"
#include "Thor/opengl/mesh.h"

Cube::Cube(Shader *shader) 
{
    mesh = &m_Mesh;
    m_Mesh.verticies.data = (float *)m_Vertices;
    m_Mesh.verticies.size = sizeof(m_Vertices);
    m_Mesh.verticies.count = m_Mesh.verticies.size / m_VertexSize;
    this->shader = shader;
    textures.count = 0;
    m_Mesh.indicies.count = 0;
    OpenGLCreateMesh(&m_Mesh);
}

Cube::~Cube()
{
}