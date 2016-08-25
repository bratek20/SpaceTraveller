#ifndef InputScene_h
#define InputScene_h

#include "Assets.h"
#include "Button.h"
//based on Shader class from learnopengl tutorial
class InputScene {
private:
    Button upButton, downButton, leftButton, rightButton;
public :
    InputScene(Assets &assets);
    ~InputScene();
    void update();
    void draw();
};


#endif 
