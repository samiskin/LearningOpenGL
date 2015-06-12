//
// Created by Shiranka Miskin on 6/12/15.
//

#ifndef OPENGL_MESH_H
#define OPENGL_MESH_H


#include<glm/glm.hpp>
#include<GL/glew.h>

class Vertex {
public:
    Vertex(const glm::vec3& pos){ this->pos = pos; }
protected:
private:
    glm::vec3 pos;
};


class Mesh {
public:
    Mesh(Vertex* vertices, unsigned int numVertices);
    void draw();
    virtual ~Mesh();
private:
    Mesh(const Mesh& other) {}
    Mesh& operator=(const Mesh rhs) {}

    enum {
        POSITION_VB,

        NUM_BUFFERS
    };
    GLuint m_vertexArrayObject;
    GLuint m_vertexArrayBuffer[NUM_BUFFERS];
    unsigned int m_drawCount;


};

#endif //OPENGL_MESH_H
