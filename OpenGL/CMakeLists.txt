cmake_minimum_required(VERSION 2.8)

project(OpenGL)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON CACHE INTERNAL "")
set(QT_USE_QTOPENGL TRUE)

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)
find_package(GLU REQUIRED)

add_executable(OpenGL main.cpp)
target_link_libraries(${PROJECT_NAME} ${OPENGL_LIBRARIES} GLU GLUT::GLUT)