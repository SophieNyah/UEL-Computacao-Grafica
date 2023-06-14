//
// Created by sophie on 13/06/23.
//

#include <cmath>
#include <iostream>
#include "earth_moon.h"

struct {
    const GLfloat radius = 0.2;
} Earth;

struct {
    GLfloat distance_from_earth = 0.6;
    const GLfloat radius = 0.05;
} Moon;

void Space::draw_earth() {
    static GLfloat rotation = 5;

    glPushMatrix();
        glColor3f(0.0,1.0,0.4);
        glLoadIdentity();
        glRotatef(rotation, 0.0, 0.15, 1.0);
        glutWireSphere(Earth.radius, 15, 15);
    glPopMatrix();

    rotation += 0.8;
}

void Space::draw_moon() {
    static GLfloat angle_rotation = 0;
    GLfloat x = Moon.distance_from_earth * std::cos(angle_rotation);
    GLfloat y = Moon.distance_from_earth * std::sin(angle_rotation);

    glPushMatrix();
        glColor3f(1.0,1.0,1.0);
        glTranslatef(x, y, 0.0);
        glutWireSphere(Moon.radius, 20, 20);
    glPopMatrix();

    angle_rotation -= 0.04;
}
