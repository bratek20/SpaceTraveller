#include "Moveable.h"

Moveable::Moveable() : position(glm::vec3(0, 0, 0)) {
}

glm::vec3 Moveable::getPosition() {
    return position;
}