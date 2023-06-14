//
// Created by sophie on 24/04/23.
//

#include <GL/glut.h>
#include <iostream>
#include "keyboard_mouse_handler.h"
#include "labyrinth.h"

void handle_KeyboardFunc(GLubyte key, GLint x, GLint y) {
    GLint m = glutGetModifiers();

    switch (key) {
        case 27:
            exit(0);
            break;
    }
}

void handle_PassiveMotion(GLint x, GLint y) {
    switch(Labyrinth::check_collision(x, y)) {
        case Labyrinth::State::Playing:
            break;
        case Labyrinth::State::Lose:
            Labyrinth::lose();
            break;
        case Labyrinth::State::Win:
            Labyrinth::win();
            break;
    }
}
