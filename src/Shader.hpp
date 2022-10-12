#pragma once
#include <string>
#include <glm/glm.hpp>


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

        void uploadMat4f(char* name, glm::mat4 mt);
        void uploadVec3f(char* name, glm::vec3 vc);
        
};