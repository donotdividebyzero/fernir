#include "renderer.h"

#include "Thor/opengl/renderer.h"

#include "Thor/renderable.h"

void BeginDraw()
{
    OpenGLStartDraw();
}

void EndDraw()
{
    OpenGLEndDraw();
}

void Submit(Renderable *obj)
{
    OpenGLDraw(obj);
}