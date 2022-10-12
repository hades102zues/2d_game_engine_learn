#include "Camera.hpp"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>


Camera::Camera(glm::vec2 position) {
    m_position = position;
    m_view = glm::mat4(1.0f);
    m_projection = glm::mat4(1.0f);

}

void Camera::adjustProjection() {
    //screen width 0 -> 1280
    //screen height 0 -> 672
    //z-near 0.0f
    //z-far 100.f
    m_projection = glm::ortho(0.0f, 32.0f * 40.0f, 0.0f, 32.0f * 21.0f, 0.0f, 100.0f);
}

glm::mat4 Camera::getViewMatrix() {

    glm::vec3 arbitraryStepFromCamera = glm::vec3(0.0f, 0.0f, -1.0f);
    glm::vec3 arbitraryCameraUp = glm::vec3(0.0f, 1.0f, 0.0f);
    glm::vec3 cameraFront = glm::vec3(m_position.x, m_position.y, 20.0f) + arbitraryStepFromCamera;
    m_view = glm::lookAt(m_position, cameraFront, arbitraryCameraUp);

    return m_view;
}

glm::mat4 Camera::getProjectionMatrix() {
    return m_projection;
}