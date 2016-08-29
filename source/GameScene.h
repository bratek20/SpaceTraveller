#ifndef GameScene_h
#define GameScene_h

#include "Assets.h"
#include "Object3D.h"
#include "Camera.h"
#include "s3e.h"
#include "glm/glm.hpp"

//class supports 3D objects and camera
class GameScene {
    friend class InputScene;
private:
    Assets& assets;
    std::shared_ptr<Camera> camera;
    std::vector<std::shared_ptr<Object3D> >objects; //i avoid creating copy by std::vector thanks ptr instead object
    ShaderProgram shaderProgram;
    glm::mat4 projection;
    glm::mat4 view;
public :
    GameScene(Assets &assets);
    ~GameScene();
    
    void update();
    void draw();
    void addObject();//create new Object3D in front of camera
};


#endif 
