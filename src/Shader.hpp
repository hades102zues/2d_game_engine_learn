#pragma once
#include <string>


class Shader {

    unsigned int shaderProgramID;
    char* vertexSource;
    char* fragmentSource;
    char* programIntent;


    public:
        Shader(char* vShaderPath, char* fShaderPath, std::string intent);
        
        void compileShader();
        void useShader();
        void detachShader();
};