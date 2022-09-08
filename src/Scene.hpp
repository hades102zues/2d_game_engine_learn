#pragma once

#include "Keyboard.hpp"
#include "Window.hpp"

class Scene {
    protected:
        bool changingScene;
    public:
        Scene(){};
        ~Scene(){};
        virtual void update(float dt, Keyboard* keyboard, Window& window) = 0;
};