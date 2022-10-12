#include <glad/glad.h>


#include "LevelEditorScene.hpp"
#include <GLFW/glfw3.h>
#include <iostream>
#include "import_shader_source.hpp"
#include "Shader.hpp"


static const float vertexData1[] = {
    //position              //color
    0.5f, -0.5f, 0.0f,      1.0f, 0.0f, 0.0f, 1.0f, //Bottom Right
    -0.5f, 0.5f, 0.0f,      0.0f, 1.0f, 0.0f, 1.0f, //Top Left
    0.5f, 0.5f, 0.0f,       0.0f, 0.0f, 1.0f, 1.0f, //Top Right
    -0.5f, -0.5f, 0.0f,     1.0f, 1.0f, 0.0f, 1.0f  //Bottom Left

};

static const float vertexData[] = {
    //position              //color
    0.5f, 0.5f, 0.0f,      1.0f, 0.0f, 0.0f, 1.0f, //Top Right
    0.5f, -0.5f, 0.0f,      0.0f, 1.0f, 0.0f, 1.0f, //Bottom Right
    -0.5f, -0.5f, 0.0f,       0.0f, 0.0f, 1.0f, 1.0f, //Bottom left
    -0.5f, 0.5f, 0.0f,     1.0f, 1.0f, 0.0f, 1.0f  //Top Left

};


//you must do this in clock wise order here in C!!
//think in terms of that the vertex data is collected in batches
//must use the same data type as what will be specified in draw Elements
unsigned int elementBuffer[] = {
    0, 1, 3, //top right triangle
    1, 2, 3, //bottom left triangle
};


LevelEditorScene::LevelEditorScene(Window &window) {

    std::cout<< "LevelEditor Scene started" << std::endl;
    // this->changingScene = false;
    // this->timeToChangeScene = 2.0f;
    window.r = 0.25f;
    window.g = 0.21f;
    window.b = 0.41f;
    this->defaultShader = nullptr;
    


   
}

void LevelEditorScene::init() {
    this->defaultShader = new Shader("src/assets/shaders/vertexShader.vs", "src/assets/shaders/fragmentShader.fs", "LEVEL_EDITOR");


    // -=====VERTEX BUFFERS
    glGenVertexArrays(1, &this->vaoID);
    glBindVertexArray(this->vaoID);

    glGenBuffers(1, &this->vboID);
    glBindBuffer(GL_ARRAY_BUFFER, this->vboID);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertexData), vertexData, GL_STATIC_DRAW);
    
    
    glGenBuffers(1, &this->eboID);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->eboID);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(elementBuffer), elementBuffer, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 7 * sizeof(float), (void*) 0);
    glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 7 * sizeof(float), (void*)(3 * sizeof(float)));

    // note that when an enabled attrib does not receive data
    // nothing at all will be drawn to the screen. 
    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);

    
    

}
LevelEditorScene::~LevelEditorScene() {
    std::cout<< "Destroying Level Editor Scene" << std::endl;
}

void LevelEditorScene::update(float dt, Keyboard* keyboard, Window &window) {


    // Ready the pipeline
    this->defaultShader->useShader();
    glBindVertexArray(this->vaoID);

      glDrawElements(GL_TRIANGLES, sizeof(elementBuffer)/sizeof(unsigned int), GL_UNSIGNED_INT, 0);

       
    glBindVertexArray(0);
    this->defaultShader->detachShader();






    

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