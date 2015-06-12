# LearningOpenGL
A record of me learning to develop an OpenGL application (working on my Macbook Pro)


##Day 1
Began with following tutorials by thebennybox on Youtube: https://www.youtube.com/playlist?list=PLEETnX-uPtBXT9T-hD0Bj31DSnwio-ywh

Installed Jetbrains CLion since I like the Jetbrains Vim plugin which can source your .vimrc (I like using jk as an escape sequence but thats sometimes annoying with other IDEs Vim plugins)

Installed GLEW
  - Tried to install using the git links given in http://glew.sourceforge.net/ however they seemed to be lacking some files so running `make` didn't work.  
  - Got it to work by downloading by downloading the folder from their direct link to the source file and navigating to the folder then running 
```bash
  make
  sudo make install
  make clean
```

Realized I could use brew

Installed GLM (Mathematics library for OpenGL)
  - ran `brew install glm`

Installed SDL2
  - ran `brew install sdl2`

Created the code following the tutorials up to video 3

Had issues with linking with the GL libraries.
  - Ended up using https://github.com/tcbrindle/sdl2-cmake-scripts
  - Added the lines seen in `CMakeLists.txt` and everything except glInit() seemed to work
  - After some googling, found out that OSX doesn't need to call glInit(), so doing the following resulted it in compiling and showing a window!
```cpp
ifndef __APPLE__
GLenum status = glewInit();
if (status != GLEW_OK) {
  std::cerr << "Glew failed to initialize!" << std::endl;
}
#endif
```
    
