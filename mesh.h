//
// Created by Shiranka Miskin on 6/12/15.
//

#ifndef OPENGL_MESH_H
#define OPENGL_MESH_H


#include<glm/glm.hpp>
#include "obj_loader.h"
#include<GL/glew.h>

class Vertex {
public:
    Vertex(const glm::vec3& pos, const glm::vec2& texCoord, const glm::vec3& normal = glm::vec3(0, 0, 0))
    {
        this->pos = pos;
        this->texCoord = texCoord;
        this->normal = normal;
    }
    inline glm::vec3* getPos() { return &pos; }
    inline glm::vec2* getTexCoord() { return &texCoord; }
    inline glm::vec3* getNormal() { return &normal; }

protected:
private:
    glm::vec3 pos;
    glm::vec2 texCoord;
    glm::vec3 normal;
};


class Mesh {
public:
    Mesh(Vertex* vertices, unsigned int numVertices, unsigned int* indices, unsigned int numIndices);
    Mesh(const std::string& fileName);
    void draw();
    virtual ~Mesh();
private:
    Mesh(const Mesh& other) {}
    Mesh& operator=(const Mesh rhs) {}

    void initMesh(const IndexedModel& model);

    enum {
        POSITION_VB,
        TEXCOORD_VB,
        INDEX_VB,
        NORMAL_VB,
        NUM_BUFFERS
    };
    GLuint m_vertexArrayObject;
    GLuint m_vertexArrayBuffer[NUM_BUFFERS];
    unsigned int m_drawCount;


};

#endif //OPENGL_MESH_H
