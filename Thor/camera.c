#include "camera.h"

typedef struct {
    mat4 proj;
    mat4 view;
    CameraType type;
} Camera;

Camera camera;

void GetCameraViewProjection(mat4 dest)
{
    glm_mul(camera.proj, camera.view, dest);
    // glm_mat4_copy(camera.proj, dest);
}

void CameraCreate(Window *window, CameraType type) 
{
    camera.type = type;
    glm_mat4_identity(camera.view);
    glm_translate(camera.view, (vec3){0.0f, 0.0f, -5.0f});
    if (type == CAMERA_ORTOGRAPHIC) {
        glm_ortho(0, (float)window->width, 0, (float)window->height, 0.1f, 100.0f, camera.proj); 
    }

    if (type == CAMERA_PERSPECTIVE) {
        glm_perspective(glm_rad(45.0f), window->width/window->height, 0.1f, 100.0f, camera.proj);
    }
}

void CameraUpdate(float ts)
{
    (void)ts;
}

void CameraDestroy()
{

}
