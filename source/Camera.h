#ifndef Camera_h
#define Camera_h

#include "IwGL.h"
#include "Moveable.h"
#include "glm\gtc\matrix_transform.hpp"

// Default camera values
const GLfloat YAW = -90.0f;
const GLfloat PITCH = 0.0f;
const GLfloat VELOCITY = 1.0f;

//class based on Camera class from learnopengl.com
// An abstract camera class that processes input and calculates the corresponding Eular Angles, Vectors and Matrices for use in OpenGL
class Camera : public Moveable {
public:
    // Constructor with vectors
    Camera();
    // Constructor with scalar values

    // Returns the view matrix calculated using Eular Angles and the LookAt Matrix
    glm::mat4 GetViewMatrix();

    //move options
    void moveForward() override;
    void moveBackward() override;
    void moveLeft() override;
    void moveRight() override;
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
    
    // Calculates the front vector from the Camera's (updated) Eular Angles
    void updateCameraVectors();
};


#endif 
