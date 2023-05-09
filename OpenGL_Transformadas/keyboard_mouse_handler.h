//
// Created by sophie on 24/04/23.
//

#ifndef OPENGL_KEYBOARD_MOUSE_HANDLER_H
#define OPENGL_KEYBOARD_MOUSE_HANDLER_H

void handle_KeyboardFunc(GLubyte key, GLint x, GLint y);
void handle_specialFunc(GLint key, GLint x, GLint y);
void handle_MouseFunc(GLint button, GLint action, GLint x, GLint y);
void handle_PassiveMotion(GLint x, GLint y);
void handle_motion(GLint x, GLint y);


#endif //OPENGL_KEYBOARD_MOUSE_HANDLER_H
