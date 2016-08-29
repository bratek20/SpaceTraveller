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
    glm::mat4 model;//where i am in world/what is my rotation etc.
public:   
    Drawable();
    Drawable(std::vector<GLfloat> &_vertices, GLuint _texture, ShaderProgram _shaderProgram);
    
    Drawable(const Drawable& other) = delete;          //to avoid bugs 
    Drawable& operator=(const Drawable& rhs) = delete; //with destructor which destroy still useable VAO and VBO

    ~Drawable();
    virtual void draw();
};

#endif 
