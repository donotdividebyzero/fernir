#include "cube.h"

#include "Thor/mesh.h"
#include "Thor/shader.h"
#include "Thor/opengl/mesh.h"

Cube::Cube(Shader *shader) 
{
    mesh = &m_Mesh;
    m_Mesh.verticies.data = (float *)m_Vertices;
    m_Mesh.verticies.size = sizeof(m_Vertices);
    m_Mesh.verticies.count = m_Mesh.verticies.size / (3*sizeof(float));
    this->shader = shader;
    OpenGLCreateMesh(&m_Mesh);
}

Cube::~Cube()
{
}