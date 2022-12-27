#include "Thor/shader.h"

Shader OpenGLCreateShader(const char *, const char *, Textures *);

void OpenGLSetUniformMat4(Shader *, const char*, mat4);
void OpenGLSetUniformInt(Shader *, const char*, int);
void OpenGLSetUniformVec3(Shader *, const char*, vec3);
void OpenGLSetUniformFloat(Shader *, const char*, float);

void OpenGLBindShader(Shader *);

void OpenGLUnbindShader(Shader *);

void OpenGLDeleteShader(Shader *);