#include "Thor/shader.h"

Shader OpenGLCreateShader(const char *, const char *);

void OpenGLSetUniformMat4(Shader *, const char*, mat4);

void OpenGLBindShader(Shader *);

void OpenGLUnbindShader(Shader *);

void OpenGLDeleteShader(Shader *);