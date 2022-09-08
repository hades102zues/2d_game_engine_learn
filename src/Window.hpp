
#pragma once

#include <GLFW/glfw3.h>
#include <string>
#include "Scene.hpp"


class Window {

    private:
        int height, width;
        std::string name;
        // static void framebuffer_resize(GLFWwindow* window, int width, int height);
        // static void glfw_mouse_pos_callback(GLFWwindow* window, double xpos, double ypos);
        // static void glfw_mouse_button_callback(GLFWwindow* window, int button, int action, int mods);
        // static void glfw_mouse_scroll_callback(GLFWwindow* window, double xoffset, double yoffset);

    public:
        GLFWwindow* glWindow;

        Window(std::string name);
        ~Window();
        void loop();
        void changeScene(int sceneCode, Scene* currentScene);
        //Window get();

};
