//
// Created by sophie on 08/05/23.
//

#ifndef OPENGL_CONSTANTS_H
#define OPENGL_CONSTANTS_H

#include <GL/glu.h>

struct Color {
    GLfloat red;
    GLfloat green;
    GLfloat blue;
};

namespace DefColor {
    constexpr Color grey = {.3, .3, .3};
    constexpr Color blue = {.3, 1, 1};
    constexpr Color orange = {.8, .4, .1};
    constexpr Color brown = {.4, .1, .1};
    constexpr Color black = {.0, .0, .0};
}

namespace Window {
    constexpr GLfloat width = 640.0;
    constexpr GLfloat height = 480.0;
}

#endif //OPENGL_CONSTANTS_H
