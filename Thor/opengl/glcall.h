#ifndef __THOR__GLCALL_H
#define __THOR__GLCALL_H

#include <glad/glad.h>
#include "Thor/core.h"
#include <stdio.h>

static void glClearError()
{
    while (glGetError() != GL_NO_ERROR);
}

static int glCheckError(const char* function, const char* file, int line)
{
    GLenum error = GL_NO_ERROR;
    while ((error = glGetError()))
    {
        fprintf(stderr, "[OpenGl] (%d): %s, %s:%d\n", error, function, file, line);
        return 1;
    }

    return 0;
}

#define glCall(x) glClearError();\
    x;\
    ASSERT(!glCheckError(#x, __FILE__, __LINE__))


#define glCallRet(x, T) glClearError();\
    T res = x;\
    ASSERT(!glCheckError(#x, __FILE__, __LINE__));\
    return res

#endif 