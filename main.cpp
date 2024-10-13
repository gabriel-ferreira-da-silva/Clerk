#include <stdlib.h>
#include <math.h>
#include "Scene.h"
#include "Camera.h"
#include "Object.h"
#include "Particle.h"
#include "KeyboardHandler.h"
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif


Camera cam;

Scene scene;

Particle *pa = new Particle();
Particle *pb = new Particle();
Particle *pc = new Particle();
Particle *pd = new Particle();
Particle *ca = new Current();

int main(int argc, char **argv) {
	

	pa->position = glm::vec3(10.f,13.f,10.f);
	pb->position = glm::vec3(10.f,20.f,0);
	pc->position = glm::vec3(15.f,25.f,15.f);
	pd->position = glm::vec3(25.f,25.f,15.f);

	pa->velocity = glm::vec3(.010f,-.013f,.010f);
	pb->velocity = glm::vec3(.010f,-.013f,.010f);
	pc->velocity = glm::vec3(.010f,-.013f,.010f);
	pd->velocity = glm::vec3(.010f,-.013f,.010f);

	scene.pushObject(pa);
	scene.pushObject(pb);
	scene.pushObject(pc);
	scene.pushObject(pd);
	scene.pushObject(ca);




	glutInit(&argc, argv);
	scene.init();

    glutIgnoreKeyRepeat(1);

	glEnable(GL_DEPTH_TEST);

	glutMainLoop();
	return 1;
}