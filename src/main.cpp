#include <iostream>
#include <string>
#include <filesystem>
#include "Window.hpp"


int main(int argc, char** argv) {
	std::cout << "PROGRAM DIRECTORY: " << std::filesystem::current_path().string() << std::endl;
	Window* window = new Window("GAME");
    window->loop();

    
	delete window;
	return 0;
}
