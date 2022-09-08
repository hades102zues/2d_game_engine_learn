#include "LevelScene.hpp"
#include <GLFW/glfw3.h>
#include <iostream>


LevelScene::LevelScene(Window &window) {
    std::cout<< "Level Scene started" << std::endl;
    this->changingScene = false;
    this->timeToChangeScene = 2.0f;
    window.r = 0.2f;
    window.g = 0.3f;
    window.b = 0.3f;
    window.a = 1.0f;
}

LevelScene::~LevelScene() {

std::cout<< "Destroying Level Scene" << std::endl;
}

void LevelScene::update(float dt, Keyboard* keyboard, Window &window) {


    if (!this->changingScene and keyboard->isKeyPressed(GLFW_KEY_SPACE)) {
        this->changingScene = true;
    }

    if (this->changingScene and this->timeToChangeScene > 0.0f) {
        this->timeToChangeScene -= dt;
        window.r -= dt * 5.0f;
        window.g -= dt * 5.0f;
        window.b -= dt * 5.0f;
    }
    else if (this->changingScene) { 
        std::cout << "Changing Scene from levelScene" << std::endl;
        window.changeSceneHandler(0);
       
    }
    
}