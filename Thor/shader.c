#include "shader.h"

#include "Thor/opengl/shader.h"

#include <cglm/cglm.h>

Shader CreateShader(const char *vertex, const char *fragment, Textures *textures)
{
    return OpenGLCreateShader(vertex, fragment, textures);
}

void SetUniformMat4(Shader *shader, const char* name, mat4 v)
{
    OpenGLSetUniformMat4(shader, name, v);
}

void SetUniformInt(Shader* shader, const char* name, int value)
{
    OpenGLSetUniformInt(shader, name, value);
}

void SetUniformVec3(Shader* shader, const char* name, vec3 value)
{
    OpenGLSetUniformVec3(shader, name, value);
}

void SetUniformFloat(Shader* shader, const char* name, float v)
{
    OpenGLSetUniformFloat(shader, name, v);
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