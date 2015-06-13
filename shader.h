//
// Created by Shiranka Miskin on 6/11/15.
//

#ifndef OPENGL_SHADER_H
#define OPENGL_SHADER_H

#include <string>
#include <GL/glew.h>
#include "transform.h"
#include "camera.h"

class Shader {
public:
    Shader(const std::string& fileName);
    void bind();
    void update(const Transform& transform, const Camera& camera);
    virtual ~Shader();
private:
    static const unsigned int NUM_SHADERS = 2;
    Shader(const Shader& other) {}
    Shader& operator=(const Shader rhs) {}

    enum {
        TRANSFORM_U,
        NUM_UNIFORMS
    };

    GLuint m_program;
    GLuint m_shaders[NUM_SHADERS]; // 0-vertex, 1-fragment
    GLuint m_uniforms[NUM_UNIFORMS];

};


#endif //OPENGL_SHADER_H
