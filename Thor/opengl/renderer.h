#ifndef __THOR_OPENGL_RENDERER_H
#define __THOR_OPENGL_RENDERER_H
#include "renderer.h"
#include "Thor/renderable.h"

void OpenGLDraw(Renderable *);

void OpenGLStartDraw();

void OpenGLEndDraw();

#endif