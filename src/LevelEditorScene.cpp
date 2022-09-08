#include "LevelEditorScene.hpp"
#include <GLFW/glfw3.h>
#include <iostream>

LevelEditorScene::LevelEditorScene() {

}

LevelEditorScene::~LevelEditorScene() {

}

void LevelEditorScene::update(float dt, Keyboard* keyboard, Window &window) {

    std::cout << "I am leveleditor" <<std::endl;
    if (!this->changingScene && keyboard->isKeyPressed(GLFW_KEY_BACKSPACE)) {
        changingScene = true;
    }

    if (this->changingScene) {
        
    }
}