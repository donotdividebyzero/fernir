#include "shader.h"

#include "Thor/opengl/shader.h"

#include <cglm/cglm.h>

Shader CreateShader(const char *vertex, const char *fragment, Textures *textures)
{
    return OpenGLCreateShader(vertex, fragment, textures);
}

void SetUniformMat4(Shader *shader, const char*name, mat4 v)
{
    OpenGLSetUniformMat4(shader, name, v);
}

void SetUniform1i(Shader* shader, const char* name, int value)
{
    OpenGLSetUniform1i(shader, name, value);
}

void BindShader(Shader *shader)
{
    OpenGLBindShader(shader);
}

void UnbindShader(Shader *shader)
{
    OpenGLUnbindShader(shader);
}

void DeleteShader(Shader *shader)
{
    OpenGLDeleteShader(shader);
}