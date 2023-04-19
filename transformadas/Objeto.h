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
    double x() const;
    double y() const;
    void setX(double x);
    void setY(double y);
    Matriz::Mat3_1 getCoords() const;

    private:
        Matriz::Mat3_1 coords;
};

class Objeto {

    public:
        Objeto(std::vector<Ponto> pontos = {});

        void inserirPonto(Ponto ponto);
        Ponto getPonto(const int i);
        void printObjeto();

        enum class Ref { VERTICAL, HORIZONTAL, DIAGONAL, DIAGONAL_INVERSA };

        // Transformações primitivas
        Objeto& transalacao(const double tx, const double ty);
        Objeto& escala(const double sx, const double sy);
        Objeto& rotacao(const double grau);
        Objeto& cisalhamento(const double kx, const double ky);
        Objeto& reflexao(Ref);

        // Transformações compostas
        Objeto& rotacaoPonto(const Ponto &referencia, const double grau);
        Objeto& rotacaoCentro(const double grau);
        Objeto& escalaPonto(const Ponto &referencia, const double sx, const double sy);
        Objeto& escalaCentro(const double sx, const double sy);

    private:
        std::vector<Ponto> pontos;

};


#endif // TRANSFORMADAS_OBJETO_H
