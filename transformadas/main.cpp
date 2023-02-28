#include <iostream>
#include "Objeto.h"
#include "Matrizes.h"

int main() {
    double a[][3]{ {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };
    double b[]{ 11,12,13 };
    double c[][1]{};
    Matriz::multiplica(a, b, c);
    return 0;
}
