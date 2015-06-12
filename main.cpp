#include <iostream>
#include <GL/glew.h>
#include "display.h"
#include "shader.h"
#include "mesh.h"

#include <fstream>

int main() {
    Display display(800, 600, "Hello World");

    // X: -1 is left of screen, 1 is right of screen
    // Y: 1 is top of screen, -1 is bottom of screen
    Vertex vertices[] = { Vertex(glm::vec3(-0.5,-0.5,0)),
                          Vertex(glm::vec3(0,0.5 ,0)),
                          Vertex(glm::vec3(0.5,-0.5,0))};

    Mesh mesh(vertices, sizeof(vertices)/sizeof(vertices[0])); // vertices and number of vertices


    Shader shader("/Users/samiskin/OpenGL/res/basicShader");

    while (!display.isClosed()) {
        display.clear(0.0f, 0.15f, 0.3f, 1.0f);
        shader.bind();
        mesh.draw();
        display.update();
    }
    return 0;
}