//
// Created by Shiranka Miskin on 6/12/15.
//

#ifndef OPENGL_MESH_H
#define OPENGL_MESH_H


#include<glm/glm.hpp>
#include<GL/glew.h>

class Vertex {
public:
    Vertex(const glm::vec3& pos, const glm::vec2& texCoord)
    {
        this->pos = pos;
        this->texCoord = texCoord;
    }
    inline glm::vec3* getPos() { return &pos; }
    inline glm::vec2* getTexCoord() { return &texCoord; }
protected:
private:
    glm::vec3 pos;
    glm::vec2 texCoord;
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
        TEXCOORD_VB,
        NUM_BUFFERS
    };
    GLuint m_vertexArrayObject;
    GLuint m_vertexArrayBuffer[NUM_BUFFERS];
    unsigned int m_drawCount;


};

#endif //OPENGL_MESH_H
