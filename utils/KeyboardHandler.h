#ifndef KEYBOARDHANDLER_H
#define KEYBOARDHANDLER_H
#include "Camera.h"
#include <vector>

class KeyboardHandler {
public:
    
    static KeyboardHandler& getInstance() {
        static KeyboardHandler instance;
        return instance;
    }

    std::vector<char> keys;

    void setCamera(Camera* camera);
    void pressKey(int key, int xx, int yy);
    void releaseKey(int key, int xx, int yy);
    void pressKeyNormal(unsigned char key, int xx, int yy);
    void releaseKeyNormal(unsigned char key, int xx, int yy);
    void registerCallbacks();

private:
    Camera* cam;

    KeyboardHandler() : cam(nullptr) {}
    KeyboardHandler(const KeyboardHandler&) = delete;
    KeyboardHandler& operator=(const KeyboardHandler&) = delete;
};

#endif 