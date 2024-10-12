#ifndef PARTICLE_H
#define PARTICLE_H
#include "Object.h"
#include "Camera.h"
#include "KeyboardHandler.h"

float electrostatic_constant = 0.0001f;

class Particle : public Object{
    public:
        float mass;
        float electric_charge;
        glm::vec3 position;
        glm::vec3 velocity;
        glm::vec3 acceleration;
        glm::vec3 resultant_force;
        Particle();
        void draw() const override;
        void interact(Object *obj);
        
        void calc_position();
        void calc_velocity();
        void calc_acceleration();

};

#endif 