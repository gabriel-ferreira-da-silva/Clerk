#ifndef SCENE_H
#define SCENE_H
#include "Camera.h"
#include "Object.h"
#include "KeyboardHandler.h"

#include <vector>
#include <memory>


class Scene {
    public:
        Scene();
        Camera cam;
        KeyboardHandler& keyboardHandler = KeyboardHandler::getInstance();

        std::vector<std::unique_ptr<Object>> objects;

        void renderScene();
        void drawSnowMan();
        void changeSize(int w, int h);
        void init();
        void renderObjects();
        void pushObject(Object *obj);
};

#endif 