#include <iostream>
#include <GL/glew.h>
#include "display.h"
#include "shader.h"
#include "mesh.h"
#include "texture.h"

#include <fstream>

int main() {

    std::string resFolder = "/Users/samiskin/OpenGL/res/";

    Display display(800, 600, "Hello World");

    // X: -1 is left of screen, 1 is right of screen
    // Y: 1 is top of screen, -1 is bottom of screen
    Vertex vertices[] = { Vertex(glm::vec3(-0.5, -0.5, 0), glm::vec2(0.0,0.0)),
                          Vertex(glm::vec3(0,0.5 ,0), glm::vec2(0.5, 1.0)),
                          Vertex(glm::vec3(0.5, -0.5,0), glm::vec2(1.0, 0.0))};

    Mesh mesh(vertices, sizeof(vertices)/sizeof(vertices[0])); // vertices and number of vertices


    Shader shader(resFolder + "basicShader");
    Texture texture(resFolder + "bricks.jpg");

    while (!display.isClosed()) {
        display.clear(0.0f, 0.15f, 0.3f, 1.0f);
        shader.bind();
        texture.bind(0);
        mesh.draw();
        display.update();
    }
    return 0;
}