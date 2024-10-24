#include "KeyboardHandler.h"
#include "Camera.h"
#include <glm/glm.hpp>
#include <GL/glut.h>
#include <algorithm>

void KeyboardHandler::setCamera(Camera *camera){
    cam = camera;
}
void KeyboardHandler::pressKey(int key, int xx, int yy) {
	switch (key) {
		case GLUT_KEY_LEFT : cam->deltaAzimuth = 0.01f; break;
		case GLUT_KEY_RIGHT : cam->deltaAzimuth = -0.01f; break;
		case GLUT_KEY_DOWN : cam->deltaAltitude = 0.01f; break;
		case GLUT_KEY_UP : cam->deltaAltitude = -0.01f; break;
	}
}

void KeyboardHandler::pressKeyNormal(unsigned char key, int xx, int yy) {

	switch (key) {
		case 'w': cam->deltaMoveX = 1.5f; break;
		case 's': cam->deltaMoveX = -1.5f; break;
		case 'a': cam->deltaMoveY = -1.5f; break;
		case 'd': cam->deltaMoveY = 1.5f; break;
		case 'f': this->keys.push_back('f');
	}
}

void KeyboardHandler::releaseKeyNormal(unsigned char key, int x, int y) {
	switch (key) {
		case 'w' : 
		case 's' : 
		case 'a' : 
		case 'd' : cam->deltaMoveX = 0.f; cam->deltaMoveY = 0.f;break;
		case 'f': this->keys.erase(std::remove(this->keys.begin(), this->keys.end(), 'f'), this->keys.end());
	}
}

void KeyboardHandler::releaseKey(int key, int x, int y) {
	switch (key) {
		case GLUT_KEY_LEFT :
		case GLUT_KEY_RIGHT : 
		case GLUT_KEY_UP :
		case GLUT_KEY_DOWN :cam->deltaAzimuth = 0.0f; cam->deltaAltitude=0.0f;break;
	}
}

void KeyboardHandler::registerCallbacks(){
	glutKeyboardFunc([](unsigned char key, int xx, int yy) {
        KeyboardHandler::getInstance().pressKeyNormal(key, xx, yy);
    });
    glutSpecialFunc([](int key, int xx, int yy) {
        KeyboardHandler::getInstance().pressKey(key, xx, yy);
    });
    glutKeyboardUpFunc([](unsigned char key, int xx, int yy) {
        KeyboardHandler::getInstance().releaseKeyNormal(key, xx, yy);
    });
    glutSpecialUpFunc([](int key, int xx, int yy) {
        KeyboardHandler::getInstance().releaseKey(key, xx, yy);
    });
}