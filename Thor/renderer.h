#ifndef __THOR__RENDERER_H
#define __THOR__RENDERER_H

#include <cglm/cglm.h>
#include "Thor/shader.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    float x,y,z,w;
} Vec4;

typedef struct {
    float x,y,z;
} Vec3;

typedef struct Vertex {
    Vec3 pos;
    Vec4 color;
} Vertex;

typedef unsigned int Index;

typedef struct Mesh {
    unsigned long id;
    struct {
        Vertex *data;
        size_t size;
        size_t count;
    } verticies;
    struct {
        Index *data;
        size_t size;
        size_t count;
    } indicies;
    Shader shader;
    mat4 model;
} Mesh;

void RenderCommand(Mesh *);

#ifdef __cplusplus
}
#endif
#endif