#pragma once
#include <GLFW/glfw3.h>

class Keyboard {
    public:
        bool keyBucket[350] = {false};
        Keyboard();
        ~Keyboard();
        void key_callback(GLFWwindow* window, int key,  int scancode, int act, int mods);
};