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
Particle *pb = new Particle();
Particle *pc = new Particle();
Particle *pd = new Particle();
Particle *pe = new Particle();
Particle *pf = new Particle();

Current *ca = new Current();

int main(int argc, char **argv) {
	

	pa->position = glm::vec3(3.f,3.f, 0.f);
	pb->position = glm::vec3(-3.f,-3.f, 0.f);
	pc->position = glm::vec3(3.f,-3.f, 0.f);
	pd->position = glm::vec3(-3.f,3.f, 0.f);
	pe->position = glm::vec3(-3.f,3.f, 10.f);
	pf->position = glm::vec3(-3.f,-3.f, 10.f);

	pa->velocity = glm::vec3(.010f,-.013f,.010f);
	pb->velocity = glm::vec3(.010f,-.013f,.010f);
	pc->velocity = glm::vec3(.010f,-.013f,.010f);
	pd->velocity = glm::vec3(.010f,-.013f,.010f);	
	pe->velocity = glm::vec3(.010f,-.013f,.010f);
	pf->velocity = glm::vec3(.010f,-.013f,.010f);	
	
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
	scene.pushObject(pb);
	scene.pushObject(pc);
	scene.pushObject(pd);
	scene.pushObject(pe);
	scene.pushObject(pf);
	scene.pushObject(ca);

	glutInit(&argc, argv);
	scene.init();

    glutIgnoreKeyRepeat(1);

	glEnable(GL_DEPTH_TEST);

	glutMainLoop();
	return 1;
}