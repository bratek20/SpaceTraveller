#include "InputScene.h"

InputScene::InputScene(Assets& assets, GameScene& _gameScene): gameScene(_gameScene),
    upButton ( assets, assets.upButtonTexture, 0.2f, 0.7f, 0.1f, 0.1f ),
    downButton ( assets, assets.downButtonTexture, 0.2f, 0.8f, 0.1f, 0.1f),
    leftButton ( assets, assets.leftButtonTexture, 0.1f, 0.8f, 0.1f, 0.1f),
    rightButton ( assets, assets.rightButtonTexture, 0.3f, 0.8f, 0.1f, 0.1f),
    spawnButton ( assets, assets.spawnButtonTexture, 0.8f , 0.2f, 0.1f, 0.1f),
    confirmButton( assets, assets.confirmButtonTexture, 0.8f, 0.4f, 0.1f, 0.1f),
    isTurning(false), currentSpawnTime(spawnCooldown){
    movingObject = gameScene.camera;
}
InputScene::~InputScene() {

}

void InputScene::draw() {
    upButton.draw();
    downButton.draw();
    leftButton.draw();
    rightButton.draw();
    spawnButton.draw();
    confirmButton.draw();
}

void InputScene::update() {
    currentSpawnTime++;

    if (upButton.isClicked())
        movingObject->moveForward();
    else if (downButton.isClicked())
        movingObject->moveBackward();
    else if (leftButton.isClicked())
        movingObject->moveLeft();
    else if (rightButton.isClicked())
        movingObject->moveRight();
    else if (spawnButton.isClicked() && currentSpawnTime > spawnCooldown) {
        gameScene.addObject();
        currentSpawnTime = 0;
        movingObject = gameScene.objects.back(); //now user can move new created 3d object
    }
    else if (confirmButton.isClicked())
        movingObject = gameScene.camera; //now user again moves camera
    else 
        turnEvent();
}

void InputScene::turnEvent() {
    if (s3ePointerGetState(S3E_POINTER_BUTTON_SELECT) != S3E_POINTER_STATE_DOWN) {
        isTurning = false;
        return;
    }

    int32 newTouchedX = s3ePointerGetX();
    int32 newTouchedY = s3ePointerGetY();

    if (!isTurning) {
        isTurning = true;
        lastTouchedX = newTouchedX;
        lastTouchedY = newTouchedY;
        return;
    }

    gameScene.camera->turn(newTouchedX - lastTouchedX, newTouchedY - lastTouchedY);
}
