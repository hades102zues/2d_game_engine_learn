#pragma once

#include "Keyboard.hpp"
#include "Window.hpp"
#include <iostream>

class Scene {
    protected:
        bool changingScene;
        float timeToChangeScene;
    public:
        Scene(){};
        virtual ~Scene(){};
        virtual void update(float dt, Keyboard* keyboard, Window& window) = 0;
        
};