//
// Created by sophie on 27/02/23.
//

#include "Objeto.h"

Ponto::Ponto(double x, double y): coords{x, y, 1} {}
double Ponto::x() { return this->coords[0]; }
double Ponto::y() { return this->coords[1]; }
void   Ponto::setX(double x) { this->coords[0] = x; }
void   Ponto::setY(double y) { this->coords[1] = y; }
const  Matriz::Mat3_1 Ponto::getCoords() { return this->coords; }

// https://stackoverflow.com/questions/31502120/sin-and-cos-give-unexpected-results-for-well-known-angles/31525208#31525208
Objeto Objeto::transalacao(double tx, double ty) {
    Matriz::Mat3_3 mat{{
           {1, 0, tx},
           {0, 1, ty},
           {0, 0, 1}
   }};
    for(Ponto &ponto: this->pontos) {
        Matriz::Mat3_1 p = Matriz::multiplica(mat, ponto.getCoords());
        ponto.setX(p[0]);
        ponto.setY(p[1]);
    }
    return *this;
}
Objeto Objeto::escala() {

}
Objeto Objeto::rotacao() {

}
Objeto Objeto::cisalhamento() {

}
Objeto Objeto::reflexao() {

}

Objeto::Objeto(std::vector<Ponto> pontos): pontos{ pontos } {}

void Objeto::inserirPonto(Ponto ponto) {
    this->pontos.emplace_back(ponto);
}

Ponto Objeto::getPonto(int i) {
    return this->pontos.at(i);
}
