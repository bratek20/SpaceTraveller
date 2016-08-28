#ifndef Moveable_h
#define Moveable_h

#include "glm/glm.hpp"

class Moveable {
protected:
    glm::vec3 position;
public:
    Moveable();
    virtual ~Moveable() {}

    virtual void moveForward() = 0;
    virtual void moveBackward() = 0;
    virtual void moveLeft() = 0;
    virtual void moveRight() = 0;
};
#endif 
