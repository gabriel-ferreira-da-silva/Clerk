#include "EMelements.h"
#include "Object.h"
#include "Camera.h"
#include "KeyboardHandler.h"
#include <cmath>    


float electrostatic_constant = 0.0001f;
float magnetostatic_constant = 0.005f;


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
    glutSolidSphere(.25,20,20);
    glPopMatrix();
}


void Particle::interact(const std::shared_ptr<Object>& obj)  {
    
    Particle* particle = dynamic_cast<Particle*>(obj.get());
    Current* current = dynamic_cast<Current*>(obj.get());
    
    this->resultant_force = glm::vec3(0.,0.,0.);
    if (particle) {
    
        glm::vec3 displacement = particle->position - this->position;
        float distance = glm::length(displacement);
        
        if (distance < 0.001f) {
            return;
        }

        float G = 1.0f;
        float force =  electrostatic_constant * (this->electric_charge * particle->electric_charge) / (distance * distance);
        
        glm::vec3 forceDirection = glm::normalize(displacement);
        
        this->resultant_force = forceDirection * force;
    }

    if (current) {
        for(int i=0; i < current->points.size()-1 ;i++ ){
            glm::vec3 wire = glm::vec3( current->points[i+1].x - current->points[i].x,
                                        current->points[i+1].y - current->points[i].y,
                                        current->points[i+1].z - current->points[i].z );

            glm::vec3 distance = glm::vec3( this->position.x - current->points[i].x,
                                            this->position.y - current->points[i].y,
                                            this->position.z - current->points[i].z );
            float dis = glm::length(distance);
            glm::vec3 magnetic_field = (magnetostatic_constant/ (dis*dis)) * (cross(distance,wire)) ;
            glm::vec3 magnetic_force = this->electric_charge * cross(magnetic_field,this->velocity);
            this->resultant_force += magnetic_force;
        }
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

 void Current::draw() const {
    glPushMatrix();
    glPointSize(10.f);
    glBegin( GL_LINES);
        for(int i=0; i < points.size()-1 ;i++ ){
            glVertex3f(points[i].x,points[i].y,points[i].z);
            glVertex3f(points[i+1].x,points[i+1].y,points[i+1].z);
        }
        
    glEnd();
    glPopMatrix();
 }

 void Current::addPoint(glm::vec3 point){
    points.push_back(point);
 }


Current::Current(){
    magnitude = 0.001f;
}
 void Current::update(){
    
 }


 void Current::interact(const std::shared_ptr<Object>& obj){
    
 }