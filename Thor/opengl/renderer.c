#include "Thor/renderer.h"
#include "renderer.h"

#include <glad/glad.h>

#include "Thor/camera.h"

#include "glcall.h"

#include <cglm/cglm.h>

typedef struct {
    GLuint vao, ibo, vbo;
    GLuint shader;
    GLuint textId;
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

        if (mesh->indicies.count > 0) {
            glCall(glGenBuffers(1, &ibo));
            glCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo));
            glCall(glBufferData(GL_ELEMENT_ARRAY_BUFFER, mesh->indicies.size, mesh->indicies.data, GL_STATIC_DRAW));
            glCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0));
        } else {
            ibo = 0;
        }
     
        glEnableVertexAttribArray(0);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)0);

        glEnableVertexAttribArray(1);
        glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)(3*sizeof(float)));

        mesh->id = vao;
        vaos[mesh->id] = (VertexArray){vao, ibo, vbo, mesh->shader.id};
        glCall(glBindBuffer(GL_ARRAY_BUFFER, 0));
        glCall(glBindVertexArray(0));
    }

    glCall(glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT));
    VertexArray *va = &vaos[mesh->id];
    for(size_t i=0;i<2;i++) {
        if (mesh->textures[i] != 0) {
            int textureUnit = GL_TEXTURE0+(mesh->textures[i]-1);
            glCall(glActiveTexture(textureUnit));
            glCall(glBindTexture(GL_TEXTURE_2D, mesh->textures[i]));
        }
    }
    
    glCall(glBindVertexArray(va->vao));
    glCall(glBindBuffer(GL_ARRAY_BUFFER, va->vbo));
    if (va->ibo > 0) {
        glCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, va->ibo));
    }

    glCall(glUseProgram(va->shader));

    mat4 proj;
    GetCameraViewProjection(proj);
    int uniform_location = glGetUniformLocation(va->shader, "proj");
    glCall(glUniformMatrix4fv(uniform_location, 1, GL_FALSE, &proj));

    for(size_t i=0; i < mesh->positions.count; i++) {
        int model_loc = glGetUniformLocation(va->shader, "model");
        glCall(glUniformMatrix4fv(model_loc, 1, GL_FALSE, &mesh->positions.data[i]));
        
        if (va->ibo > 0) {
            glCall(glDrawElements(GL_TRIANGLES, mesh->indicies.count, GL_UNSIGNED_INT, 0));
        } else {
            glCall(glDrawArrays(GL_TRIANGLES, 0, mesh->verticies.count));
        }
    }

    glCall(glBindVertexArray(0));
}