#pragma once

#include "Keyboard.hpp"
#include "Window.hpp"
#include <iostream>
#include "Camera.hpp"

class Scene {
    protected:
        bool changingScene;
        float timeToChangeScene;
        Camera* camera;

    public:
        Scene(){};
        
        // virtual functions will have an implementation in the base class
        // which can be overrided in the predecessor
        // all base classes intended for polymorphic runtime must have virtual destructor
        virtual ~Scene(){};
        virtual void init(){}; 

        //  pure virtual functions enforces that the predecessor must implement this function. 
        //  Hence the base class is considered to be abstract 
        virtual void update(float dt, Keyboard* keyboard, Window& window) = 0; 
        
};