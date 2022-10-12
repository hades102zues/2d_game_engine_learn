#pragma once
#include <glm/glm.hpp>


class Camera {
    glm::mat4 m_view, m_projection;
    glm::vec2 m_position;


    public:
        Camera(glm::vec2 position);
        ~Camera();
        void adjustProjection();
        glm::mat4 getViewMatrix();
        glm::mat4 getProjectionMatrix();
};