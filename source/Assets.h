#ifndef Assets_h
#define Assets_h

#include "IwGL.h"
#include "Iw2d.h"
#include "vector"
#include "ShaderProgram.h"

class Assets
{
public:
    std::vector<GLfloat> squareVertices;
    const GLchar *vertexShaderCode, *fragmentShaderCode;
    GLuint simpleTexture;
    ShaderProgram shaderProgram2D;

    Assets();
	~Assets();
private:
    GLuint loadTexture(const char* path);
	
};

#endif 
