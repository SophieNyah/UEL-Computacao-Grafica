//
// Created by sophie on 27/02/23.
//

#include <iostream>
#include "Objeto.h"

Ponto::Ponto(double x, double y): coords{x, y, 1} {}
double Ponto::x() const { return this->coords[0]; }
double Ponto::y() const { return this->coords[1]; }
void   Ponto::setX(double x) { this->coords[0] = x; }
void   Ponto::setY(double y) { this->coords[1] = y; }
Matriz::Mat3_1 Ponto::getCoords() const { return this->coords; }


void transformaObjeto(const Matriz::Mat3_3 &transformacao, std::vector<Ponto> &pontos){
    for(Ponto &ponto: pontos) {
        Matriz::Mat3_1 p = Matriz::multiplica(transformacao, ponto.getCoords());
        ponto.setX(p[0]);
        ponto.setY(p[1]);
    }
}
Ponto centroGeometrico(const std::vector<Ponto> &pontos){
    double x = 0;
    double y = 0;
    for(Ponto p: pontos) {
        x += p.x();
        y += p.y();
    }
    x = x/pontos.size();
    y = y/pontos.size();
    return Ponto{x, y};
}

Objeto& Objeto::transalacao(const double tx, const double ty) {
    Matriz::Mat3_3 mat{{
           {1, 0, tx},
           {0, 1, ty},
           {0, 0,  1}
   }};
    transformaObjeto(mat, this->pontos);
    return *this;
}
Objeto& Objeto::escala(const double sx, const double sy) {
    Matriz::Mat3_3  mat {{
        {sx, 0, 0},
        {0, sy, 0},
        {0, 0,  1}
    }};
    transformaObjeto(mat, this->pontos);
    return *this;
}
Objeto& Objeto::rotacao(const double grau) {
    double sen = Matriz::senG(grau);
    double cos = Matriz::cosG(grau);
    Matriz::Mat3_3 mat {{
        {cos, -sen, 0},
        {sen,  cos, 0},
        {  0,    0, 1}
    }};
    transformaObjeto(mat, this->pontos);
    return *this;
}
Objeto& Objeto::cisalhamento(const double kx, const double ky) {
    Matriz::Mat3_3 mat {{
        {1, kx, 0},
        {ky, 1, 0},
        { 0, 0, 1}
    }};
    transformaObjeto(mat, this->pontos);
    return *this;
}
Objeto& Objeto::reflexao(Ref tipo) {
    Matriz::Mat3_3 mat;
    switch(tipo){
        case Ref::VERTICAL:
            mat = {{
                {1, 0, 0},
                {0,-1, 0},
                {0, 0, 1}
            }};
            break;
        case Ref::HORIZONTAL:
            mat = {{
                {-1, 0, 0},
                { 0, 1, 0},
                { 0, 0, 1}
            }};
            break;
        case Ref::DIAGONAL:
            mat = {{
                {0, 1, 0},
                {1, 0, 0},
                {0, 0, 1}
            }};
            break;
        case Ref::DIAGONAL_INVERSA:
            mat = {{
                { 0,-1, 0},
                {-1, 0, 0},
                { 0, 0, 1}
            }};
            break;
    }
    transformaObjeto(mat, this->pontos);
    return *this;
}

Objeto &Objeto::rotacaoPonto(const Ponto &referencia, const double grau) {
    double x = referencia.x();
    double y = referencia.y();
    return this->transalacao(-x, -y).rotacao(grau).transalacao(x, y);
}
Objeto &Objeto::rotacaoCentro(const double grau) {
    Ponto centro = centroGeometrico(this->pontos);
    return this->rotacaoPonto(centro, grau);
}
Objeto &Objeto::escalaPonto(const Ponto &referencia, const double sx, const double sy) {
    double x = referencia.x();
    double y = referencia.y();
    return this->transalacao(-x, -y).escala(sx, sy).transalacao(x, y);
}
Objeto &Objeto::escalaCentro(const double sx, const double sy) {
    Ponto centro = centroGeometrico(this->pontos);
    return this->escalaPonto(centro, sx, sy);
}


Objeto::Objeto(std::vector<Ponto> pontos): pontos{ pontos } {}

void Objeto::inserirPonto(Ponto ponto) {
    this->pontos.emplace_back(ponto);
}

Ponto Objeto::getPonto(const int i) {
    return this->pontos.at(i);
}

void Objeto::printObjeto() {
    for(Ponto p: this->pontos) {
        std::cout << " (" << p.x() << ", " << p.y() << ") ";
    }
    std::cout << '\n';
}
