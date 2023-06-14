cmake_minimum_required(VERSION 2.8)

project(T4E2)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON CACHE INTERNAL "")
set(QT_USE_QTOPENGL TRUE)

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)
find_package(GLU REQUIRED)

add_executable(T4E2 main.cpp camera.cpp camera.h earth_moon.cpp earth_moon.h)
target_link_libraries(${PROJECT_NAME} ${OPENGL_LIBRARIES} GLU GLUT::GLUT)