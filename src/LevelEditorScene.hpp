#pragma once 


#include "Scene.hpp"
#include "Shader.hpp"
#include "Texture.hpp"



class LevelEditorScene : public Scene {
    private:

        unsigned int vaoID;
        unsigned int vboID;
        unsigned int eboID;
        Shader* defaultShader;
        Texture* m_defTex;
        

    public:
        LevelEditorScene(Window &window);
        ~LevelEditorScene();
        void init();
        virtual void update(float dt, Keyboard* keyboard, Window& window);
};