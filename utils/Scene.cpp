#include "KeyboardHandler.h"
#include "Camera.h"
#include "Scene.h"
#include "Object.h"

#include <glm/glm.hpp>
#include <GL/glut.h>
#include <vector>
#include <memory>




static Scene* sceneInstance = nullptr;

void changeSizeCallback(int w, int h) {
    sceneInstance->changeSize(w, h);
}

void renderCallback() {
    sceneInstance->renderScene();
}

Scene::Scene(){
	keyboardHandler.setCamera(&cam);
}

void Scene::pushObject(Object *obj){
    objects.push_back(std::unique_ptr<Object>(obj));  
}

void Scene::renderObjects(){
	for (const auto& obj : objects) {
        obj->draw(); 
    }
}

void Scene::drawSnowMan() {
	glPushMatrix();
	glColor3f(0.9f, 0.f, 0.f);
	glTranslatef( 0., 0., 10.0);
	glutSolidSphere(0.75f,20,20);
	glPopMatrix();
}

void Scene::changeSize(int w, int h) {

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
	
	objectsInteration();
	objectsUpdate();
	renderObjects();

	glutSwapBuffers();
}

void Scene::objectsInteration(){
	for (const auto& obj1 : objects) {
		for (const auto& obj2 : objects) {
			if(obj1 != obj2){
				obj1->interact(obj2);
			}
		}
    }
}

void Scene::objectsUpdate(){
	for (const auto& obj1 : objects) {
		obj1->update();
    }
}


void Scene::init(){
    sceneInstance = this; 

    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowPosition(100,100);
    glutInitWindowSize(1200,1000);
    glutCreateWindow("Clerk");

    glutDisplayFunc(renderCallback);
    glutReshapeFunc(changeSizeCallback);
    glutIdleFunc(renderCallback);

	keyboardHandler.registerCallbacks();
}
