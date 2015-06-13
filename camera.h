//
// Created by Shiranka Miskin on 6/12/15.
//

#ifndef OPENGL_CAMERA_H
#define OPENGL_CAMERA_H


#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>

class Camera {

public:
    Camera(const glm::vec3& pos, float fov, float aspect, float zNear, float zFar)
    {
        m_perspective = glm::perspective(fov, aspect, zNear, zFar);
        m_position = pos;
        m_forward = glm::vec3(0, 0, 1);
        m_up = glm::vec3(0, 1, 0);
    }


    inline glm::mat4 getViewProjection() const{
        // origin, target to look at, upward target
        return m_perspective * glm::lookAt(m_position, m_position + m_forward, m_position + m_up);
    }

private:
    glm::mat4 m_perspective;
    glm::vec3 m_position;
    glm::vec3 m_forward; // rotation represented by 2 vectors, forward is what direction is forward
    glm::vec3 m_up; // what direction is up for me
};


#endif //OPENGL_CAMERA_H
