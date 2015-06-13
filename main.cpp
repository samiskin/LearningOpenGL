#include <iostream>
#include <GL/glew.h>
#include "display.h"
#include "shader.h"
#include "mesh.h"
#include "texture.h"
#include "transform.h"
#include "camera.h"

#define WIDTH 800
#define HEIGHT 600

#include <fstream>

int main() {

    std::string resFolder = "/Users/samiskin/OpenGL/res/";

    Display display(WIDTH, HEIGHT, "Hello World");

    // X: -1 is left of screen, 1 is right of screen
    // Y: 1 is top of screen, -1 is bottom of screen
    Vertex vertices[] = { Vertex(glm::vec3(-0.5, -0.5, 0), glm::vec2(0.0, 0.0)),
                          Vertex(glm::vec3(   0,  0.5, 0), glm::vec2(0.5, 1.0)),
                          Vertex(glm::vec3( 0.5, -0.5, 0), glm::vec2(1.0, 0.0))};

    unsigned int indices[] = {0, 1, 2};
    Mesh mesh(vertices, sizeof(vertices)/sizeof(vertices[0]), indices, sizeof(indices)/sizeof(indices[0])); // vertices and number of vertices
    Mesh monkey(resFolder + "monkey3.obj");


    Shader shader(resFolder + "basicShader");
    Texture texture(resFolder + "bricks.jpg");
    Transform transform;
    Camera camera(glm::vec3(0, 0, -4), 70.0f, (float)WIDTH/(float)HEIGHT, 0.01f, 1000.0f); // don't want to set too far apart otherwise floating point precision errors

    float counter = 0.0f;
    while (!display.isClosed()) {
        display.clear(0.0f, 0.15f, 0.3f, 1.0f);

        float sinCounter = sinf(counter);
        float cosCounter = cosf(counter);

        transform.getPos().x = sinCounter;
        transform.getPos().y = cosCounter;
        transform.getPos().z = cosCounter;
        transform.getRot().z = counter;
        transform.getRot().y = counter;
        //transform.setScale(glm::vec3(cosCounter, cosCounter, cosCounter));

        shader.bind();
        texture.bind(0);
        shader.update(transform, camera);
        monkey.draw();
        display.update();
        counter += 0.01f;
    }
    return 0;
}