#ifndef Camera_h
#define Camera_h

#include "IwGL.h"
#include "Moveable.h"
#include "glm\gtc\matrix_transform.hpp"

// Default camera values
const GLfloat YAW = -90.0f;
const GLfloat PITCH = 0.0f;

const GLfloat VELOCITY = 0.5f; //velocity of camera/object move
const GLfloat SENSIVITY = 0.01f;//sensivity of camera turning 

//class based on Camera class from learnopengl.com
// An abstract camera class that processes input and calculates the corresponding Eular Angles, Vectors and Matrices for use in OpenGL
class Camera : public Moveable {
    friend class Object3D;
public:
    Camera();
    glm::mat4 GetViewMatrix(); // Returns the view matrix calculated using Eular Angles and the LookAt Matrix

    //move options
    void moveForward() override;
    void moveBackward() override;
    void moveLeft() override;
    void moveRight() override;
    void turn(int32 deltaX, int32 deltaY) override;

    glm::vec3 getFront();
private:
    // Camera Attributes
    // glm::vec3 position; is in moveable class
    glm::vec3 front;
    glm::vec3 up;
    glm::vec3 right;
    glm::vec3 worldUp;
    // Eular Angles
    GLfloat yaw;
    GLfloat pitch;
    
    // Calculates the front, right and up vector from the Camera's (updated) Eular Angles
    void updateCameraVectors();
};


#endif 
