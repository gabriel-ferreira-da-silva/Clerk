#include <vector>
#include <memory>
#include "Bullet.h"

Bullet::Bullet(){

}


void Bullet::draw() const {
    glPushMatrix();
    glColor3f(1.f, 0.f, 1.f);
    glTranslatef( this->position.x, this->position.y, this->position.z);
    glutSolidSphere(.25,20,20);
    glPopMatrix();
}

void Bullet::update(){
    this->position += this->velocity;
}