#include "Camera.h"
#include <glm/gtc/matrix_transform.hpp>
#include <math.h>

#define PI 3.141593

Camera::Camera() {
    position = glm::vec3(0.0f, 0.0f, 0.0f);   
    direction = glm::vec3(0.0f, 1.0f, 0.0f);  
    up = glm::vec3(0.0f, 0.0f, 1.0f);          
    
    displacement = glm::vec3(0.0f, sin(PI/2)*sin(PI/2), 0.0f); 
    
    deltaAngle = 0.0f;
    deltaMove = 0.0f;
    deltaMoveX = 0.0f;
    deltaMoveY = 0.0f;

    azimuth= PI/2;
    altitude= PI/2;

    deltaAzimuth=0.0f;
    deltaAltitude=0.0f;
    
    angle = 0.0f;

}

void Camera::computePos() {
    position += displacement * deltaMoveX*0.1f;
    position += normalize(cross(displacement,up)) * deltaMoveY * 0.1f;
}


void Camera::computeDir() {
    azimuth += deltaAzimuth;
    altitude += deltaAltitude;

    displacement.x = cos(azimuth)* sin(altitude);
    displacement.y = sin(azimuth)* sin(altitude);
    displacement.z = cos(altitude);
}

void Camera::render() {
    if (deltaAzimuth or deltaAltitude)
        computeDir();
    if (deltaMoveX or deltaMoveY)
        computePos();
    
    direction = position + displacement;
}

void Camera::look() {
    render();
    
    gluLookAt(
        position.x, position.y, position.z,
        direction.x,direction.y,direction.z,
        up.x, up.y, up.z
    );
}
