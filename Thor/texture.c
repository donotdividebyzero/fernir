#include "texture.h"

#include "Thor/opengl/texture.h"

Texture2d CreateTexture(const char* file_path)
{
    return OpenGLCreateTexture(file_path);
}