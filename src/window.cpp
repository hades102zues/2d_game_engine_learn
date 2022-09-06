
#include <glad/glad.h>
#include "window.h"
#include <iostream>


void Window::framebuffer_resize(GLFWwindow* glWindow, int width, int height) {
    glViewport(0, 0, width, height);
}

Window::Window() {
    this->height = 600;
    this->width = 800;
    this->name = "GAME";
    this->glWindow = NULL;
    
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

    glfwGetFramebufferSize(this->glWindow, &this->width, &this->height);
    glViewport(0, 0, this->width, this->height);
    glfwSetFramebufferSizeCallback(this->glWindow, framebuffer_resize);
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f); 

}

Window::~Window() {
    glfwTerminate();
}

// Window Window::get() {
//     if (!this->window) {
        
//     }

//     return this->window;
// }



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