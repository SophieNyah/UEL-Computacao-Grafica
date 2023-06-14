//
// Created by sophie on 13/06/23.
//

#include <iostream>
#include "camera.h"

struct {
    GLfloat x = 2.0;
    GLfloat y = 2.5;
    GLfloat z = 2.0;
} Eye;

struct {
    GLfloat x = 0.0;
    GLfloat y = 0.0;
    GLfloat z = 0.0;
} Reference;

struct {
    GLfloat x = 0.0;
    GLfloat y = 1.0;
    GLfloat z = 0.0;
} ViewUp;

struct {
    GLfloat left = -1.0;
    GLfloat right = 1.0;
    GLfloat bottom = -1.0;
    GLfloat top = 1.0;
    GLfloat near = 1.0;
    GLfloat far = 16.0;
} Frustum;

void updateLookAt() {
    glEnable(GL_DEPTH_TEST);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(
        Eye.x,       Eye.y,       Eye.z,
        Reference.x, Reference.y, Reference.z,
        ViewUp.x,    ViewUp.y,    ViewUp.z
    );
}

void updateFrustum() {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(Frustum.left, Frustum.right, Frustum.bottom, Frustum.top, Frustum.near, Frustum.far);
}

void Cam::initialize() {
    glViewport(0, 0, 600, 600);
    updateFrustum();
    updateLookAt();
}

void Cam::move(GLfloat horizontal, GLfloat vertical) {
    Eye.x += horizontal;
    Reference.x += horizontal;
    updateLookAt();
}

void Cam::zoom(GLfloat factor) {
    Frustum.left += factor;
    Frustum.right -= factor;
    Frustum.bottom += factor;
    Frustum.top -= factor;

    updateFrustum();
}
