#include "keyboard.h"
#include <iostream>


Keyboard::Keyboard() {
    std::cout<< "KEYBOARD_INIT" << std::endl;
}
void Keyboard::key_callback(GLFWwindow* window, int key,  int scancode, int act, int mods){
    if (key >= 350) {
        std::cout<< "UNHANDLED_KEY_" << key << std::endl;
        return;
    }
    if (key == GLFW_PRESS) {
        this->keyBucket[key] = true;
    }
    if (key == GLFW_RELEASE) {
        this->keyBucket[key] = false;
    }
    if (key == GLFW_KEY_ESCAPE) {
        glfwSetWindowShouldClose(window, true);
    }
}
Keyboard::~Keyboard(){}
