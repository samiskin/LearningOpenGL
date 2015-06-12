//
// Created by Shiranka Miskin on 6/12/15.
//

#include <iostream>
#include "mesh.h"
#include <vector>

Mesh::Mesh(Vertex *vertices, unsigned int numVertices) {
    m_drawCount = numVertices;

    glGenVertexArrays(1, &m_vertexArrayObject);
    glBindVertexArray(m_vertexArrayObject);

    std::vector<glm::vec3> positions;
    std::vector<glm::vec2> texCoords;

    positions.reserve(numVertices);
    texCoords.reserve(numVertices);

    for(int i = 0; i < numVertices; i++) {
        positions.push_back(*vertices[i].getPos());
        texCoords.push_back(*vertices[i].getTexCoord());

    }

    glGenBuffers(NUM_BUFFERS, m_vertexArrayBuffer);
    glBindBuffer(GL_ARRAY_BUFFER, m_vertexArrayBuffer[POSITION_VB]);
    glBufferData(GL_ARRAY_BUFFER, numVertices * sizeof(positions[0]), &positions[0], GL_STATIC_DRAW); // tell its an array, put all of the vertex data into the array

    // vertex attribute arrays tell the GPU how to interpret its information to get the vertexes, ex: if you have position and color stored in each vertex, need to tell GPU to read pos and skip the color to get to the next vertex
    glEnableVertexAttribArray(0); // tells openGL that we're goign to tell it how to read an attribute as an array
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0); // tell it which attribuArray we're describing, number of data objects, type of data, whether we want it to normalize (rarely used), our data is continuous attribute array so starts at 0, and skip 0)


    glBindBuffer(GL_ARRAY_BUFFER, m_vertexArrayBuffer[TEXCOORD_VB]);
    glBufferData(GL_ARRAY_BUFFER, numVertices * sizeof(texCoords[0]), &texCoords[0], GL_STATIC_DRAW);

    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, 0);

    glBindVertexArray(0);
}

Mesh::~Mesh() {
    glDeleteVertexArrays(1, &m_vertexArrayObject);
}

void Mesh::draw() {
    glBindVertexArray(m_vertexArrayObject);

    glDrawArrays(GL_TRIANGLES, 0, m_drawCount); // tell how to draw the data, where to start reading from in the data, when to end so draw all the data in the buffer

    glBindVertexArray(0);

}

