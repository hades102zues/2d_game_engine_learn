#pragma once

#include <string>
#include <glm/glm.hpp>


class Shader {

    unsigned int shaderProgramID;
    char* vertexSource;
    char* fragmentSource;
    char* programIntent;
    bool beingUsed;


    public:
        Shader(char* vShaderPath, char* fShaderPath, std::string intent);
        
        void compileShader();
        void useShader();
        void detachShader();

        void uploadMat4(char* name, glm::mat4 mt);
        void uploadMat3(char* name, glm::mat3 mt);
        void uploadVec4(char* name, glm::vec4 vc);
        void uploadVec3(char* name, glm::vec3 vc);
        void uploadFloat(char* name, GLfloat f);
        void uploadInt (char* name, GLint i);
        
};