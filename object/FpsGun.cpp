#include "FpsGun.h"
#include "Object.h"
#include "Camera.h"
#include "KeyboardHandler.h"
#include <cmath>    
#include <iostream>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>



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

        this->position = this->position + offset;
    }
}

void FpsGun::draw() const {
    
    glPushMatrix();
    glColor3f(.3f, 0.f, 0.f);
    glTranslatef(this->position.x, this->position.y, this->position.z);
    glutSolidSphere(.25,20,20);
    glPopMatrix();
}
