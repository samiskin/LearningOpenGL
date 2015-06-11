//
// Created by Shiranka Miskin on 6/10/15.
//

#ifndef OPENGL_DISPLAY_H
#define OPENGL_DISPLAY_H

#include<string>
#include<SDL2/SDL.h>
#include <iostream>

class Display {

public:
    Display(int width, int height, const std::string& title);
    void clear(float r, float g, float b, float a);
    void update();
    virtual ~Display();
    bool isClosed();
protected:
private:
    Display(const Display& other) {}
    Display& operator= (const Display& other){}

    SDL_Window* m_window;
    SDL_GLContext m_glContext;
    bool m_isClosed;
};


#endif //OPENGL_DISPLAY_H
