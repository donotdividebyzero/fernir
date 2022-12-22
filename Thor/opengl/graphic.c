#include <Thor/graphic.h>
#include "Thor/event.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "Thor/opengl/renderer.h"
#include "Thor/opengl/glcall.h"

#include <stdio.h>

void m_GraphicApiWindowResize(int width, int height)
{
    glViewport(0, 0, width, height);
}

void GraphicApiInitialize(Window *window)
{
    gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
    fprintf(stdout, "OpenGL version supported by this platform (%s): \n", glGetString(GL_VERSION));
    glViewport(0, 0, window->width, window->height);

    glCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER));
    glCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER));
    float borderColor[] = {1.0f, 1.0f, 1.0f, 1.0f};
    glCall(glTexParameterfv(GL_TEXTURE_2D, GL_TEXTURE_BORDER_COLOR, borderColor));

    glCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST));
    glCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR));

    EventRegisterWindowSetFrameBufferSizeCallback(m_GraphicApiWindowResize);
}

void GraphicApiDestroy(Window *window) 
{
    (void)window;
    OpenGLRendererDestruct();
}