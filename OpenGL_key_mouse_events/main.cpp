//
// Created by sophie on 24/04/23.
//

#include <GL/glut.h>
#include "figures.h"
#include "keyboard_mouse_handler.h"
#include "menus.h"

void myInit(void);
void myDisplay(void);

int main(int argc, char* argv[]) {
    glutInit(&argc, argv); // Inicializa o GLUT e processa qualquer parâmetro passado pela linha de comandos. Deve ser chamada antes de qualquer outra rotina GLUT.
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB); // Especifica como o vídeo será utilizado, no caso será alocado um buffer e o sistema de cor será RGB.
    glutInitWindowSize (640, 480); // Especifica as dimensões da janela em pixels.
    glutInitWindowPosition (100, 100); // Especifica a coordenada superior esquerda da janela. Define a localização da janela dentro da tela
    glutCreateWindow ("Primeiro programa"); // Cria a janela e devolve um identificador único para a janela. Até que o comando glutMainLoop seja chamado, a janela não será mostrada.
    myInit(); // Rotina que implementa as configurações iniciais do programa.
    glutDisplayFunc(myDisplay); // Chamada para a função de desenho
    glClear(GL_COLOR_BUFFER_BIT);
    // Toda vez que o GLUT determinar que a janela tem de ser desenhada, ele chamará a função aqui determinada.

    glutKeyboardFunc(handle_KeyboardFunc); // Determinam as funções que usaremos para ler o teclado e o mouse respectivamente.
    glutMouseFunc(handle_MouseFunc);
    glutPassiveMotionFunc(handle_PassiveMotion);
    glutMotionFunc(handle_motion);
    glutCreateMenu(handle_menu);
    create_menu();

    glutMainLoop( ); // É o último comando que chamamos. Ele faz com que todas as janelas criadas sejam mostradas. Uma vez que entramos neste loop, só saímos quando o programa se encerra.
    return 0;
}

void myInit(void) {
    glClearColor(1.0,1.0,1.0,0.0);     // cor de fundo branco
    glColor3f(0.0f, 0.0f, 0.0f);          // Define cor corrente de desenho
    glPointSize(4.0);             // Define o tamanho do ponto: 4 por 4 pixels
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    // janela com resolução de 640 por 480
    gluOrtho2D(0.0, 640.0, 480.0, 0.0);
}

void myDisplay(void) {
//    glClear(GL_COLOR_BUFFER_BIT); // limpa a janela
//    const int yBase = 100;
//    const int xBase = 200;
//    const int houseWidth = 150;
//    const int houseHeight = houseWidth - 30;
//    draw_rectangle(xBase, yBase, houseWidth, houseHeight, {grey});
//    draw_rectangle(xBase + 35, yBase, 30, 60, {blue});
//    draw_rectangle(xBase + 80, yBase + 30, 50, 50, {blue});
//    draw_rectangle(xBase + 20, yBase + houseHeight, 20, 75, {brown});
//    draw_triangle(
//            xBase,                  yBase + houseHeight,
//            xBase + houseWidth,      yBase + houseHeight,
//            xBase + (houseWidth/2), yBase + houseHeight + 60,
//            {orange}
//    );

    glFlush(); // Garante a execução de todas as rotinas de desenho
}
