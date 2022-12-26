#ifndef __THOR_RENDERABLE_H
#define __THOR_RENDERABLE_H

#include "texture.h"
#include "shader.h"
#include "mesh.h"
#include <cglm/cglm.h>

#ifdef __cplusplus
    extern "C" {
#endif

struct Renderable
{
    struct {
        Texture2d *data;
        size_t count;
    } textures;
    Shader *shader;
    Mesh *mesh;
    mat4 position;
};

typedef struct Renderable Renderable;

#ifdef __cplusplus
    }
#endif

#endif