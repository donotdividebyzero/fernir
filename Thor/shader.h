#ifndef __THOR_SHADER_H
#define __THOR_SHADER_H

#include <cglm/cglm.h>

#include "texture.h"

#ifdef __cplusplus
    extern "C" {
#endif

typedef struct {
    Texture2d* textures;
    size_t count;
} Textures;
typedef struct {
    unsigned int id;
} Shader;

Shader CreateShader(const char *, const char *, Textures *);

void SetUniformMat4(Shader *, const char*, mat4);
void SetUniformInt(Shader *, const char*, int);
void SetUniformVec3(Shader *, const char*, vec3);
void SetUniformFloat(Shader *, const char*, float);
void BindShader(Shader *);
void UnbindShader(Shader *);
void DeleteShader(Shader *);

#ifdef __cplusplus
    }
#endif

#endif