#pragma once 


#include "Scene.hpp"


class LevelEditorScene : public Scene {
    public:
        LevelEditorScene(Window &window);
        ~LevelEditorScene();
        virtual void update(float dt, Keyboard* keyboard, Window &window);
};