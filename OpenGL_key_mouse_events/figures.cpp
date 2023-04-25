//
// Created by sophie on 24/04/23.
//

#include "figures.h"
#include <GL/glut.h>

void draw_rectangle(int x1, int y1, int width, int height, std::optional<Color> color) {
    if(color.has_value()) {
        Color c = color.value();
        glColor3f(c.red, c.green, c.blue);
    }
    glBegin(GL_TRIANGLE_STRIP);
        glVertex2i(x1,       y1);
        glVertex2i(x1,       y1+height);
        glVertex2i(x1+width, y1+height);
        glVertex2i(x1+width, y1);
        glVertex2i(x1,       y1);
    glEnd();
}

void draw_triangle(int x1, int y1, int x2, int y2, int x3, int y3, std::optional<Color> color) {
    if(color.has_value()) {
        Color c = color.value();
        glColor3f(c.red, c.green, c.blue);
    }
    glBegin(GL_TRIANGLES);
        glVertex2i(x1, y1);
        glVertex2i(x2, y2);
        glVertex2i(x3, y3);
    glEnd();
}

void draw_point(GLint x, GLint y, std::optional<Color> color) {
    if(color.has_value()) {
        Color c = color.value();
        glColor3f(c.red, c.green, c.blue);
    }
    glBegin(GL_POINTS);
        glVertex2i(x, y);
    glEnd();
}

void limpa_tela() {
    glClear(GL_COLOR_BUFFER_BIT);
}

void set_color(Color cor) {
    glColor3f(cor.red, cor.green, cor.blue);
}

void set_thickness(GLfloat t) {
    glPointSize(t);
}
