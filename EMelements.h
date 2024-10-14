#ifndef EMELEMENTS_H
#define EMELEMENTS_H
#include "Object.h"
#include "Camera.h"
#include "KeyboardHandler.h"
#include <vector>
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

class Current : public Object{
    public:
        float magnitude;
        float magnetostatic_constant;
        std::vector<glm::vec3> points;
        
        Current();
        void draw() const override;
        void update() override;
        void interact(const std::shared_ptr<Object>& obj)  override;
        void addPoint(glm::vec3 point);

};

#endif 