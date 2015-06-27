//
// Created by Shiranka Miskin on 6/12/15.
//

#ifndef OPENGL_TRANSFORM_H
#define OPENGL_TRANSFORM_H


#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>


class Transform {
public:
    Transform(const glm::vec3 &pos = glm::vec3(), const glm::vec3 &rot = glm::vec3(), const glm::vec3 &scale = glm::vec3(1.0f, 1.0f, 1.0f)):
            m_pos(pos), m_rot(rot), m_scale(scale) {}

    // pos+rot+scale is usually called Model Matrix
    glm::mat4 getModel() const;

    inline glm::vec3& getPos() { return m_pos; }
    inline glm::vec3& getRot() { return m_rot; }
    inline glm::vec3& getScale() { return m_scale; }

    inline void setPos(const glm::vec3 &pos) { m_pos = pos; }
    inline void setRot(const glm::vec3 &rot) { m_rot = rot; }
    inline void setScale(const glm::vec3 &scale) { m_scale = scale; }

protected:
private:
    glm::vec3 m_pos;
    glm::vec3 m_rot; // represent not as angle, since you can have gimblelock where some rotations are impossible
                     // recommended to rotate using quaternions
    glm::vec3 m_scale;


};


#endif //OPENGL_TRANSFORM_H
