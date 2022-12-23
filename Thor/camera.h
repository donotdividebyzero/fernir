#ifndef __THOR_CAMERA_H
#define __THOR_CAMERA_H

#include <cglm/cglm.h>
#include "Thor/window.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum {
    CAMERA_PERSPECTIVE,
    CAMERA_ORTOGRAPHIC,
    CAMERA_EDITOR
} CameraType;


void GetCameraViewProjection(mat4 dest);

void CameraCreate(Window *, CameraType, float);

void CameraDestroy();

void CameraUpdate(float);

#ifdef __cplusplus
}
#endif

#endif