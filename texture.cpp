//
// Created by Shiranka Miskin on 6/12/15.
//

#include "texture.h"
#include "stb_image.h"
#include <cassert>
#include <iostream>

Texture::Texture(const std::string &fileName) {
    int width, height, numComponents;
    unsigned char* imageData = stbi_load(fileName.c_str(), &width, &height, &numComponents, 4); // 4 is required components
    if (imageData == NULL)
        std::cerr << "Texture loading failed for texture: " << fileName << std::endl;




    glGenTextures(1, &m_texture); // space for 1 texture
    glBindTexture(GL_TEXTURE_2D, m_texture);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT); // controls texture wrapping, ex: read pixel 543 on a 500 width image
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT); // separaet for x and y

    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR); // for minification, if texture takes up fewer pixels than resolution.  GL_LINEAR = linearly interpolate
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR); // for magnification, linear extrapolation

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, imageData); // type, level(for multiple images for dif resolution), colorformat, width of tex, height of tex, border, format to load it as, image data


    stbi_image_free(imageData);
}

Texture::~Texture() {
    glDeleteTextures(1, &m_texture); // delete 1 texture at address
}

void Texture::bind(unsigned int unit) {
    assert(unit >= 0 && unit <= 31);
    glActiveTexture(GL_TEXTURE0 + unit); // change which texture openGL is working with, can add unit since enum placed sequentially
    glBindTexture(GL_TEXTURE_2D, m_texture);
}
