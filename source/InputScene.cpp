#include "InputScene.h"

InputScene::InputScene(Assets& assets, GameScene& _gameScene): gameScene(_gameScene),
    upButton ( Button(assets, assets.simpleTexture, 0.2f, 0.7f, 0.1f, 0.1f) ),
    downButton ( Button(assets, assets.simpleTexture, 0.2f, 0.8f, 0.1f, 0.1f) ),
    leftButton ( Button(assets, assets.simpleTexture, 0.1f, 0.8f, 0.1f, 0.1f) ),
    rightButton ( Button(assets, assets.simpleTexture, 0.3f, 0.8f, 0.1f, 0.1f) ){
}
InputScene::~InputScene() {

}
void InputScene::update() {
    if (upButton.isClicked())
        gameScene.camera.moveForward();
    if (downButton.isClicked())
        gameScene.camera.moveBackward();
    if (leftButton.isClicked())
        gameScene.camera.moveLeft();
    if (rightButton.isClicked())
        gameScene.camera.moveRight();
}

void InputScene::draw() {
    upButton.draw();
    downButton.draw();
    leftButton.draw();
    rightButton.draw();
}
