#pragma once 


#include "Scene.hpp"


class LevelEditorScene : public Scene {
    public:
        LevelEditorScene();
        ~LevelEditorScene();
        virtual void update(float dt, Keyboard* keyboard, Window &window);
};