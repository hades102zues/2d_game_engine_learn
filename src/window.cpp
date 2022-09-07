
#include <glad/glad.h>
#include "window.h"
#include "keyboard.h"
#include <iostream>
#include "mouse.h"

static Mouse* mouse;
static Keyboard* keyboard;

static void framebuffer_resize(GLFWwindow* glWindow, int width, int height) {
    glViewport(0, 0, width, height);
}
static void glfw_mouse_pos_callback(GLFWwindow* window, double xpos, double ypos){
    mouse->mouse_pos_callback(window, xpos, ypos);
}
static void glfw_mouse_button_callback(GLFWwindow* window, int button, int action, int mods) {
    mouse->mouse_button_callback(window, button, action, mods);
}
static void glfw_mouse_scroll_callback(GLFWwindow* window, double xoffset, double yoffset) {
    mouse->mouse_scroll_callback(window, xoffset, yoffset);
}
static void glfw_key_callback(GLFWwindow* window, int key,  int scancode, int act, int mods) {
    keyboard->key_callback(window, key, scancode, act, mods);
}


Window::Window(std::string name) {
    this->height = 600;
    this->width = 800;
    this->name = name;
    this->glWindow = NULL;
    mouse = new Mouse();
    
    if (!glfwInit()) {
        std::cout << "GLFW_FAIL_INIT" << std::endl;
        exit(-1);
    }
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_RESIZABLE, GL_TRUE);

    this->glWindow = glfwCreateWindow(this->width, this->height, name.c_str(), NULL, NULL);

    if (this->glWindow == NULL) {
        std::cout << "GLFW_WINDOW_FAIL_CREATION" << std::endl;
        exit(-1);
    }

    glfwMakeContextCurrent(this->glWindow);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		std::cout << "GLAD_FAIL_INIT" << std::endl;
		exit(-1);
	}
    // ==Viewport==
    glViewport(0, 0, this->width, this->height);
    glfwGetFramebufferSize(this->glWindow, &this->width, &this->height);
    glfwSetFramebufferSizeCallback(this->glWindow, framebuffer_resize);
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f); 

    // ==Mouse Callbacks==
    glfwSetCursorPosCallback(this->glWindow, glfw_mouse_pos_callback);
    glfwSetMouseButtonCallback(this->glWindow, glfw_mouse_button_callback);
    glfwSetScrollCallback(this->glWindow, glfw_mouse_scroll_callback);

    // ==Keyboard Callback==
    glfwSetKeyCallback(this->glWindow, glfw_key_callback);
    

}

Window::~Window() {
    glfwTerminate();
}


void Window::loop() {
    while (!glfwWindowShouldClose(this->glWindow))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        /* Swap front and back buffers */
        glfwSwapBuffers(this->glWindow);

        /* Poll for and process events */
        glfwPollEvents();
    }
}