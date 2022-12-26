#ifndef __THOR__RENDERER_H
#define __THOR__RENDERER_H

#ifdef __cplusplus
extern "C" {
#endif

#include "renderable.h"

void BeginDraw();
void EndDraw();

void Submit(Renderable *);

#ifdef __cplusplus
}
#endif

#endif