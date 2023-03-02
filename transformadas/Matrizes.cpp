//
// Created by sophie on 27/02/23.
//

#include "Matrizes.h"

namespace Matriz {
    Mat3_1 multiplica(const Mat3_3 mat, const Mat3_1 ponto) {
        Mat3_1 res{0, 0, 0};
        res[0] = mat[0][0]*ponto[0] + mat[0][1]*ponto[1] + mat[0][2]*ponto[2];
        res[1] = mat[1][0]*ponto[0] + mat[1][1]*ponto[1] + mat[1][2]*ponto[2];
        res[2] = mat[2][0]*ponto[0] + mat[2][1]*ponto[1] + mat[2][2]*ponto[2];
        return res;
    }
}
