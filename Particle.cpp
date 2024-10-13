#include "Particle.h"
#include "Object.h"
#include "Camera.h"
#include "KeyboardHandler.h"
#include <cmath>    


float electrostatic_constant = 0.0001f;


Particle::Particle(){
    mass = 1.;
    electric_charge = 1.;

    position = glm::vec3(0.0f, 0.0f, 0.0f);   
    velocity = glm::vec3(0.0f, 0.0f, 0.0f);   
    acceleration = glm::vec3(0.0f, 0.0f, 0.0f);   
}

void Particle::draw() const{
    glPushMatrix();
    glColor3f(1.f, electric_charge, 1.f);
    glTranslatef( position.x, position.y, position.z);
    glutSolidSphere(mass,20,20);
    glPopMatrix();
}


void Particle::interact(const std::shared_ptr<Object>& obj)  {
    
    Particle* other = dynamic_cast<Particle*>(obj.get());
    
    if (other) {
    
        glm::vec3 displacement = other->position - this->position;
        float distance = glm::length(displacement);
        
        if (distance < 0.001f) {
            return;
        }

        float G = 1.0f;
        float force =  electrostatic_constant * (this->electric_charge * other->electric_charge) / (distance * distance);
        
        glm::vec3 forceDirection = glm::normalize(displacement);
        
        this->resultant_force = forceDirection * force;
    }
}

void Particle::calc_acceleration(){
    this->acceleration = this->resultant_force / this->mass;
}

void Particle::calc_velocity(){
    this->velocity += this->acceleration;
}

void Particle::calc_position(){
    this->position += this->velocity;
}

void Particle::update(){
    this->calc_acceleration();
    this->calc_velocity();
    this->calc_position();
}
