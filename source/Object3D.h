#ifndef Object3D_h
#define Object3D_h

#include "Drawable.h"
#include "Assets.h"
#include "s3e.h"

//drawable Object3D class to help handle input in InputScene
class Object3D : public Drawable {
private:
    float x, y, z;
public :
    Object3D() {};
    Object3D(Assets& assets, GLuint _texture, float x,float y, float z);
    void update();
};


#endif 
