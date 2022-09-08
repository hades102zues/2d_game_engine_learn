#include "Keyboard.hpp"
#include <iostream>


Keyboard::Keyboard() {
    std::cout<< "KEYBOARD_INIT" << std::endl;
}
void Keyboard::key_callback(GLFWwindow* window, int key,  int scancode, int act, int mods){
    if (key >= 350) {
        std::cout<< "UNHANDLED_KEY_" << key << std::endl;
        return;
    }
    
    if (act == GLFW_PRESS) {
        this->keyBucket[key] = true;
        std::cout << "PRESSED: " << key <<std::endl;
        if (key == GLFW_KEY_ESCAPE) {
            glfwSetWindowShouldClose(window, true);
        }
    }
    if (act == GLFW_RELEASE) {
        std::cout << "RELEASED: " << key <<std::endl;
        this->keyBucket[key] = false;
    }

}

bool Keyboard::isKeyPressed(int keyCode) {
    if (keyCode < sizeof(keyBucket)/sizeof(bool)) {
        return  keyBucket[keyCode];
    } else {
        return false;
    }
}
Keyboard::~Keyboard() {
    std::cout << "KEYBOARD_DESTROYED" <<std::endl;
}
