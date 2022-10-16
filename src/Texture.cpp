#include <glad/glad.h>
#include "Texture.hpp"
#include <iostream>
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"



Texture::Texture(char* path) {

    unsigned int texture;
    glGenTextures(1, &texture);
    m_texID = texture;
    m_filePath = path;

    // load and generate the texture
    int width, height, nrComponents;
    //stbi_set_flip_vertically_on_load(true);
    unsigned char *data = stbi_load(path, &width, &height, &nrComponents, 0);
	if (data) {
        GLenum format;

        //checks for rgba format
        if (nrComponents == 1)
            format = GL_RED;
        else if (nrComponents == 3)
            format = GL_RGB;
        else if (nrComponents == 4)
            format = GL_RGBA;

        glBindTexture(GL_TEXTURE_2D, texture);
        glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

        stbi_image_free(data);
	}
	else {
        std::cout << "Texture failed to load at path: " << path << std::endl;
        stbi_image_free(data);
	}
}


void Texture::use() {
    glBindTexture(GL_TEXTURE_2D, m_texID);
}

void Texture::detach() {
    glBindTexture(GL_TEXTURE_2D, 0);
}