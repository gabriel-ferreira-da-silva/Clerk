#ifndef CAMERA_H
#define CAMERA_H

#include <glm/glm.hpp>
#include <GL/glut.h>

class Camera {
public:
    glm::vec3 position; 
    glm::vec3 direction; 
    glm::vec3 up;        

    float deltaAngle;
    float deltaMove;
    float angle;   

    Camera();      

    void computePos();
    void computeDir();
    void render();
    void look();
};

#endif
