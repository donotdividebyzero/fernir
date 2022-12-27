#include "game.h"
#include "Thor/renderer.h"
#include "Thor/shader.h"

#include <GLFW/glfw3.h>

Game::Game()
{
    m_LightShader = CreateShader(
        "Fernir/shader/vertex/simple.glsl",
        "Fernir/shader/fragment/light.glsl",
        nullptr
    );
    
    m_CubeShader = CreateShader(
        "Fernir/shader/vertex/simple.glsl",
        "Fernir/shader/fragment/shaded.glsl",
        nullptr
    );

    m_Light = new Cube(&m_LightShader);
    mat4 lightPosition;
    glm_mat4_identity(lightPosition);
    glm_vec3_copy((vec3){1.2f, 1.0f, 2.0f}, m_LightPosition);
    glm_translate(lightPosition, m_LightPosition);
    glm_mat4_scale(lightPosition, 0.2f);
    glm_mat4_copy(lightPosition, m_Light->position);

    m_Cube = new Cube(&m_CubeShader);
    mat4 cubePosition;
    glm_mat4_identity(cubePosition);
    glm_mat4_copy(cubePosition, m_Cube->position);
    BindShader(&m_CubeShader);
    SetUniformVec3(&m_CubeShader, "lightPos", m_LightPosition);
    SetUniformVec3(&m_CubeShader, "objectColor", (vec3){1.0f, 0.5f, 0.31f});
    SetUniformVec3(&m_CubeShader, "lightColor", (vec3){1.0f, 1.0f, 1.0f});

    SetUniformVec3(&m_CubeShader, "light.ambient",  (vec3){0.2f, 0.2f, 0.2f});
    SetUniformVec3(&m_CubeShader, "light.diffuse",  (vec3){0.5f, 0.5f, 0.5f});
    SetUniformVec3(&m_CubeShader, "light.specular", (vec3){1.0f, 1.0f, 1.0f});

    SetUniformVec3(&m_CubeShader, "material.ambient", (vec3){1.0f, 0.5f, 0.31f});
    SetUniformVec3(&m_CubeShader, "material.diffuse", (vec3){1.0f, 0.5f, 0.31f});
    SetUniformVec3(&m_CubeShader, "material.specular", (vec3){0.5f, 0.5f, 0.5f});
    SetUniformFloat(&m_CubeShader, "material.shininess", 32.0f);
    UnbindShader(&m_CubeShader);
}

Game::~Game()
{
    delete m_Cube;
    delete m_Light;
}

void Game::GameOnUpdate(float ts)
{
    mat4 lightPosition;
    glm_mat4_identity(lightPosition);
    glm_vec3_copy((vec3){1.2f, 1.0f, 2.0f}, m_LightPosition);
    m_LightPosition[0] = 1.0f + sin(glfwGetTime()) * 2.0f;
    m_LightPosition[1] = sin(glfwGetTime() / 2.0f) * 1.0f;
    glm_translate(lightPosition, m_LightPosition);
    glm_mat4_scale(lightPosition, 0.2f);
    glm_mat4_copy(lightPosition, m_Light->position);

    BindShader(&m_CubeShader);
    SetUniformVec3(&m_CubeShader, "lightPos", m_LightPosition);

    Submit(m_Light);
    Submit(m_Cube);
}

void Game::KeyPressed(int key)
{
    m_PressedKeys[key] = 1;
}

void Game::KeyReleased(int key)
{
    m_PressedKeys[key] = 0;
}
