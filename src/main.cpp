#include <iostream>
#include <string>
#include "Window.hpp"


int main(int argc, char** argv) {

	Window* window = new Window("GAME");
    window->loop();

    
	delete window;
	return 0;
}
