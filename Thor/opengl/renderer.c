#include "Thor/renderer.h"
#include "renderer.h"

#include <glad/glad.h>

#include "Thor/camera.h"

#include "glcall.h"

#include <cglm/cglm.h>

typedef struct {
    GLuint vao, ibo, vbo;
    GLuint shader;
} VertexArray;

#define MAX_VAO_ARRAYS 5000

VertexArray vaos[MAX_VAO_ARRAYS];

void OpenGLRendererDestruct()
{
    for(size_t i=0; i<MAX_VAO_ARRAYS;i++)
    {
        VertexArray *va = &vaos[i];
        if (va->vao) {
            glCall(glDeleteVertexArrays(1, &va->vao));
            glCall(glDeleteBuffers(1, &va->vbo));
        }
    }
}

void OpenGLRenderCommand(Mesh *mesh)
{
    if (!mesh->id) {
        GLuint vao, ibo, vbo;
        glCall(glGenVertexArrays(1, &vao));
        glCall(glBindVertexArray(vao));

        glCall(glGenBuffers(1, &vbo));
        glCall(glBindBuffer(GL_ARRAY_BUFFER, vbo));
        glCall(glBufferData(GL_ARRAY_BUFFER, mesh->verticies.size, mesh->verticies.data, GL_STATIC_DRAW));

        glCall(glGenBuffers(1, &ibo));
        glCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo));
        glCall(glBufferData(GL_ELEMENT_ARRAY_BUFFER, mesh->indicies.size, mesh->indicies.data, GL_STATIC_DRAW));

        glEnableVertexAttribArray(0);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)0);

        glEnableVertexAttribArray(1);
        glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)(3*sizeof(float)));

        mesh->id = vao;
        vaos[mesh->id] = (VertexArray){vao, ibo, vbo, mesh->shader.id};
        glCall(glBindBuffer(GL_ARRAY_BUFFER, 0));
        glCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0));
        glCall(glBindVertexArray(0));
    }

    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glCall(glClear(GL_COLOR_BUFFER_BIT));
    VertexArray *va = &vaos[mesh->id];
    glCall(glBindVertexArray(va->vao));
    glCall(glBindBuffer(GL_ARRAY_BUFFER, va->vbo));
    glCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, va->ibo));
    glCall(glUseProgram(va->shader));

    mat4 proj;
    GetCameraViewProjection(proj);
    int uniform_location = glGetUniformLocation(va->shader, "proj");
    glCall(glUniformMatrix4fv(uniform_location, 1, GL_FALSE, &proj));

    // mat4 view;
    // glm_mat4_identity(view);
    // glm_translate(view, (vec3){0.0, 0.0, -3.0f});
    // int view_loc = glGetUniformLocation(va->shader, "view");
    // glCall(glUniformMatrix4fv(view_loc, 1, GL_FALSE, &view));

    mat4 model;
    glm_mat4_identity(model);
    glm_rotate(model, glm_rad(-55.0f), (vec3){1.0f, 0.0f, 0.0f});
    int model_loc = glGetUniformLocation(va->shader, "model");
    glCall(glUniformMatrix4fv(model_loc, 1, GL_FALSE, &model));
    
    glCall(glDrawElements(GL_TRIANGLES, mesh->indicies.count, GL_UNSIGNED_INT, 0));
    glCall(glBindVertexArray(0));
}