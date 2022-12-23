#include "texture.h"
#include <glad/glad.h>

#include "glcall.h"
#include "stb_image.h"


Texture2d OpenGLLoadTexture(const char* file_path) 
{
    Texture2d texture;
    glCall(glGenTextures(1, &texture));
    glCall(glBindTexture(GL_TEXTURE_2D, texture));
    
    glCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT));
    glCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT));

    glCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR));
    glCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR));

    int width, height, nrChannels;
    stbi_set_flip_vertically_on_load(1);
    unsigned char *data = stbi_load(file_path, &width, &height, &nrChannels, 0);
    if (data) {
        glCall(glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data));
        glCall(glGenerateMipmap(GL_TEXTURE_2D));
    }
    else
    {
        fprintf(stderr, "Can't load texture!\n");
        return 0;
    }

    stbi_image_free(data);
    glCall(glBindTexture(GL_TEXTURE_2D, 0));
    return texture;
}