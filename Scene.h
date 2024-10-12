#ifndef SCENE_H
#define SCENE_H
#include "Camera.h"
#include "KeyboardHandler.h"

class Scene {
    public:
        Scene();
        Camera cam;
        KeyboardHandler& keyboardHandler = KeyboardHandler::getInstance();
        void renderScene();
        void drawSnowMan();
        void changeSize(int w, int h);
        void init();
};

#endif 