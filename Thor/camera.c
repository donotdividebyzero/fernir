#include "camera.h"
#include "timer.h"
#include "event.h"
#include <glfw/glfw3.h>
typedef struct {
    Window *window;
    vec3 position;
    vec3 front;
    vec3 up;
    float fov;
    mat4 proj;
    mat4 view;
    CameraType type;
    float speed;
    void (*calculateProjection)();
} Camera;

typedef struct {
    int isInitiated;
    double lastY;
    double lastX;
    double yaw;
    double pitch;
} MousePosition;

Camera camera;
MousePosition mousePosition;
int m_KeyPressed[GLFW_KEY_LAST];

void m_CalculatePerspective()
{
    Window *window = camera.window;
    glm_perspective(glm_rad(camera.fov), window->width/window->height, 0.1f, 100.0f, camera.proj);
}

void m_CalculateOrthographic()
{
    Window *window = camera.window;
    glm_ortho(0, (float)window->width, 0, (float)window->height, 0.1f, 100.0f, camera.proj);
}

void m_CameraMousePosCallback(double xpos, double ypos)
{
    if (mousePosition.isInitiated)
    {
        mousePosition.lastX = xpos;
        mousePosition.lastY = ypos;
        mousePosition.isInitiated = 0;
    }
  
    float xoffset = xpos - mousePosition.lastX;
    float yoffset = mousePosition.lastY - ypos; 
    mousePosition.lastX = xpos;
    mousePosition.lastY = ypos;

    float sensitivity = 0.1f;
    xoffset *= sensitivity;
    yoffset *= sensitivity;

    mousePosition.yaw   += xoffset;
    mousePosition.pitch += yoffset;

    if(mousePosition.pitch > 89.0f)
        mousePosition.pitch = 89.0f;
    if(mousePosition.pitch < -89.0f)
        mousePosition.pitch = -89.0f;

    vec3 direction;
    direction[0] = cos(glm_rad(mousePosition.yaw)) * cos(glm_rad(mousePosition.pitch));
    direction[1] = sin(glm_rad(mousePosition.pitch));
    direction[2] = sin(glm_rad(mousePosition.yaw)) * cos(glm_rad(mousePosition.pitch));
    glm_normalize(direction);
    glm_vec3_copy(direction, camera.front);
}

void m_CameraKeyCallback(int key, int action, int modes)
{
    if (action == GLFW_PRESS || action == GLFW_REPEAT) {
        m_KeyPressed[key] = 1;
    }
    if (action == GLFW_RELEASE) {
        m_KeyPressed[key] = 0;
    }
}

void m_CameraMouseScrollCallback(double xoffset, double yoffset)
{
   camera.fov -= (float)yoffset;
    if (camera.fov < 1.0f) {
        camera.fov = 1.0f;
    }

    if (camera.fov > 100.0f) {
        camera.fov = 100.0f; 
    }
}

void GetCameraViewProjection(mat4 dest)
{
    glm_mul(camera.proj, camera.view, dest);
}

void GetCameraPosition(vec3 dest)
{
    glm_vec3_copy(camera.position, dest);
}

void CameraCreate(Window *window, CameraType type, const float cameraSpeed) 
{
    mousePosition.isInitiated = 1;
    mousePosition.lastX = window->width/2;
    mousePosition.lastY = window->height/2;
    camera.window = window;
    camera.type = type;
    camera.fov = 45.0f;
    camera.speed = cameraSpeed;
    glm_vec3_copy((vec3){0.0f, 0.0f,  3.0f}, camera.position);
    glm_vec3_copy((vec3){0.0f, 0.0f, -1.0f}, camera.front);
    glm_vec3_copy((vec3){0.0f, 1.0f,  0.0f}, camera.up);
    
    if (type == CAMERA_ORTOGRAPHIC) {
        camera.calculateProjection = m_CalculateOrthographic; 
    }

    if (type == CAMERA_PERSPECTIVE) {
        camera.calculateProjection = m_CalculatePerspective;
    }

    EventRegisterKeyCallback(m_CameraKeyCallback);
    EventRegisterMouseScrollCallback(m_CameraMouseScrollCallback);
    EventRegisterMousePosCallback(m_CameraMousePosCallback);
}

void CameraUpdate(float ts)
{
    camera.calculateProjection();
    vec3 temp;
    camera.speed = 6.0f * ts;
    if (m_KeyPressed[GLFW_KEY_W]) {
        glm_vec3_scale(camera.front, camera.speed, temp);
        glm_vec3_add(camera.position, temp, camera.position);
    }
    if (m_KeyPressed[GLFW_KEY_S]) {
        glm_vec3_scale(camera.front, camera.speed, temp);
        glm_vec3_sub(camera.position, temp, camera.position);
    }
    if (m_KeyPressed[GLFW_KEY_A]) {
        glm_cross(camera.front, camera.up, temp);
        glm_normalize(temp);
        glm_vec3_scale(temp, camera.speed, temp);       
        glm_vec3_sub(camera.position, temp, camera.position);
    }
    if (m_KeyPressed[GLFW_KEY_D]) {
        glm_cross(camera.front, camera.up, temp);
        glm_normalize(temp);
        glm_vec3_scale(temp, camera.speed, temp);
        glm_vec3_add(camera.position, temp, camera.position);
    }

    vec3 camPosFront;
    glm_vec3_add(camera.position, camera.front, camPosFront);
    glm_lookat(
        camera.position, 
        camPosFront, 
        camera.up, 
        camera.view
    );
}

void CameraDestroy()
{

}
