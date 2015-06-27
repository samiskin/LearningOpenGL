//
// Created by Shiranka Miskin on 6/12/15.
//

#ifndef OPENGL_TEXTURE_H
#define OPENGL_TEXTURE_H

#include <string>
#include <GL/glew.h>

class Texture {
public:
    Texture(const std::string& fileName);
    void bind(unsigned int unit); // you can bind multiple texture at once, up to 32, so must distinguish between which texture using the unit
    virtual ~Texture();
private:
    Texture(const Texture& other) {}
    Texture& operator=(const Texture rhs) {}

    GLuint m_texture;
};


#endif //OPENGL_TEXTURE_H
