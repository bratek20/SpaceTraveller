#ifndef Moveable_h
#define Moveable_h

#include "glm/glm.hpp"

//interface supports moving object
class Moveable {
protected:
    glm::vec3 position;//position in game world
public:
    Moveable();
    virtual ~Moveable() {}

    virtual void moveForward() = 0;
    virtual void moveBackward() = 0;
    virtual void moveLeft() = 0;
    virtual void moveRight() = 0;
    virtual void turn(int32 deltaX, int32 deltaY) = 0;

    glm::vec3 getPosition();
};
#endif 
