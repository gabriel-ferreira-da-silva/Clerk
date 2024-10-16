#include "FpsGun.h"
#include "Object.h"
#include "Camera.h"
#include "KeyboardHandler.h"
#include <cmath>    
#include <iostream>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <bits/stdc++.h>


FpsGun::FpsGun(){

}

void FpsGun::setCamera(Camera *cam){
    this->cam = cam;
    this->position = cam->position;
    this->displacement = cam->displacement;
    
}

void FpsGun::update(){
    if (this->cam) {
        this->position = this->cam->position;
        this->displacement = this->cam->displacement;
        glm::vec3 c= cross(this->displacement, cam->up);
        this->axis = cross(normalize(c),normalize(displacement));

        glm::mat4 rotationMatrix = glm::rotate(glm::mat4(1.0f), this->angle, glm::normalize(this->axis));
        glm::vec4 offset4 = rotationMatrix * glm::vec4(this->displacement, 1.0f);
        glm::vec3 offset = glm::vec3(offset4);

        this->position = this->position + offset*1.3f;
    }

    if(this->keyboardHandler){
        if(std::count(this->keyboardHandler->keys.begin(), this->keyboardHandler->keys.end(),'f' )> 0){
            Bullet *newBullet = new Bullet();
            newBullet->position = this->position;
            newBullet->velocity = glm::normalize(this->cam->displacement);
            this->bullets.push_back(newBullet);
            std::cout << "f is pressed\n";
        }else{
            std::cout << "f is not pressed\n";
        }
    }

    for(const auto& bullet: this->bullets){
        bullet->update();
    }
}

void FpsGun::draw() const {
    
    glPushMatrix();
    glColor3f(.3f, 0.f, 0.f);
    glTranslatef(this->position.x, this->position.y, this->position.z);
    glutSolidSphere(.25,20,20);
    glPopMatrix();

    for(const auto& bullet: this->bullets){
        bullet->draw();
    }
}
