#include "Object.h"
#include "Camera.h"
#include "KeyboardHandler.h"


void Sphere::draw() const {
    glPushMatrix();
    glColor3f(1.f, 1.f, 1.f);
    glTranslatef( 0., 10., 10.0);
    glutSolidSphere(0.75f,20,20);
    glPopMatrix();
}
