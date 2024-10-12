#include <stdlib.h>
#include <math.h>
#include "Scene.h"
#include "Camera.h"
#include "KeyboardHandler.h"
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif


Camera cam;

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

void drawSnowMan() {
	glutSolidSphere(0.75f,20,20);
}

void renderScene(void) {

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

Scene scene;


int main(int argc, char **argv) {
	
	KeyboardHandler& keyboardHandler = KeyboardHandler::getInstance();
    keyboardHandler.setCamera(&cam);


	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(100,100);
	glutInitWindowSize(1200,1000);
	glutCreateWindow("Clerk");

	glutDisplayFunc(renderScene);
	glutReshapeFunc(changeSize);
	glutIdleFunc(renderScene);

	keyboardHandler.registerCallbacks();

    glutIgnoreKeyRepeat(1);

	glEnable(GL_DEPTH_TEST);

	glutMainLoop();

	return 1;
}