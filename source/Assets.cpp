#include "Assets.h"

Assets::Assets(){
    squareVertices = {
        // Positions       // Texture Coords
         1.0f,  1.0f, 0.0f,  1.0f, 1.0f,   // Top Right
         1.0f, -1.0f, 0.0f,  1.0f, 0.0f,   // Bottom Right
        -1.0f, -1.0f, 0.0f,  0.0f, 0.0f,   // Bottom Left

         1.0f,  1.0f, 0.0f,  1.0f, 1.0f,   // Top Right
        -1.0f, -1.0f, 0.0f,  0.0f, 0.0f,   // Bottom Left
        -1.0f,  1.0f, 0.0f,  0.0f, 1.0f    // Top Left 
    };

    tetrahedronVertices = {
        1.0f, 1.0f, 1.0f,   0.0f, 0.0f,
        -1.0f, 1.0f, -1.0f, 1.0f, 0.0f,
        1.0f, -1.0f, -1.0f, 1.0f, 1.0f,

        1.0f, 1.0f, 1.0f, 0.0f, 0.0f,
        -1.0f, 1.0f, -1.0f, 1.0f, 0.0f,
        -1.0f, -1.0f, 1.0f, 1.0f, 1.0f,

        1.0f, 1.0f, 1.0f, 0.0f, 0.0f,
        1.0f, -1.0f, -1.0f, 1.0f, 0.0f,
        -1.0f, -1.0f, 1.0f, 1.0f, 1.0f,
    
        -1.0f, 1.0f, -1.0f, 0.0f, 0.0f,
        1.0f, -1.0f, -1.0f, 1.0f, 0.0f,
        -1.0f, -1.0f, 1.0f, 1.0f, 1.0f,
    };

    vertexShader2DCode = "#version 300 es\n"
        "layout(location = 0) in vec3 position;"
        "layout(location = 1) in vec2 texCoord;"

        "out vec2 TexCoord;"

        "uniform mat4 model;"
        "void main(){"
            "gl_Position = model * vec4(position, 1.0f);"
            "TexCoord = vec2(texCoord.x, texCoord.y);"
        "}";

    vertexShader3DCode = "#version 300 es\n"
        "layout(location = 0) in vec3 position;"
        "layout(location = 1) in vec2 texCoord;"

        "out vec2 TexCoord;"

        "uniform mat4 model;"
        "uniform mat4 view;"
        "uniform mat4 projection;"
        "void main(){"
        "gl_Position = projection * view * model * vec4(position, 1.0f);"
        "TexCoord = vec2(texCoord.x, texCoord.y);"
        "}";
    fragmentShaderCode = "#version 300 es\n"
        "in highp vec2 TexCoord;"

        "out highp vec4 color;"

        "uniform sampler2D textureUniform;"

        "void main(){"
            "color = texture(textureUniform, TexCoord);"
        "}";

    simpleTexture = loadTexture("container.jpg");
    tetrahedronTexture = loadTexture("tetrahedronTexture2.png");

    shaderProgram2D = ShaderProgram(vertexShader2DCode,fragmentShaderCode);
    shaderProgram3D = ShaderProgram(vertexShader3DCode, fragmentShaderCode);
}
Assets::~Assets() {
    glDeleteTextures(1, &simpleTexture);
    glDeleteTextures(1, &tetrahedronTexture);
}

GLuint Assets::loadTexture(const char* path) {
    GLuint texture;
    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);

    CIwImage* pImage = new CIwImage;
    pImage->LoadFromFile(path);
    // Convert the image data to RGBA4444 format
    CIwImage* image = new CIwImage;
    image->SetFormat(CIwImage::RGBA_4444);
    pImage->ConvertToImage(image);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	// Set texture wrapping to GL_REPEAT (usually basic wrapping method)
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    // Set texture filtering parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    // Load image, create texture and generate mipmaps
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, image->GetWidth(), image->GetHeight(), 0, GL_RGBA, GL_UNSIGNED_SHORT_4_4_4_4, image->GetTexels());
    glGenerateMipmap(GL_TEXTURE_2D);

    delete image;
    delete pImage;

    return texture;
}