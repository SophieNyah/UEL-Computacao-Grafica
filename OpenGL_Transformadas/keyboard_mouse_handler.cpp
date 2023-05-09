//
// Created by sophie on 24/04/23.
//

#include <GL/glut.h>
#include <iostream>
#include "keyboard_mouse_handler.h"
#include "figures.h"

int currentCenterX = 320;
int currentCenterY = 240;

void handle_KeyboardFunc(GLubyte key, GLint x, GLint y) {
    GLint m = glutGetModifiers();

    switch (key) {
        case 27:
            exit(0);
            break;
        case 'A':
        case 'a':
            glTranslated(currentCenterX, currentCenterY, 0);
            std::cout << currentCenterX << " " << currentCenterY << "\n";
            glRotated(-15, 0, 0, 1);
            glTranslated(-currentCenterX, -currentCenterY, 0);
            break;
        case 'D':
        case 'd':
            glTranslated(currentCenterX, currentCenterY, 0);
            glRotated(15, 0, 0, 1);
            glTranslated(-currentCenterX, -currentCenterY, 0);
            break;
        case 'W':
        case 'w':
            glTranslated(currentCenterX, currentCenterY, 0);
            glScaled(1.2, 1.2, 1);
            glTranslated(-currentCenterX, -currentCenterY, 0);
            break;
        case 'S':
        case 's':
            glTranslated(currentCenterX, currentCenterY, 0);
            glScaled(0.8, 0.8, 1);
            glTranslated(-currentCenterX, -currentCenterY, 0);
            break;
    }

    limpa_tela();
    draw_default_rectangle();
    glFlush();
}

void handle_specialFunc(GLint key, GLint x, GLint y) {
    GLint m = glutGetModifiers();

    switch (key) {
        case GLUT_KEY_LEFT:
            glTranslated(-10, 0, 0);
            currentCenterX -= 10;
            break;
        case GLUT_KEY_RIGHT:
            glTranslated(10, 0, 0);
            currentCenterX += 10;
            break;
        case GLUT_KEY_UP:
            glTranslated(0, -10, 0);
            currentCenterY -= 10;
            break;
        case GLUT_KEY_DOWN:
            glTranslated(0, 10, 0);
            currentCenterY += 10;
            break;
    }

    limpa_tela();
    draw_default_rectangle();
    glFlush();
}

void handle_MouseFunc(GLint button, GLint action, GLint x, GLint y) {
//    if(button == GLUT_LEFT_BUTTON && action == GLUT_DOWN) {
//        draw_point(x, y);
//        glFlush();
//    }
}

void handle_PassiveMotion(GLint x, GLint y) {

}

void handle_motion(GLint x, GLint y) {
//    draw_point(x, y);
//    glFlush();
}
