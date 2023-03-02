//
// Created by sophie on 27/02/23.
//

#ifndef TRANSFORMADAS_OBJETO_H
#define TRANSFORMADAS_OBJETO_H

#include <vector>
#include <array>
#include "Matrizes.h"

/**
 * Esse é um ponto 2D representado em coordenadas homogêneas.
 * O ponto z é o fator de escala (1 por padrão)
 */
struct Ponto {
    Ponto(double x, double y);
    double x();
    double y();
    const Matriz::Mat3_1 getCoords();
    void setX(double x);
    void setY(double y);

    private:
        Matriz::Mat3_1 coords;
};

class Objeto {

    public:
        Objeto(std::vector<Ponto> pontos = {});

        void inserirPonto(Ponto ponto);
        Ponto getPonto(int i);

        Objeto transalacao(double tx, double ty);
        Objeto escala();
        Objeto rotacao();
        Objeto cisalhamento();
        Objeto reflexao();

    private:
        std::vector<Ponto> pontos;

};


#endif // TRANSFORMADAS_OBJETO_H
