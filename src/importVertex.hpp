#include <iostream>
#include <fstream>
#include <sstream>
#include <string>



char* readFromShaderFile(char* path, char* intent) {
    std::ifstream fStream;
    std::sstream  sStream;
    std::string mString;


    fStream.exceptions(std::ifstream::badbit | std::ifstream::failbit);

    try {
        fStream.open(path);
        sStream << fStream.rdbuf();
        mString = sStream.str();

    }
    catch (std::ifstream::failure e) {
        std::cout << "ERROR_READING_SHADER_SOURCE: " << intent << std::endl;

    }

    return mString.c_str();

}