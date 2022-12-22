#ifndef __THOR_SHADER_H
#define __THOR_SHADER_H

#include <cglm/cglm.h>

#ifdef __cplusplus
    extern "C" {
#endif

typedef struct {
    unsigned int id;
} Shader;

Shader CreateShader(const char *, const char *);
void SetUniformMat4(Shader *, const char*, mat4);
void BindShader(Shader *);
void UnbindShader(Shader *);
void DeleteShader(Shader *);

#ifdef __cplusplus
    }
#endif

#endif