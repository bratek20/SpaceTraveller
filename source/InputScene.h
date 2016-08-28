#ifndef InputScene_h
#define InputScene_h

#include "Assets.h"
#include "Button.h"
#include "GameScene.h"
//based on Shader class from learnopengl tutorial
class InputScene {
private:
    GameScene& gameScene;
    Button upButton, downButton, leftButton, rightButton;
public :
    InputScene(Assets& assets, GameScene& _gameScene);
    ~InputScene();
    void update();
    void draw();
};


#endif 
