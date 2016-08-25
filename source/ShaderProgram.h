#ifndef ShaderProgram_h
#define ShaderProgram_h

#include "IwGL.h"
#include "iostream"

//based on Shader class from learnopengl tutorial
class ShaderProgram {
private:
    GLuint shaderProgram;
public :
    ShaderProgram() {};
    ShaderProgram(const GLchar* vertexShaderPath, const GLchar* fragmentShaderPath);
    void Use();
    GLuint getProgram();
};


#endif 
