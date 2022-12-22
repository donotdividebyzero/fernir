#include "shader.h"

#include "Thor/opengl/shader.h"

#include <cglm/cglm.h>

Shader CreateShader(const char *vertex, const char *fragment)
{
    return OpenGLCreateShader(vertex, fragment);
}

void SetUniformMat4(Shader *shader, const char*name, mat4 v)
{
    OpenGLSetUniformMat4(shader, name, v);
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