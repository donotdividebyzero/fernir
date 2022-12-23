#include "texture.h"

#include "Thor/opengl/texture.h"

Texture2d LoadTexture(const char* file_path)
{
    return OpenGLLoadTexture(file_path);
}