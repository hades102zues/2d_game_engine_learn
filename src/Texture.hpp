#pragma once



class Texture {

    public:
        char* m_filePath;
        unsigned int m_texID;
        Texture(char* path);
        ~Texture();
        void use();
        void detach();

};