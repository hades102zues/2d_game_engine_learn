#include "mouse.h"
#include <GLFW/glfw3.h>
#include <iostream>


Mouse::Mouse() {
    this->x = 0.0f;
    this->y = 0.0f;
    this->lastX = 0.0f;
    this->lastY = 0.0f;
    this->scrollX = 0.0f;
    this->scrollY = 0.0f;
    this->firstMove = true;
    this->isDragging = false;
}


void Mouse::mouse_pos_callback(GLFWwindow* window, double xpos, double ypos) {
    // Save then update
    this->lastX = this->x;
    this->lastY = this->y;
    this->x = xpos;
    this->y = ypos;

    // A note on dragging.
    // Dragging involves a mouse button press and some movement
    // Since we are in the mouse movement callback we atleast know whether the mouse is moving
    // What remains to be known is whether a mouse button is also being pressed.
    for (int i = 0; i < sizeof(this->mousePress)/sizeof(bool); i++){
        if (this->mousePress[i]) {
            this->isDragging = true;
            break;
        }
    }
}

void Mouse::mouse_button_callback(GLFWwindow* window, int button, int action, int mods) {
    //ignore additional mouse buttons
    if (button >= sizeof(this->mousePress)/sizeof(bool)){
        std::cout<<"WARNING_UNHANDLED_MOUSE_BUTTON: "<< button << std::endl;
        return;
    }

    if (action == GLFW_PRESS) {
        this->mousePress[button] = true;
    }
    
    if (action == GLFW_RELEASE) {
        this->mousePress[button] = false;
        this->isDragging = false;
    }

}

void Mouse::mouse_scroll_callback(GLFWwindow* window, double xoffset, double yoffset) {
    this->scrollX = xoffset;
    this->scrollY = yoffset;

}

void Mouse::endFrame() {
    this->scrollX = 0.0f;
    this->scrollY = 0.0f;
    this->lastX = this->x;
    this->lastY = this->y;
}

float Mouse::getDx() {
    return this->lastX - this->x; 
}

float Mouse::getDy() {
    return this->lastY - this->y;
}

bool Mouse::isMouseButtonDown(int button) {
     if (button >= sizeof(this->mousePress)/sizeof(bool)){
        std::cout<<"WARNING_UNRECOGNIZED_BUTTON_REFERENCED: "<< button << std::endl;
        return false;
    }

    return this->mousePress[button];
}