#ifndef CAMERA_H
#define CAMERA_H

#include <glm/glm.hpp>
#include <GL/glut.h>

class Camera {
public:
    glm::vec3 position;
    glm::vec3 direction; 
    glm::vec3 up;      

    glm::vec3 displacement;

    float azimuth;
    float altitude;

    float deltaAngle;
    float deltaAltitude;
    float deltaAzimuth;
    float deltaMove;
    float deltaMoveX;
    float deltaMoveY;

    float angle;   

    Camera();      

    void computePos();
    void computeDir();
    void render();
    void look();
};

#endif
