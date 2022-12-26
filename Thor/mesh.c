#include "mesh.h"

#include <stdio.h>

Mesh CreateMeshFromFile(const char* file_path)
{
    FILE* objFile = fopen(file_path, "rb");
    if (!objFile) {
        fprintf(stderr, "Can't load mesh object: %s\n", file_path);
        return (Mesh){0};
    }
}