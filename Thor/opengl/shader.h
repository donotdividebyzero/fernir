#include "Thor/shader.h"

Shader OpenGLCreateShader(const char *, const char *, Textures *);

void OpenGLSetUniformMat4(Shader *, const char*, mat4);
void OpenGLSetUniform1i(Shader *, const char*, int);

void OpenGLBindShader(Shader *);

void OpenGLUnbindShader(Shader *);

void OpenGLDeleteShader(Shader *);