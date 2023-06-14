#define GL_SILENCE_DEPRECATION
#include <iostream>
#include <math.h>
#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "camera.h"
#include "keyboard_mouse_handler.h"

void init(void) {
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f); //define a cor de fundo
    Cam::initialize();
}

void drawCube() {
    glColor3f(1.0,0.0,0.0);
    glBegin (GL_POLYGON);
        glVertex3f(-0.5,-0.5,0.5);
        glVertex3f(0.5,-0.5,0.5);
        glVertex3f(0.5,0.5,0.5);
        glVertex3f(-0.5,0.5,0.5);
    glEnd();
    glColor3f(0.0,1.0,0.0);
    glBegin(GL_POLYGON);
        glVertex3f(0.5,0.5,0.5);
        glVertex3f(0.5,-0.5,0.5);
        glVertex3f(0.5,-0.5,-0.5);
        glVertex3f(0.5,0.5,-0.5);
    glEnd ();
    glColor3f(0.0,0.0,1.0);
    glBegin(GL_POLYGON);
        glVertex3f(0.5,-0.5,0.5);
        glVertex3f(-0.5,-0.5,0.5);
        glVertex3f(-0.5,-0.5,-0.5);
        glVertex3f(0.5,-0.5,-0.5);
    glEnd();
    glColor3f(1.0,1.0,0.0);
    glBegin(GL_POLYGON);
        glVertex3f(-0.5,0.5,0.5);
        glVertex3f(0.5,0.5,0.5);
        glVertex3f(0.5,0.5,-0.5);
        glVertex3f(-0.5,0.5,-0.5);
    glEnd();
    glColor3f (0.0,1.0,1.0);
    glBegin (GL_POLYGON);
        glVertex3f(-0.5,-0.5,-0.5);
        glVertex3f(-0.5,0.5,-0.5);
        glVertex3f(0.5,0.5,-0.5);
        glVertex3f(0.5,-0.5,-0.5);
    glEnd();
    glColor3f(1.0,1.0,1.0);
    glBegin (GL_POLYGON);
        glVertex3f(-0.5,0.5,-0.5);
        glVertex3f(-0.5,-0.5,-0.5);
        glVertex3f(-0.5,-0.5,0.5);
        glVertex3f(-0.5,0.5,0.5);
    glEnd();
}

void display(void) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    drawCube();
    glutSwapBuffers();
}

int main(int argc, char**argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowPosition(50, 100);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Viewing 3D");
    glutDisplayFunc(display);
    glutKeyboardFunc(handle_KeyboardFunc);
    glutSpecialFunc(handle_specialFunc);
    init();
    glutMainLoop();

    return EXIT_SUCCESS;
}
