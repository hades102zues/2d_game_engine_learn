#include "LevelEditorScene.hpp"
#include <GLFW/glfw3.h>
#include <iostream>

LevelEditorScene::LevelEditorScene(Window &window) {
    std::cout<< "LevelEditor Scene started" << std::endl;
    this->changingScene = false;
    this->timeToChangeScene = 2.0f;
    window.r = 0.25f;
    window.g = 0.21f;
    window.b = 0.41f;
}

LevelEditorScene::~LevelEditorScene() {
    std::cout<< "Destroying Level Editor Scene" << std::endl;
}

void LevelEditorScene::update(float dt, Keyboard* keyboard, Window &window) {

    // std::cout << "I am leveleditor" <<std::endl;
    if (!this->changingScene && keyboard->isKeyPressed(GLFW_KEY_SPACE)) {
        changingScene = true;
    }

    if (this->changingScene and this->timeToChangeScene > 0.0f) {
        // dt represents the time taken for one go of the super loop
        // timeToChangeScene in a sense represents a unit of time that should have passed before 
        // changing the scene
        // only when the amount of dt has passed so that it equals timeToChange
        // should we change the scene completely
        // what we will do in the interum is apply a nice fade transition
        this->timeToChangeScene -= dt;
        window.r -= dt * 5.0f;
        window.g -= dt * 5.0f;
        window.b -= dt * 5.0f;
    }
    else if (this->changingScene) { 
        std::cout << "Changing Scene from levelEditor" << std::endl;
        window.changeSceneHandler(1);
    }
}