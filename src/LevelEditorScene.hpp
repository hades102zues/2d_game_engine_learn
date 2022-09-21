#pragma once 


#include "Scene.hpp"


class LevelEditorScene : public Scene {
    private:
        char* vertexSource;
        char* fragmentSource;

        unsigned int vertexID;
        unsigned int fragmentID;
        unsigned int shaderProgramID;

        unsigned int vaoID;
        unsigned int vboID;
        unsigned int eboID;

    public:
        LevelEditorScene(Window &window);
        ~LevelEditorScene();
        void init();
        virtual void update(float dt, Keyboard* keyboard, Window &window);
};