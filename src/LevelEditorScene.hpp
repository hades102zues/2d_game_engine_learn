#pragma once 


#include "Scene.hpp"
#include "Shader.hpp"


class LevelEditorScene : public Scene {
    private:

        unsigned int vaoID;
        unsigned int vboID;
        unsigned int eboID;
        Shader* defaultShader;
        

    public:
        LevelEditorScene(Window &window);
        ~LevelEditorScene();
        void init();
        virtual void update(float dt, Keyboard* keyboard, Window &window);
};