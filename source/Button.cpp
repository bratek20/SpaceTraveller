#include "Button.h"

Button::Button(Assets& assets, GLuint _texture, GLfloat _leftTopX, GLfloat _leftTopY, GLfloat _width, GLfloat _height) :
    Drawable(assets.squareVertices, _texture, assets.shaderProgram2D),
    leftTopX(_leftTopX), leftTopY(_leftTopY), width(_width), height(_height){
 
    model = glm::translate(model, glm::vec3(leftTopX*2, -leftTopY*2, 0.0f));
    model = glm::translate(model, glm::vec3(-(1-width), 1-height, 0.0f));
    model = glm::scale(model, glm::vec3(width, height, 0.0f));
}

bool Button::isClicked() {
    if (s3ePointerGetState(S3E_POINTER_BUTTON_SELECT) != S3E_POINTER_STATE_DOWN) return false;

    int32 x = s3ePointerGetX();
    int32 y = s3ePointerGetY();

    int screenWidth = IwGLGetInt(IW_GL_WIDTH);
    int screenHeight = IwGLGetInt(IW_GL_HEIGHT);

    float xPercentage = (float)x / screenWidth;
    float yPercentage = (float)y / screenHeight;

    if (leftTopX < xPercentage &&  xPercentage < leftTopX + width &&
        leftTopY < yPercentage && yPercentage < leftTopY + height)
        return true;
    
    return false;
}