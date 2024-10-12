#include "KeyboardHandler.h"
#include "Camera.h"
#include "Scene.h"
#include <glm/glm.hpp>
#include <GL/glut.h>


Scene::Scene(){
	keyboardHandler.setCamera(&cam);
}

void Scene::drawSnowMan() {
	glutSolidSphere(0.75f,20,20);
}

void changeSize(int w, int h) {

	if (h == 0)
		h = 1;
	float ratio =  w * 1.0 / h;

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glViewport(0, 0, w, h);
	gluPerspective(45.0f, ratio, 0.1f, 100.0f);
	glMatrixMode(GL_MODELVIEW);
}


void Scene::renderScene(void) {

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	cam.look();

	glPushMatrix();
	glColor3f(0.9f, 0.f, 0.f);
	glTranslatef( 0., 0., 10.0);
	drawSnowMan();
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.f, 0.9f, 0.f);
	glTranslatef( 10., 0.0, 0.0);
	drawSnowMan();
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.0f, 0.0f, 0.9f);
	glTranslatef( 0., 10.0, 0.0);
	drawSnowMan();
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.0f, 0.0f, 0.9f);
	glTranslatef( 0., -20.0, 0.0);
	drawSnowMan();
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.3f, 0.3f, 0.9f);
	glTranslatef( 0., 10.0, 10.0);
	drawSnowMan();
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.5f, 0.5f, 0.5f);
	glTranslatef( 10., 10.0, 10.0);
	drawSnowMan();
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.4f, 0.1f, 0.1f);
	glTranslatef( 10., .0, 10.0);
	drawSnowMan();
	glPopMatrix();


	glutSwapBuffers();
}

static Scene* sceneInstance = nullptr;

void changeSizeCallback(int w, int h) {
    sceneInstance->changeSize(w, h);
}

void renderCallback() {
    sceneInstance->renderScene();
}

void Scene::init(){
    sceneInstance = this;  // Set the static pointer to this instance

    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowPosition(100,100);
    glutInitWindowSize(1200,1000);
    glutCreateWindow("Clerk");

    glutDisplayFunc(renderCallback);
    glutReshapeFunc(changeSizeCallback);
    glutIdleFunc(renderCallback);
}
