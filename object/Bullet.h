#ifndef BULLET_H
#define BULLET_H
#include "Object.h"
#include "Camera.h"
#include "FpsGun.h"
#include <vector>
#include <memory>


class Bullet : public Object{
    public:

        Camera *cam;
        
        glm::vec3 position = glm::vec3(0.f,0.f,0.f);
        glm::vec3 velocity = glm::vec3(0.f,0.f,0.f);
        

        Bullet();
        void draw() const override;
        void update() override;
        void interact(const std::shared_ptr<Object>& obj){};

};

#endif 