#ifndef OBJECT_H
#define OBJECT_H
#include "Camera.h"
#include "KeyboardHandler.h"

class Object {
    public:
        Object(){};
        virtual void draw() const =0;
};

class Sphere : public Object{
    public:
        void draw() const override;
};

#endif 