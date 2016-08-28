#ifndef Button_h
#define Button_h

#include "Drawable.h"
#include "Assets.h"
#include "s3e.h"

//drawable button class to help handle input in InputScene
class Button : public Drawable {
private:
    GLfloat leftTopX, leftTopY; //in percentage how long leftTop point should be translated into screen 
                                //e.g. (0.5, 0.5) means that our object leftTop point is in the center of the screen 
    GLfloat width, height; //in percentage how much screen they occupied 
                           //e.g. width=0.25f means it occupies 25% of screen width
public :
    Button() {};
    Button(Assets& assets, GLuint _texture, GLfloat _leftTopX, GLfloat _leftTopY, GLfloat _width, GLfloat _height);
    bool isClicked(); //require s3ePointerUpdate
};


#endif 
