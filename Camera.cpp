#include "Camera.h"
#include <glm/gtc/matrix_transform.hpp>
#include <math.h>

Camera::Camera() {
    position = glm::vec3(0.0f, 0.0f, 0.0f);    // Start 5 units back along z-axis
    direction = glm::vec3(0.0f, 1.0f, 0.0f);  // Looking down the negative z-axis
    up = glm::vec3(0.0f, 0.0f, 1.0f);          // Up vector is along the y-axis
    deltaAngle = 0.0f;
    deltaMove = 0.0f;
    angle = 0.0f;
}

void Camera::computePos() {
    position += deltaMove * direction * 0.1f;
}

void Camera::computeDir() {
    angle += deltaAngle;
    direction.x = sin(angle);
    direction.y = cos(angle);
}

void Camera::render() {
    if (deltaMove)
        computePos();
    if (deltaAngle)
        computeDir();
}

void Camera::look() {
    render();
    gluLookAt(
        position.x, position.y, position.z,
        position.x + direction.x, position.y + direction.y, position.z + direction.z,
        up.x, up.y, up.z
    );
}
