#include "Camera.hpp"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <iostream>


Camera::Camera(glm::vec2 position) {
    m_position = position;
    m_view = glm::mat4(1.0f);
    m_projection = glm::mat4(1.0f);
    //this->adjustProjection();

}

void Camera::adjustProjection(int width, int height) {
    //0, screen width, 0, screen height, z-near, z-far
    m_projection = glm::ortho(0.0f, (float)width, 0.0f, (float)height, 0.0f, 100.0f);
    
}

glm::mat4 Camera::getViewMatrix() {


    // I do not know how to appropriately define the default poition of the camera
    // I do not know how to appropriately define the centre for the camera
    // The center should always make the camera point down the -z-axis
    glm::vec3 arbitraryStepFromCamera = glm::vec3(0.0f, 0.0f, -1.0f);
    glm::vec3 arbitraryCameraUp = glm::vec3(0.0f, 1.0f, 0.0f);
    glm::vec3 cameraPos3D = glm::vec3(m_position.x, m_position.y, 1.0f);
    glm::vec3 cameraFront = cameraPos3D + arbitraryStepFromCamera; 
    
    // each of the vectors must be normalized.
    // i.e have a length of 1
    m_view = glm::lookAt(cameraPos3D, cameraFront, arbitraryCameraUp);
    

    return m_view;
}

glm::mat4 Camera::getProjectionMatrix(int width, int height) {
    this->adjustProjection(width, height);
    return m_projection;
}