#include "renderer.h"
#include "mesh.h"
#include "Thor/shader.h"

#include <glad/glad.h>

#include "Thor/camera.h"
#include "glcall.h"
#include <cglm/cglm.h>

#include "Thor/renderable.h"

void OpenGLDraw(Renderable *obj)
{
    struct GraphicData *data = obj->mesh->graphic_data;
    if (data == NULL) {
        return;
    }

    for(size_t i=0;i<obj->textures.count;i++) {
        if (obj->textures.data[i] != 0) {
            int textureUnit = GL_TEXTURE0+(obj->textures.data[i]-1);
            glCall(glActiveTexture(textureUnit));
            glCall(glBindTexture(GL_TEXTURE_2D, obj->textures.data[i]));
        }
    }
    
    glCall(glBindVertexArray(data->vao));
    if (obj->mesh->indicies.count > 0) {
        glCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, data->ibo));
    }

    glCall(glUseProgram(obj->shader->id));

    mat4 proj;
    GetCameraViewProjection(proj);
    SetUniformMat4(obj->shader, "proj", proj);
    SetUniformMat4(obj->shader, "model", obj->position);

    if (obj->mesh->indicies.count > 0) {
        glCall(glDrawElements(GL_TRIANGLES, obj->mesh->indicies.count, GL_UNSIGNED_INT, 0));
    } else {
        glCall(glDrawArrays(GL_TRIANGLES, 0, obj->mesh->verticies.count));
    }

    glCall(glBindVertexArray(0));
}

void OpenGLStartDraw()
{
    glCall(glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT));
}

void OpenGLEndDraw()
{
}
