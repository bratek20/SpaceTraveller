#ifndef InputScene_h
#define InputScene_h

#include "Assets.h"
#include "Button.h"
#include "GameScene.h"

//class supports 2d object buttons to collect input to move camera and 3d objects
class InputScene {
private:
    GameScene& gameScene;
    Button upButton, downButton, leftButton, rightButton; //movement buttons
    Button spawnButton; //spawn new object3D and set it movingObject 
    Button confirmButton; //click to stop moving new created 3d object

    std::shared_ptr<Moveable> movingObject;//tracks currently moving thing (camera or new created 3d Object)
    const int spawnCooldown = 42;
    int currentSpawnTime;

    //need for turning camera
    bool isTurning;
    int32 lastTouchedX, lastTouchedY;
    void turnEvent();
public :
    InputScene(Assets& assets, GameScene& _gameScene);
    ~InputScene();
    void update();
    void draw();
};


#endif 
