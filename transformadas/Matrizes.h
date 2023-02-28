//
// Created by sophie on 27/02/23.
//

#ifndef TRANSFORMADAS_MATRIZES_H
#define TRANSFORMADAS_MATRIZES_H

constexpr int colResult{ 1 };
constexpr int col1{ 3 };

namespace Matriz {
    void multiplica(double m1[][col1], double m2[], double res[][colResult]);
}

#endif // TRANSFORMADAS_MATRIZES_H
