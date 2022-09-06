
#pragma once

#include <GLFW/glfw3.h>
#include <string>



class Window {

    private:
        int height, width;
        std::string name;
        static void framebuffer_resize(GLFWwindow* window, int width, int height);
        static void glfw_mouse_pos_callback(GLFWwindow* window, double xpos, double ypos);
        static void glfw_mouse_button_callback(GLFWwindow* window, int button, int action, int mods);
        static void glfw_mouse_scroll_callback(GLFWwindow* window, double xoffset, double yoffset);

    public:
        static Window window;
        GLFWwindow* glWindow;

        Window();
        ~Window();
        void loop();
        //Window get();

};
