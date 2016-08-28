#ifndef Assets_h
#define Assets_h

#include "IwGL.h"
#include "Iw2d.h"
#include "vector"
#include "ShaderProgram.h"

class Assets
{
public:
    std::vector<GLfloat> squareVertices, tetrahedronVertices;
    const GLchar *vertexShader2DCode, *vertexShader3DCode, *fragmentShaderCode;
    GLuint simpleTexture,tetrahedronTexture;
    ShaderProgram shaderProgram2D, shaderProgram3D;

    Assets();
	~Assets();
private:
    GLuint loadTexture(const char* path);
	
};

#endif 
