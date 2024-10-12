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

Scene scene;


int main(int argc, char **argv) {
	


	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(100,100);
	glutInitWindowSize(1200,1000);
	glutCreateWindow("Clerk");

	
	scene.init();

	scene.keyboardHandler.registerCallbacks();

    glutIgnoreKeyRepeat(1);

	glEnable(GL_DEPTH_TEST);

	glutMainLoop();

	return 1;
}