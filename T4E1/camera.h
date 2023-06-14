//
// Created by sophie on 13/06/23.
//

#ifndef T4E1_CAMERA_H
#define T4E1_CAMERA_H

#include <GL/glut.h>

namespace Cam {
    void initialize();

    void move(GLfloat horizontal, GLfloat vertical);
    void zoom(GLfloat factor);
}

#endif //T4E1_CAMERA_H
