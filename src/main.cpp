#include <iostream>
#include <string>
#include "window.h"


int main(int argc, char** argv) {

	Window* window = new Window("GAME");


    float currentFrameTime;
    float lastFrameTime;
    float dt;

    // Note that gabe is doing time relative to when the application starts
    // Just a thought-- should things need refactoring later
    lastFrameTime = (float) glfwGetTime();

	while (!glfwWindowShouldClose(window->glWindow))
    {
        /* Poll for and process events */
        glfwPollEvents();

        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        /* Swap front and back buffers */
        glfwSwapBuffers(window->glWindow);


        currentFrameTime = (float) glfwGetTime(); 
        dt = currentFrameTime - lastFrameTime;
        lastFrameTime = currentFrameTime;
    }
	delete window;
	return 0;
}
