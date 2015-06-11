cmake_minimum_required(VERSION 3.2)
project(OpenGL)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "~/OpenGL/cmake")
find_package(SDL2 REQUIRED)
find_package(GLEW REQUIRED)
include_directories(${SDL2_INCLUDE_DIR})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -framework OpenGL")



set(SOURCE_FILES main.cpp)
add_executable(OpenGL ${SOURCE_FILES} Display.cpp Display.h)
target_link_libraries(OpenGL ${SDL2_LIBRARY})
