//
// Created by sophie on 14/06/23.
//

#ifndef T4E3_LABYRIN_H
#define T4E3_LABYRIN_H

namespace Labyrinth {
    enum State { Win, Lose, Playing };
    void draw();
    State check_collision(GLint mouse_x, GLint mouse_y);
    void win();
    void lose();
}

#endif //T4E3_LABYRIN_H
