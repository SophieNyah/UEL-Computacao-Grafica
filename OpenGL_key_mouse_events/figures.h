//
// Created by sophie on 24/04/23.
//

#ifndef OPENGL_FIGURES_H
#define OPENGL_FIGURES_H

#include <optional>
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

void draw_rectangle(GLint x1, GLint y1, GLint width, GLint height, std::optional<Color> color=std::nullopt);
void draw_triangle(GLint x1, GLint y1, GLint x2, GLint y2, GLint x3, GLint y3, std::optional<Color> color=std::nullopt);
void limpa_tela();
void draw_point(GLint x, GLint y, std::optional<Color> color=std::nullopt);
void set_color(Color color);
void set_thickness(GLfloat thickness);

#endif //OPENGL_FIGURES_H
