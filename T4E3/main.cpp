//
// Created by sophie on 24/04/23.
//

#include <GL/glut.h>
#include "keyboard_mouse_handler.h"
#include "labyrinth.h"

void myInit(void);
void myDisplay(void);

int main(int argc, char* argv[]) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Labirinto");
    myInit();
    glutDisplayFunc(Labyrinth::draw);
    glClear(GL_COLOR_BUFFER_BIT);

    glutKeyboardFunc(handle_KeyboardFunc);
    glutPassiveMotionFunc(handle_PassiveMotion);

    glutMainLoop();
    return 0;
}

void myInit(void) {
    glClearColor(0.0,0.0,0.0,0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluOrtho2D(0.0, 640.0, 480.0, 0.0);
}

void myDisplay(void) {
//    glClear(GL_COLOR_BUFFER_BIT); // limpa a janela
//    const int yBase = 100;
//    const int xBase = 200;
//    const int houseWidth = 150;
//    const int houseHeight = houseWidth - 30;
//    draw_rectangle(xBase, yBase, houseWidth, houseHeight, {grey});
//    draw_rectangle(xBase + 35, yBase, 30, 60, {blue});
//    draw_rectangle(xBase + 80, yBase + 30, 50, 50, {blue});
//    draw_rectangle(xBase + 20, yBase + houseHeight, 20, 75, {brown});
//    draw_triangle(
//            xBase,                  yBase + houseHeight,
//            xBase + houseWidth,      yBase + houseHeight,
//            xBase + (houseWidth/2), yBase + houseHeight + 60,
//            {orange}
//    );

    glFlush(); // Garante a execução de todas as rotinas de desenho
}
