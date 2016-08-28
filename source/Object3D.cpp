#include "Object3D.h"

Object3D::Object3D(Assets& assets, GLuint _texture, float _x, float _y, float _z) :
    Drawable(assets.tetrahedronVertices, _texture, assets.shaderProgram3D), 
    x(_x), y(_y),z(_z) {

    model = glm::translate(model, glm::vec3(_x,_y,_z));

    GLfloat screenWidht = (GLfloat)IwGLGetInt(IW_GL_WIDTH);
    GLfloat screenHeight = (GLfloat)IwGLGetInt(IW_GL_HEIGHT);
    if(screenWidht > screenHeight)
        model = glm::scale(model , glm::vec3(0.5f * screenHeight/screenWidht, 0.5f , 0.5f));
    else
        model = glm::scale(model, glm::vec3(0.5f, 0.5f * screenWidht/screenHeight, 0.5f));
}

void Object3D::update() {
    model = glm::rotate(model, 0.1f, glm::vec3(1.0f, 1.0f, 0.0f));
}