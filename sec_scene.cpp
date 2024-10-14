#include <stdlib.h>
#include <math.h>
#include "Scene.h"
#include "Camera.h"
#include "Object.h"
#include "EMelements.h"
#include "KeyboardHandler.h"
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif


Camera cam;

Scene scene;

Particle *pa = new Particle();
Current *ca = new Current();

int main(int argc, char **argv) {
	

	pa->position = glm::vec3(0.f,1.f, 0.f);

	pa->velocity = glm::vec3(0.f,0.01f,.0f);	
	
	ca->points.push_back(glm::vec3( 0.f, 0.f, 0.f));
	ca->points.push_back(glm::vec3( 0.f, 0.f, 2.f));
	ca->points.push_back(glm::vec3( 0.f, 0.f, 4.f));
	ca->points.push_back(glm::vec3( 0.f, 0.f, 6.f));
	ca->points.push_back(glm::vec3( 0.f, 0.f, 8.f));
	ca->points.push_back(glm::vec3( 0.f, 0.f, 10.f));
	ca->points.push_back(glm::vec3( 0.f, 0.f, 12.f));
	ca->points.push_back(glm::vec3( 0.f, 0.f, 14.f));
	ca->points.push_back(glm::vec3( 0.f, 0.f, 16.f));
	ca->points.push_back(glm::vec3( 0.f, 0.f, 18.f));
	ca->points.push_back(glm::vec3( 0.f, 0.f, 20.f));
	ca->points.push_back(glm::vec3( 0.f, 0.f, 22.f));

	scene.pushObject(pa);
	scene.pushObject(ca);

	glutInit(&argc, argv);
	scene.init();

    glutIgnoreKeyRepeat(1);

	glEnable(GL_DEPTH_TEST);

	glutMainLoop();
	return 1;
}