#pragma once
#include <glm/glm.hpp>


class Camera {
    glm::mat4 m_view, m_projection;
    glm::vec2 m_position;


    public:
        Camera(glm::vec2 position);
        ~Camera();
        glm::mat4 getViewMatrix();
        void adjustProjection(int width, int height);
        glm::mat4 getProjectionMatrix(int width, int height);
};