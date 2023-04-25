//
// Created by sophie on 24/04/23.
//

#include <GL/glut.h>
#include "keyboard_mouse_handler.h"
#include "figures.h"

void handle_KeyboardFunc(GLubyte key, GLint x, GLint y) {
    GLint m = glutGetModifiers();

    switch (key) {
        case 27:
            exit(0);
            break;
        case 'D':
            limpa_tela();
            glFlush();
            break;
    }
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
    draw_point(x, y);
    glFlush();
}
