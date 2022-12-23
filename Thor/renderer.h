#ifndef __THOR__RENDERER_H
#define __THOR__RENDERER_H

#include <cglm/cglm.h>
#include "Thor/shader.h"
#include "Thor/texture.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    float x,y,z,w;
} Vec4;

typedef struct {
    float x,y,z;
} Vec3;

typedef struct {
    float x,y;
} Vec2;

typedef struct Vertex {
    Vec3 pos;
    Vec2 textCord;
} Vertex;

typedef unsigned int Index;

typedef struct {
    mat4 model;
} GeometryPosition;

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

    struct {
        mat4 *data;
        size_t count;
    } positions;

    Shader shader;
    Texture2d textures[2];
    mat4 model;
} Mesh;

void RenderCommand(Mesh *);

#ifdef __cplusplus
}
#endif
#endif