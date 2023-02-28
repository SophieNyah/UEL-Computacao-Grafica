//
// Created by sophie on 27/02/23.
//

#include "Objeto.h"

Ponto::Ponto(double x, double y): coords{x, y, 1} {}
double Ponto::y() { return this->coords[0]; }
double Ponto::x() { return this->coords[1]; }
void   Ponto::setX(double x) { this->coords[0] = x; }
void   Ponto::setY(double y) { this->coords[1] = y; }


Objeto::Objeto(std::vector<Ponto> pontos): pontos{ pontos } {}

void Objeto::inserirPonto(Ponto ponto) {
    this->pontos.emplace_back(ponto);
}
