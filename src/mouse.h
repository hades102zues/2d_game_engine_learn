#pragma once
#include <GLFW/glfw3.h>
#include <vector>

class Mouse {
    public:
        double x,y,lastX,lastY,scrollX,scrollY;
        bool firstMove;
        bool mousePress[3]={false};
        bool isDragging;
        Mouse();
        ~Mouse();
        void mouse_pos_callback(GLFWwindow* window, double xpos, double ypos);
        void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);
        void mouse_scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
        void endFrame();
        float getDx();
        float getDy();
        bool isMouseButtonDown(int button);
};