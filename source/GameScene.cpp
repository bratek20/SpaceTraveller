#include "GameScene.h"

GameScene::GameScene(Assets& assets):  shaderProgram(assets.shaderProgram3D),
    object(assets,assets.tetrahedronTexture,0,0,-10){
    projection = glm::perspective(glm::radians(45.0f), (GLfloat)IwGLGetInt(IW_GL_WIDTH) / (GLfloat)IwGLGetInt(IW_GL_HEIGHT), 0.1f, 100.0f);

}
GameScene::~GameScene() {

}
void GameScene::update() {
    object.update();
}

void GameScene::draw() {
    shaderProgram.Use();

    GLint viewLoc = glGetUniformLocation(shaderProgram.getProgram(), "view");
    GLint projLoc = glGetUniformLocation(shaderProgram.getProgram(), "projection");
    
    view = camera.GetViewMatrix();
    
    glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
    glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(projection));

    object.draw();
}

