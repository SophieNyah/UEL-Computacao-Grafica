//
// Created by sophie on 14/06/23.
//

#include <vector>
#include <GL/glut.h>
#include <iostream>
#include "labyrinth.h"

struct Rectangle {
    GLint x = 20;
    GLint y = 20;
    GLint w = 20;
    GLint h = 20;
};

const std::vector<Rectangle> Path{
        {},
        {.x=20,  .y=20,  .h=260},
        {.x=20,  .y=260, .w=180},
        {.x=180, .y=80,  .h=180},
        {.x=180, .y=80,  .w=120},
        {.x=280, .y=80,  .h=300},
        {.x=280, .y=380, .w=60},
        {.x=320, .y=200, .h=200},
        {.x=320, .y=200, .w=340}
};

void Labyrinth::draw() {
    glColor3f(1.0, 1.0, 1.0);
    for(int i=1; i<Path.size(); i++) {
        glBegin(GL_POLYGON);
            glVertex2i(Path[i].x, Path[i].y);
            glVertex2i(Path[i].x + Path[i].w, Path[i].y);
            glVertex2i(Path[i].x + Path[i].w, Path[i].y + Path[i].h);
            glVertex2i(Path[i].x, Path[i].y + Path[i].h);
        glEnd();
    }
    glColor3f(0.4, 0.4, 1.0);
    glBegin(GL_POLYGON);
        glVertex2i(Path[0].x, Path[0].y);
        glVertex2i(Path[0].x + Path[0].w, Path[0].y);
        glVertex2i(Path[0].x + Path[0].w, Path[0].y + Path[0].h);
        glVertex2i(Path[0].x, Path[0].y + Path[0].h);
    glEnd();

    glFlush();
}

bool is_point_inside_rectangle(Rectangle r, GLint mouse_x, GLint mouse_y) {
    const int tolerance = 3;
    if(
        mouse_x > (r.x - tolerance) &&
        mouse_x < (r.x + r.w + tolerance) &&
        mouse_y > (r.y - tolerance) &&
        mouse_y < (r.y + r.h + tolerance)
    ) {
        return true;
    }
    return false;
}

Labyrinth::State Labyrinth::check_collision(GLint mouse_x, GLint mouse_y) {
    if(is_point_inside_rectangle(Path[0], mouse_x, mouse_y)){
        return State::Win;
    }

    for(int i=1; i<Path.size(); i++) {
        if(is_point_inside_rectangle(Path[i], mouse_x, mouse_y)) {
            return State::Playing;
        }
    }

    return State::Lose;
}

void Labyrinth::win() {
    exit(0);
}

void Labyrinth::lose() {
    glutWarpPointer(630, 210);
}
