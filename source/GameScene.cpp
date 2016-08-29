#include "GameScene.h"

GameScene::GameScene(Assets& _assets):  assets(_assets), shaderProgram(_assets.shaderProgram3D),
    camera(std::make_shared<Camera>()){
    projection = glm::perspective(glm::radians(45.0f),
        (GLfloat)IwGLGetInt(IW_GL_WIDTH) / (GLfloat)IwGLGetInt(IW_GL_HEIGHT), 0.1f, 100.0f);
}
GameScene::~GameScene() {

}
void GameScene::update() {
    for (int i = 0; i < objects.size(); i++)
        objects[i]->update();
}

void GameScene::draw() {
    shaderProgram.Use();

    GLint viewLoc = glGetUniformLocation(shaderProgram.getProgram(), "view");
    GLint projLoc = glGetUniformLocation(shaderProgram.getProgram(), "projection");
    
    view = camera->GetViewMatrix();
    
    glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
    glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(projection));

    for (int i = 0; i < objects.size(); i++)
        objects[i]->draw();
}

void GameScene::addObject() {
    glm::vec3 newObjectPoistion = camera->getPosition() + camera->getFront() * 10.0f;//object's position created in front of camera 
    objects.push_back(
        std::make_shared<Object3D>(
            assets, assets.tetrahedronTexture, camera, newObjectPoistion ) );
}
