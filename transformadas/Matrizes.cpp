//
// Created by sophie on 27/02/23.
//

#include <cmath>
#include "Matrizes.h"

namespace Matriz {
    Mat3_1 multiplica(const Mat3_3 mat, const Mat3_1 ponto) {
        Mat3_1 res{0, 0, 0};
        res[0] = mat[0][0]*ponto[0] + mat[0][1]*ponto[1] + mat[0][2]*ponto[2];
        res[1] = mat[1][0]*ponto[0] + mat[1][1]*ponto[1] + mat[1][2]*ponto[2];
        res[2] = mat[2][0]*ponto[0] + mat[2][1]*ponto[1] + mat[2][2]*ponto[2];
        return res;
    }

    double grauPraRadiano(const double grau){
        return (grau / 180.0) * ((double) PI);
    }

    double senG(const double grau) {
        if (!std::isfinite(grau)) {
            return sin(grau);
        }
        if (grau < 0.0) {
            return -senG(-grau);
        }
        int quo;
        double x90 = remquo(fabs(grau), 90.0, &quo);
        switch (quo % 4) {
            case 0:
                // Use * 1.0 to avoid -0.0
                return sin(grauPraRadiano(x90)* 1.0);
            case 1:
                return cos(grauPraRadiano(x90));
            case 2:
                return sin(grauPraRadiano(-x90) * 1.0);
            case 3:
                return -cos(grauPraRadiano(x90));
        }
        return 0.0;
    }
    double cosG(const double grau) {
        return senG(90 - fabs(grau));
    }

}
