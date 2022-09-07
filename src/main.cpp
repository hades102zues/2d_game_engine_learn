#include <iostream>
#include <string>
#include "window.h"


int main(int argc, char** argv) {

	Window* window = new Window("GAME");

	while (!glfwWindowShouldClose(window->glWindow))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        /* Swap front and back buffers */
        glfwSwapBuffers(window->glWindow);

        /* Poll for and process events */
        glfwPollEvents();
    }
	delete window;
	return 0;
}
