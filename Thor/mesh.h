#ifndef __THOR_MESH_H
#define __THOR_MESH_H

#include <stdlib.h>

struct GraphicData;

typedef struct {
    struct GraphicData *graphic_data;
    struct {
        float *data;
        size_t size;
        size_t count;
    } verticies;
    struct {
        unsigned int *data;
        size_t size;
        size_t count;
    } indicies;
} Mesh;

Mesh CreateMeshFromFile(const char*);

#endif