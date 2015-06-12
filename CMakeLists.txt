cmake_minimum_required(VERSION 3.2)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "~/OpenGL/cmake")
project(OpenGL)

if(APPLE)
    include_directories(/System/Library/Frameworks)
    find_library(GLEW_LIBRARY GLEW)
    find_library(OpenGL_LIBRARY OpenGL)
    mark_as_advanced(GLEW_LIBRARY OpenGL_LIBRARY)
endif()


find_package(SDL2 REQUIRED)
find_package(GLEW REQUIRED)
if (GLEW_FOUND)
    include_directories(${GLEW_INCLUDE_DIRS})
    link_libraries(${GLEW_LIBRARIES})
endif()
include_directories(${SDL2_INCLUDE_DIR})
include_directories(./res)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -framework OpenGL")



set(SOURCE_FILES main.cpp)
add_executable(OpenGL ${SOURCE_FILES} display.cpp display.h shader.cpp shader.h res/basicShader.vs res/basicShader.fs mesh.cpp mesh.h)
target_link_libraries(OpenGL ${SDL2_LIBRARY})
