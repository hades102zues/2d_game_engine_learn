
#include <glad/glad.h>
#include <iostream>

#include "Window.hpp"
#include "Scene.hpp"
#include "Mouse.hpp"
#include "Keyboard.hpp"
#include "LevelEditorScene.hpp"
#include "LevelScene.hpp"


static Mouse* mouse;
static Keyboard* keyboard;
// static int r = 1;
// static int g = 1;
// static int b = 1;
// static int a = 1;



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
static void changeScene(int sceneCode, Scene* &currentScene) {
    switch (sceneCode) {
        case 0:
            currentScene = new LevelEditorScene();
            break;
        case 1:
            currentScene = new LevelScene();
            break;
        default:
            //assertion
            std::cout<< "UNRECOGNIZED_SCENE";
            break;

    }
}


Window::Window(std::string name) {
    this->height = 600;
    this->width = 800;
    this->name = name;
    this->glWindow = NULL;
    this->r = 1.0f;
    this->g = 1.0f;
    this->b = 1.0f;
    this->a = 1.0f;
    mouse = new Mouse();
    keyboard = new Keyboard();




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
    glClearColor(this->r, this->g, this->b, this->a); 

    // ==Mouse Callbacks==
    glfwSetCursorPosCallback(this->glWindow, glfw_mouse_pos_callback);
    glfwSetMouseButtonCallback(this->glWindow, glfw_mouse_button_callback);
    glfwSetScrollCallback(this->glWindow, glfw_mouse_scroll_callback);

    // ==Keyboard Callback==
    glfwSetKeyCallback(this->glWindow, glfw_key_callback);
    std::cout<< "WINDOW_INIT" << std::endl;

}

Window::~Window() {
    glfwTerminate();
    delete mouse, keyboard;
    std::cout << "WINDOW_DESTROYED" <<std::endl;
}


void Window::loop() {
    Scene* currentScene;
    float currentFrameTime;
    float lastFrameTime;
    float dt;

    // Note that gabe is doing time relative to when the application starts
    // Just a thought-- should things need refactoring later
    lastFrameTime = (float) glfwGetTime();
    currentFrameTime = lastFrameTime;
    dt = currentFrameTime - lastFrameTime;
    changeScene(0, currentScene);

	while (!glfwWindowShouldClose(this->glWindow))
    {

        glfwPollEvents();
        glClear(GL_COLOR_BUFFER_BIT);

        if (dt > 0 ) {
            currentScene->update(dt, keyboard, *this);
        }



        /* Swap front and back buffers */
        glfwSwapBuffers(this->glWindow);


        currentFrameTime = (float) glfwGetTime(); 
        dt = currentFrameTime - lastFrameTime;
        lastFrameTime = currentFrameTime;
    }
}

