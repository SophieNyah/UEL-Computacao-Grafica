cmake_minimum_required(VERSION 2.8)

project(T4E3)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON CACHE INTERNAL "")
set(QT_USE_QTOPENGL TRUE)

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)
find_package(GLU REQUIRED)

add_executable(T4E3 main.cpp keyboard_mouse_handler.cpp keyboard_mouse_handler.h labyrinth.cpp labyrinth.h)
target_link_libraries(${PROJECT_NAME} ${OPENGL_LIBRARIES} GLU GLUT::GLUT)