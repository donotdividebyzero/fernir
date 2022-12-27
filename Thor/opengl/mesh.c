#include "mesh.h"
#include <glad/glad.h>
#include "glcall.h"

static struct GraphicData meshes[500];

void OpenGLCreateMesh(Mesh *obj)
{
    GLuint vao, ibo, vbo;
    glCall(glGenVertexArrays(1, &vao));
    glCall(glBindVertexArray(vao));

    glCall(glGenBuffers(1, &vbo));
    glCall(glBindBuffer(GL_ARRAY_BUFFER, vbo));
    glCall(glBufferData(GL_ARRAY_BUFFER, obj->verticies.size, obj->verticies.data, GL_STATIC_DRAW));

    if (obj->indicies.count > 0) {
        glCall(glGenBuffers(1, &ibo));
        glCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo));
        glCall(glBufferData(GL_ELEMENT_ARRAY_BUFFER, obj->indicies.size, obj->indicies.data, GL_STATIC_DRAW));
        glCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0));
    } else {
        ibo = 0;
    }
    
    size_t size_of_vertex = obj->verticies.size/obj->verticies.count;
    /**
     * @TODO: Create buffer layout class
     */
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, size_of_vertex, (void*)0);

    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, size_of_vertex, (void*)(3 * sizeof(float)));
    
    glEnableVertexAttribArray(2);
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, size_of_vertex, (void*)(6 * sizeof(float)));

    glCall(glBindBuffer(GL_ARRAY_BUFFER, 0));
    glCall(glBindVertexArray(0));

    struct GraphicData *data = &meshes[vao];
    data->vao = vao;
    data->ibo = ibo;
    data->vbo = vbo;
    obj->graphic_data = data;
}