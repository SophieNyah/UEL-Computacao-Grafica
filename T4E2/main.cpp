#define GL_SILENCE_DEPRECATION //necessário incluir apenas no MAC OS
#include <GL/glut.h> //alterar o include da Glut de acordo com seu SO
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "earth_moon.h"
#include "camera.h"

void myDisplay(void);
void timerFunc(int value);

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(150, 150);
    glutCreateWindow("Objetos 3D");

    glutDisplayFunc(myDisplay);

    glutTimerFunc(100, timerFunc, 1);
    glutMainLoop();
}

void myDisplay(void) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    Space::draw_earth();
    Space::draw_moon();

    glutSwapBuffers();
}

void timerFunc(int value) {
    glutPostRedisplay();
    glutTimerFunc(100, timerFunc, 1);
}
