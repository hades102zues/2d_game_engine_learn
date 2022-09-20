#pragma once 


#include "Scene.hpp"


class LevelEditorScene : public Scene {
    private:
        const char* vertexSource;
        const char* fragmentSource;
        unsigned int vertexID;
        unsigned int fragmentID;
        unsigned int shaderProgramID;

    public:
        LevelEditorScene(Window &window);
        ~LevelEditorScene();
        void init();
        virtual void update(float dt, Keyboard* keyboard, Window &window);
};