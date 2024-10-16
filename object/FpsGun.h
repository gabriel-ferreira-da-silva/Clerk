#ifndef FPS_GUN_H
#define FPS_GUN_H
#include "Object.h"
#include "Camera.h"
#include "Bullet.h"
#include <vector>
#include <memory>

class Bullet;

class FpsGun : public Object{
    public:

        Camera *cam;
        KeyboardHandler *keyboardHandler;

        glm::vec3 position = glm::vec3(0.f,0.f,0.f);
        glm::vec3 displacement = glm::vec3(0.f,0.f,0.f);
        glm::vec3 axis = glm::vec3(0.f,0.f,0.f);
        float angle= 3.14/10;
        std::vector<Bullet*> bullets;

        FpsGun();
        void setCamera(Camera *cam);
        void draw() const override;
        void update() override;
        void interact(const std::shared_ptr<Object>& obj){};

};

#endif 