#include "InputScene.h"

InputScene::InputScene(Assets& assets): 
    upButton ( Button(assets, assets.simpleTexture, 0.2f, 0.7f, 0.1f, 0.1f) ),
    downButton ( Button(assets, assets.simpleTexture, 0.2f, 0.8f, 0.1f, 0.1f) ),
    leftButton ( Button(assets, assets.simpleTexture, 0.1f, 0.8f, 0.1f, 0.1f) ),
    rightButton ( Button(assets, assets.simpleTexture, 0.3f, 0.8f, 0.1f, 0.1f) ){
}
InputScene::~InputScene() {

}
void InputScene::update() {
    if (upButton.isClicked())
        puts("upButton clicked");
    if (downButton.isClicked())
        puts("downButton clicked");
    if (leftButton.isClicked())
        puts("leftButton clicked");
    if (rightButton.isClicked())
        puts("rightButton clicked");
}

void InputScene::draw() {
    upButton.draw();
    downButton.draw();
    leftButton.draw();
    rightButton.draw();
}
