#include "Object3D.h"

Object3D::Object3D(Assets& assets, GLuint _texture, std::shared_ptr<Camera> _camera, glm::vec3 spawnPosition) :
    Drawable(assets.tetrahedronVertices, _texture, assets.shaderProgram3D), camera(_camera), rotationAngle(0.0f){

    model = glm::translate(model, spawnPosition);

    //i want that object wont be stretched
    GLfloat screenWidht = (GLfloat)IwGLGetInt(IW_GL_WIDTH);
    GLfloat screenHeight = (GLfloat)IwGLGetInt(IW_GL_HEIGHT);
    if(screenWidht > screenHeight)
        model = glm::scale(model , glm::vec3(0.5f * screenHeight/screenWidht, 0.5f , 0.5f));
    else
        model = glm::scale(model, glm::vec3(0.5f, 0.5f * screenWidht/screenHeight, 0.5f));

    initialModel = model;
}

void Object3D::update() {
    rotationAngle += deltaAngle;
    
    model = initialModel;
    model = glm::translate(model, position);
    model = glm::rotate(model, rotationAngle, rotationVector);
}

void Object3D::moveForward() {
    position += camera->front * VELOCITY;
}
void Object3D::moveBackward() {
    position -= camera->front * VELOCITY;
}
void Object3D::moveLeft() {
    position -= camera->right * VELOCITY;
}
void Object3D::moveRight() {
    position += camera->right * VELOCITY;    
}
