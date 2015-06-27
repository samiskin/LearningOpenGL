//
// Created by Shiranka Miskin on 6/12/15.
//

#include <iostream>
#include "mesh.h"
#include <vector>


Mesh::Mesh(const std::string& fileName) {
    initMesh(OBJModel(fileName).toIndexedModel());
}


Mesh::Mesh(Vertex* vertices, unsigned int numVertices, unsigned int* indices, unsigned int numIndices) {

    IndexedModel model;

    for(int i = 0; i < numVertices; i++) {
        model.positions.push_back(*vertices[i].getPos());
        model.texCoords.push_back(*vertices[i].getTexCoord());
        model.normals.push_back(*vertices[i].getNormal());
    }

    for (unsigned int i = 0; i < numIndices; i++) {
        model.indices.push_back(indices[i]);
    }

    initMesh(model);


}

void Mesh::initMesh(const IndexedModel &model) {
    m_drawCount = model.indices.size();

    glGenVertexArrays(1, &m_vertexArrayObject);
    glBindVertexArray(m_vertexArrayObject);

    glGenBuffers(NUM_BUFFERS, m_vertexArrayBuffer);
    glBindBuffer(GL_ARRAY_BUFFER, m_vertexArrayBuffer[POSITION_VB]);
    glBufferData(GL_ARRAY_BUFFER, model.positions.size() * sizeof(model.positions[0]), &model.positions[0], GL_STATIC_DRAW); // tell its an array, put all of the vertex data into the array

    // vertex attribute arrays tell the GPU how to interpret its information to get the vertexes, ex: if you have position and color stored in each vertex, need to tell GPU to read pos and skip the color to get to the next vertex
    glEnableVertexAttribArray(0); // tells openGL that we're goign to tell it how to read an attribute as an array
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0); // tell it which attribuArray we're describing, number of data objects, type of data, whether we want it to normalize (rarely used), our data is continuous attribute array so starts at 0, and skip 0)


    glBindBuffer(GL_ARRAY_BUFFER, m_vertexArrayBuffer[TEXCOORD_VB]);
    glBufferData(GL_ARRAY_BUFFER, model.positions.size() * sizeof(model.texCoords[0]), &model.texCoords[0], GL_STATIC_DRAW);

    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, 0);

    glBindBuffer(GL_ARRAY_BUFFER, m_vertexArrayBuffer[NORMAL_VB]);
    glBufferData(GL_ARRAY_BUFFER, model.normals.size() * sizeof(model.normals[0]), &model.positions[0], GL_STATIC_DRAW); // tell its an array, put all of the vertex data into the array

    glEnableVertexAttribArray(2);
    glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 0, 0);

    // going to reference elements in another array
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_vertexArrayBuffer[INDEX_VB]);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, model.indices.size() * sizeof(model.indices[0]), &model.indices[0], GL_STATIC_DRAW);


    glBindVertexArray(0);
}

Mesh::~Mesh() {
    glDeleteVertexArrays(1, &m_vertexArrayObject);
}

void Mesh::draw() {
    glBindVertexArray(m_vertexArrayObject);

    //glDrawArrays(GL_TRIANGLES, 0, m_drawCount); // tell how to draw the data, where to start reading from in the data, when to end so draw all the data in the buffer
    glDrawElements(GL_TRIANGLES, m_drawCount, GL_UNSIGNED_INT, 0);

    glBindVertexArray(0);

}

