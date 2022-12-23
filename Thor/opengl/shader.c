#include <Thor/shader.h>
#include "shader.h"
#include "glcall.h"

#include <glad/glad.h>
#include <assert.h>
#include <stdlib.h>

unsigned int m_OpenGLCompileShader(const char* file_name, unsigned int type)
{
    FILE *stream = fopen(file_name, "r");
    if (!stream) {
        fprintf(stderr, "Can't open shader source code file `%s`\n", file_name);
        exit(EXIT_FAILURE);
    }

    fseek(stream, 0, SEEK_END);
    size_t file_size = ftell(stream);
    fseek(stream, 0, SEEK_SET);

    char* shader_content = malloc(file_size + 1);
    assert(fread(shader_content, 1, file_size, stream) == file_size);
    fclose(stream);
    unsigned int shader = glCreateShader(type);
    glCall(glShaderSource(shader, 1, (const GLchar *const*)&shader_content, (const GLint*)&file_size));
    glCall(glCompileShader(shader));


    int result;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &result);

    if (result == GL_FALSE) {
        int length;
        glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &length);
        char* message = (char*)alloca(length * sizeof(char));
        glGetShaderInfoLog(shader, length, &length, message);
        fprintf(stderr, "Failed to compile shader %s\n", message);
        glDeleteShader(shader);

        return 0;
    }

    return shader;
}

Shader OpenGLCreateShader(const char *vertex, const char *fragment, Textures *textures)
{
    unsigned int vertex_shader = m_OpenGLCompileShader(vertex, GL_VERTEX_SHADER);
    unsigned int fragment_shader = m_OpenGLCompileShader(fragment, GL_FRAGMENT_SHADER);
 
    unsigned int program = glCreateProgram();
    glCall(glAttachShader(program, vertex_shader));
    glCall(glAttachShader(program, fragment_shader));
    glCall(glLinkProgram(program));

    int success;
    glGetProgramiv(program, GL_LINK_STATUS, &success);
    if (!success) {
        GLchar infoLog[1024];
        glGetProgramInfoLog(program, 1024, NULL, infoLog);
        fprintf(stderr, "[OpenGl]: %s\n", infoLog);
    }
    
    Shader shader = (Shader){program};

    for(size_t i=0; i < textures->count;i++) {
        char* textureName = alloca(sizeof(char)*10);
        sprintf(textureName, "m_Texture%zu", i);
        OpenGLSetUniform1i(&shader, textureName, i);
    }

    return shader;
}

int m_OpenGLGetShaderUniformLocation(Shader *shader, const char *uniform_name)
{
    /**
     * @TODO: figure out how to cache uniform locations 
     * 
     */
    // for(int i = 0; i<sizeof(shader->UniformLocations); i++) {
    //     if (strcmp(uniform_name, shader->UniformLocation[i]) == 0)) {
    //         return i;
    //     }
    // }
    // int uniformLocation = glGetUniformLocation(shader->Id, uniform_name);
    // shader->UniformLocation[uniformLocation] = uniform_name;
    glCallRet(glGetUniformLocation(shader->id, uniform_name), int);
}

void OpenGLSetUniformMat4(Shader *shader, const char*uniform, mat4 value) 
{
    OpenGLBindShader(shader);
    int uniform_location = m_OpenGLGetShaderUniformLocation(shader, uniform);
    glCall(glUniformMatrix4fv(uniform_location, 1, GL_FALSE, &value[0][0]));
}

void OpenGLSetUniform1i(Shader *shader, const char* uniform, int value)
{
    OpenGLBindShader(shader);
    int uniform_location = m_OpenGLGetShaderUniformLocation(shader, uniform);
    glCall(glUniform1i(uniform_location, value));
}

void OpenGLBindShader(Shader *shader)
{
    glCall(glUseProgram(shader->id));
}

void OpenGLUnbindShader(Shader *shader)
{
    (void)shader;
    glCall(glUseProgram(0));
}

void OpenGLDeleteShader(Shader *shader)
{
    (void)shader;
}