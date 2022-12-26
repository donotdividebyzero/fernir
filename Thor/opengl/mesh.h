#ifndef __THOR_OPENGL_MESH_H
#define __THOR_OPENGL_MESH_H

#include "Thor/mesh.h"

#ifdef __cplusplus
extern "C" {
#endif

struct GraphicData {
    unsigned int vao, ibo, vbo;     
};

void OpenGLCreateMesh(Mesh *);
#ifdef __cplusplus
}
#endif
#endif