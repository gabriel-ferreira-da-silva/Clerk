#ifndef OBJECT_H
#define OBJECT_H
#include "Camera.h"
#include "KeyboardHandler.h"
#include <memory>

class Object {
    public:
        Object(){};
        virtual ~Object();
        virtual void draw() const =0;
        virtual void update();
        virtual void interact(const std::shared_ptr<Object>& other) = 0;
};


#endif 