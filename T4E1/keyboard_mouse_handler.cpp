//
// Created by sophie on 24/04/23.
//

#include <iostream>
#include "keyboard_mouse_handler.h"
#include "camera.h"

void handle_KeyboardFunc(GLubyte key, GLint x, GLint y) {
    switch (key) {
        case 27:
            exit(0);
            break;
    }
    glFlush();
}

void handle_specialFunc(GLint key, GLint x, GLint y) {
    switch (key) {
        case GLUT_KEY_LEFT:
            Cam::move(-1, 0);
            break;
        case GLUT_KEY_RIGHT:
            Cam::move(1, 0);
            break;
        case GLUT_KEY_UP:
            Cam::zoom(0.3);
            break;
        case GLUT_KEY_DOWN:
            Cam::zoom(-0.3);
            break;
    }

    glutPostRedisplay();
}
