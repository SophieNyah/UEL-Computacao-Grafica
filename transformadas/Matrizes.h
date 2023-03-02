//
// Created by sophie on 27/02/23.
//

#ifndef TRANSFORMADAS_MATRIZES_H
#define TRANSFORMADAS_MATRIZES_H

#include <array>

namespace Matriz {
    using Mat3_1 = std::array<double, 3>;
    using Mat3_3 = std::array<std::array<double, 3>, 3>;
    Mat3_1 multiplica(const Mat3_3,  const Mat3_1);
}

#endif // TRANSFORMADAS_MATRIZES_H
