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
    glCall(glEnable(GL_DEPTH_TEST));

    EventRegisterWindowSetFrameBufferSizeCallback(m_GraphicApiWindowResize);
}

void GraphicApiDestroy(Window *window) 
{
    (void)window;
    OpenGLRendererDestruct();
}