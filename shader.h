//
// Created by Shiranka Miskin on 6/11/15.
//

#ifndef OPENGL_SHADER_H
#define OPENGL_SHADER_H

#include <string>
#include <GL/glew.h>

class Shader {
public:
    Shader(const std::string& fileName);
    void bind();
    virtual ~Shader();
private:
    static const unsigned int NUM_SHADERS = 2;
    Shader(const Shader& other) {}
    Shader& operator=(const Shader rhs) {}

    GLuint m_program;
    GLuint m_shaders[NUM_SHADERS]; // 0-vertex, 1-fragment

};


#endif //OPENGL_SHADER_H
