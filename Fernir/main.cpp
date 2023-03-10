#include "Thor/entry.h"
#include "Thor/window.h"
#include "Thor/renderer.h"
#include "Thor/camera.h"
#include "Thor/event.h"

#include "game.h"

Game *game = nullptr;

Window WindowConfig()
{
    Window window;
    window.width = 1280;
    window.height = 720;
    window.vsync = 1;
    window.title = "Fernir";

    return window;
}

void GameKeyCallback(int key, int action, int modes) {
    (void)modes;
    if (action == GLFW_RELEASE) {
        game->KeyReleased(key);
    }
    if (action == GLFW_PRESS || action == GLFW_REPEAT) {
        game->KeyPressed(key);
    }
}

void CreateApplication(Window *window)
{
    game = new Game();
    CameraCreate(window, CAMERA_PERSPECTIVE, 2.5f);
    EventRegisterKeyCallback(GameKeyCallback);

}

void RenderApplication(Window *window, float ts)
{
    game->GameOnUpdate(ts);
}

void DestroyApplication()
{
    delete game;
}
