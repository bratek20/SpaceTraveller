#ifndef GameScene_h
#define GameScene_h

#include "Assets.h"
#include "Object3D.h"
#include "Camera.h"
#include "s3e.h"
#include "glm/glm.hpp"

class GameScene {
    friend class InputScene;
private:
    Camera camera;
    Object3D object;
    ShaderProgram shaderProgram;
    glm::mat4 projection;
    glm::mat4 view;
public :
    GameScene() {}
    GameScene(Assets &assets);
    ~GameScene();
    void update();
    void draw();
};


#endif 
