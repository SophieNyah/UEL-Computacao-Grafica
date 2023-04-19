import pygame
import sys
import time

white = (255, 255, 255)
red   = (255,   0,   0)
green = (0,   255,   0)
blue  = (0,     0, 255)


def imprimepontos(screen):
    for i in range(100, 200):
        screen.set_at((i, i), white)


def bresenham_reta(screen, x1, y1, x2, y2, color=white):
    dx = x2 - x1
    dy = y2 - y1
    m = dy / dx
    if m > 1:
        x1, x2, y1, y2 = y1, y2, x1, x2
        dx = x2 - x1
        dy = y2 - y1
    dx = abs(dx)
    dy = abs(dy)

    y_step = 1 if y1 < y2 else -1
    x_step = 1 if x1 < x2 else -1

    def compare():
        if x1 < x2:
            return True if x < x2 else False
        else:
            return True if x > x2 else False

    neg_p = 2 * dy
    pos_p = (2 * dy) - (2 * dx)
    p = 2 * dy
    x = x1
    y = y1
    if m > 1:
        screen.set_at((y, x), color)
    else:
        screen.set_at((x, y), color)
    while compare():
        x += x_step
        if p < 0:
            p += neg_p
        else:
            y += y_step
            p += pos_p
        if m > 1:
            screen.set_at((y, x), color)
        else:
            screen.set_at((x, y), color)


def bresenham_circulo(screen, xc, yc, r, color=white):
    x = 0
    y = r

    def plot_octantes():
        screen.set_at(( y + xc, x + yc), color)
        screen.set_at(( x + xc, y + yc), color)
        screen.set_at((-y + xc, x + yc), color)
        screen.set_at((-x + xc, y + yc), color)
        screen.set_at((-y + xc,-x + yc), color)
        screen.set_at((-x + xc,-y + yc), color)
        screen.set_at(( x + xc,-y + yc), color)
        screen.set_at(( y + xc,-x + yc), color)
    plot_octantes()
    p = 1 - r
    while x < y:
        x += 1
        if p < 0:
            p += 2*x + 1
        else:
            y -= 1
            p += 2*x + 1 - 2*y
        plot_octantes()


pygame.init()  # inicialização
window = pygame.display.set_mode((500, 500))  # cria a janela de exibição
pygame.display.set_caption("Teste do Pygame")

# imprimepontos(window)  # aqui vc vai chamar a função para desenhar a reta ou circunferencia
bresenham_reta(window,  10,  20, 270, 450, white)
bresenham_reta(window, 400, 400, 310, 200, red)
bresenham_reta(window,  45, 380, 135, 310, green)
bresenham_reta(window, 400, 410, 300, 480, blue)
bresenham_circulo(window, 300, 75, 60)
pygame.display.update()  # refresh da janela para exibir o que foi impresso com set_at

# loop para congelar a janela
# fica aguardando um evento, que no caso é o fechamento da janela no botao X
while True:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:  # fechar a janela no x
            pygame.quit()
            sys.exit()
