#ifndef Object3D_h
#define Object3D_h

#include "Drawable.h"
#include "Moveable.h"
#include "Assets.h"
#include "Camera.h"
#include "s3e.h"

//object3D is drawable and moveable
class Object3D : public Drawable, public Moveable {//i know that object shoudnt inheritate form thwo classes
private:                                           // but in this situation i think it works fine 
    std::shared_ptr<Camera> camera;

    glm::mat4 initialModel;//starting model

    const glm::vec3 rotationVector = glm::vec3(1.0f, 1.0f, 0.0f);//around what i am rotating
    float rotationAngle;//my current rotation angle
    const float deltaAngle = 0.1f;//how my rotation is changed
public :
    Object3D(Assets& assets, GLuint _texture, std::shared_ptr<Camera> _camera, glm::vec3 spawnPosition);
    void update();

    //move functions
    void moveForward() override;
    void moveBackward() override;
    void moveLeft() override;
    void moveRight() override;
    void turn(int32 deltaX, int32 deltaY) override {};//3d object cant turn
};


#endif 
