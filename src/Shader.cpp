#include <glad/glad.h>
#include "Shader.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <string.h>


static char* readFromShaderFile(char* path, std::string intent) {
    std::ifstream fStream;
    std::stringstream  sStream;
    std::string mString;


    fStream.exceptions(std::ifstream::badbit | std::ifstream::failbit);

    try {
        fStream.open(path);
        sStream << fStream.rdbuf();
        mString = sStream.str();


    }
    catch (std::ifstream::failure e) {
        std::cout << "ERROR_READING_SHADER_SOURCE: " << intent << std::endl;
        std::cerr << "Error: " << strerror(errno) <<std::endl;


    }
  
   
    return strdup(mString.c_str());

}


Shader::Shader(char* vShaderPath, char* fShaderPath, std::string intent) {


    this->vertexSource = readFromShaderFile(vShaderPath, intent+"_VSHADER");
    this->fragmentSource = readFromShaderFile(fShaderPath, intent+"_FSHADER");
    this->programIntent = strdup(intent.c_str());
    
}

void Shader::compileShader() {

    unsigned int vertexID, fragmentID;

    vertexID = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexID, 1, &this->vertexSource, NULL);
    glCompileShader(vertexID);

    const int logLength = 512;
    int success;
    char infoLog[512];

    glGetShaderiv(vertexID, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(vertexID, 512, NULL, infoLog);
        std::cout<< this->programIntent <<"_ERROR_SHADER_VERTEX_COMIPILATION\n" << infoLog << std::endl;
    }

    fragmentID = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentID, 1, &this->fragmentSource, NULL);
    glCompileShader(fragmentID);

    glGetShaderiv(fragmentID, GL_COMPILE_STATUS, &success);
    if(!success) {
        glGetShaderInfoLog(fragmentID, 512, NULL, infoLog);
        std::cout<< this->programIntent << "_ERROR_SHADER_VERTEX_COMIPILATION\n" << infoLog << std::endl;
    }

    this->shaderProgramID = glCreateProgram();
    glAttachShader(this->shaderProgramID, vertexID);
    glAttachShader(this->shaderProgramID, fragmentID);
    glLinkProgram(this->shaderProgramID);

    glGetProgramiv(this->shaderProgramID, GL_LINK_STATUS, &success);
     if (!success) {
        glGetProgramInfoLog(vertexID, 512, NULL, infoLog);
        std::cout<< this->programIntent <<"_ERROR_SHADER_PROGRAM_LINKING\n" << infoLog << std::endl;
    }

    glDeleteShader(vertexID);
    glDeleteShader(fragmentID);

}

void Shader::useShader() {
    glUseProgram(this->shaderProgramID);
}

void Shader::detachShader() {
    glUseProgram(0);
}
