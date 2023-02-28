//
// Created by sophie on 27/02/23.
//

#ifndef TRANSFORMADAS_OBJETO_H
#define TRANSFORMADAS_OBJETO_H

#include <vector>

/**
 * Esse é um ponto 2D representado em coordenadas homogêneas.
 * O ponto z é o fator de escala (1 por padrão)
 */
struct Ponto {
    Ponto(double x, double y);
    double x();
    double y();
    void setX(double x);
    void setY(double y);

    private:
        double coords[3];
};

class Objeto {

    public:
        std::vector<Ponto> pontos;

        Objeto(std::vector<Ponto> pontos = {});
        void inserirPonto(Ponto ponto);

        void transalacao();
        void escala();
        void rotacao();
        void cisalhamento();
        void reflexao();

};


#endif // TRANSFORMADAS_OBJETO_H
