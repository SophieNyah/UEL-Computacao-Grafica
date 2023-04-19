#include <iostream>
#include "Objeto.h"

int main() {
    Objeto linha     { {{2, 0}, {4, 0}} };
    Objeto triangulo { {{1,1}, {3,1}, {2,2}} };
    Objeto casa      { {{1,1}, {1,3}, {2,4}, {3,4}, {4,3}, {4,1}} }; // "casinha" dos slides

    linha.rotacaoPonto(linha.getPonto(0), 30);
    triangulo.escalaCentro(2, 2)
        .rotacaoPonto(triangulo.getPonto(2), 180)
        .rotacaoCentro(-45);
    casa.cisalhamento(1, 0)
        .reflexao(Objeto::Ref::VERTICAL);

    linha.printObjeto();
    triangulo.printObjeto();
    casa.printObjeto();
    return 0;
}
