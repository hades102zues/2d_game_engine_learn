#include "Scene.hpp"

class LevelScene : public Scene {
    public:
        LevelScene();
        ~LevelScene();
        virtual void update(float dt);
};