#ifndef PARTICLE_H
#define PARTICLE_H
#include "Object.h"
#include "Camera.h"
#include "KeyboardHandler.h"
#include <memory>

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
        void update() override;
        void interact(const std::shared_ptr<Object>& obj)  override;
        void calc_position();
        void calc_velocity();
        void calc_acceleration();

};

class Current : public Particle{
    public:
        void draw() const override;

};

#endif 