#include "Camera.h"
#include "cstdio"
Camera::Camera() : Moveable(), worldUp (glm::vec3(0.0f, 1.0f, 0.0f)),
    yaw(YAW), pitch (PITCH), front(glm::vec3(0.0f, 0.0f, -1.0f)){
    updateCameraVectors();
}

void Camera::updateCameraVectors(){
    // Calculate the new Front vector
    glm::vec3 newFront;
    newFront.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
    newFront.y = sin(glm::radians(pitch));
    newFront.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
    
    front = glm::normalize(newFront);
    // Also re-calculate the Right and Up vector
    right = glm::normalize(glm::cross(front, worldUp));  // Normalize the vectors, because their length gets closer to 0 the more you look up or down which results in slower movement.
    up = glm::normalize(glm::cross(right, front));
}

glm::mat4 Camera::GetViewMatrix() {
    return glm::lookAt(position, position + front, up);
}

void Camera::moveForward() {
    position += front * VELOCITY;
}
void Camera::moveBackward() {
    position -= front * VELOCITY;
}
void Camera::moveLeft() {
    position -= right * VELOCITY;
}
void Camera::moveRight() {
    position += right * VELOCITY;
}