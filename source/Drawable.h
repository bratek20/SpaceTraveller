#ifndef Drawable_h
#define Drawable_h

#include "IwGL.h"
#include "Assets.h"
#include "ShaderProgram.h"
#include "vector"
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"
//base class for further drawable objects
//assume that vertices will be set in delivered class and will contain:
// 3D vertices and 2D texture coordination
class Drawable {
private:
    std::vector<GLfloat> vertices; //what shape i draw
    GLuint texture; //how this shape is filled
    
    GLuint VAO, VBO;//vertex array object, vertex buffer object
protected:
    ShaderProgram shaderProgram; //how i draw
    glm::mat4 model;
public:   
    Drawable() {};
    Drawable(std::vector<GLfloat> &_vertices, GLuint _texture, ShaderProgram _shaderProgram);
    ~Drawable();
    virtual void draw(); //delivered classes should use it after their draw actions
};

#endif 
