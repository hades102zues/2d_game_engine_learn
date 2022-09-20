#include <glad/glad.h>


#include "LevelEditorScene.hpp"
#include <GLFW/glfw3.h>
#include <iostream>
#include "import_shader_source.hpp"


LevelEditorScene::LevelEditorScene(Window &window) {
    // std::cout<< "LevelEditor Scene started" << std::endl;
    // this->changingScene = false;
    // this->timeToChangeScene = 2.0f;
    // window.r = 0.25f;
    // window.g = 0.21f;
    // window.b = 0.41f;

    this->vertexSource = readFromShaderFile("./src/assets/vertexShader.vs", "LEVEL_EDITOR_VSHADER");
    this->fragmentSource = readFromShaderFile("./src/assets/fragmentShader.fs", "LEVEL_EDITOR_FSHADER");

}

void LevelEditorScene::init() {
    this->vertexID = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(this->vertexID, 1, &this->vertexSource, NULL);
    glCompileShader(this->vertexID);

    const int logLength = 512;
    int success;
    char infoLog[512];

    glGetShaderiv(this->vertexID, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(this->vertexID, 512, NULL, infoLog);
        std::cout<< "LEVEL_EDITOR_ERROR_SHADER_VERTEX_COMIPILATION\n" << infoLog << std::endl;
    }

    this->fragmentID = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(this->fragmentID, 1, &this->fragmentSource, NULL);
    glCompileShader(this->fragmentID);

    glGetShaderiv(this->fragmentID, GL_COMPILE_STATUS, &success);
    if(!success) {
        glGetShaderInfoLog(this->fragmentID, 512, NULL, infoLog);
        std::cout<< "LEVEL_EDITOR_ERROR_SHADER_VERTEX_COMIPILATION\n" << infoLog << std::endl;
    }

    this->shaderProgramID = glCreateProgram();
    glAttachShader(this->shaderProgramID, this->vertexID);
    glAttachShader(this->shaderProgramID, this->fragmentID);
    glLinkProgram(this->shaderProgramID);

    glGetProgramiv(this->shaderProgramID, GL_LINK_STATUS, &success);
     if (!success) {
        glGetProgramInfoLog(this->vertexID, 512, NULL, infoLog);
        std::cout<< "LEVEL_EDITOR_ERROR_SHADER_PROGRAM_LINKING\n" << infoLog << std::endl;
    }

    glDeleteShader(this->vertexID);
    glDeleteShader(this->fragmentID);



}
LevelEditorScene::~LevelEditorScene() {
    std::cout<< "Destroying Level Editor Scene" << std::endl;
}

void LevelEditorScene::update(float dt, Keyboard* keyboard, Window &window) {

    // // std::cout << "I am leveleditor" <<std::endl;
    // if (!this->changingScene && keyboard->isKeyPressed(GLFW_KEY_SPACE)) {
    //     changingScene = true;
    // }

    // if (this->changingScene and this->timeToChangeScene > 0.0f) {
    //     // dt represents the time taken for one go of the super loop
    //     // timeToChangeScene in a sense represents a unit of time that should have passed before 
    //     // changing the scene
    //     // only when the amount of dt has passed so that it equals timeToChange
    //     // should we change the scene completely
    //     // what we will do in the interum is apply a nice fade transition
    //     this->timeToChangeScene -= dt;
    //     window.r -= dt * 5.0f;
    //     window.g -= dt * 5.0f;
    //     window.b -= dt * 5.0f;
    // }
    // else if (this->changingScene) { 
    //     std::cout << "Changing Scene from levelEditor" << std::endl;
    //     window.changeSceneHandler(1);
    // }
}