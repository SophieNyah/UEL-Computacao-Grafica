#include <iostream>
#include "Objeto.h"

int main() {
    Objeto o{};
    o.inserirPonto({5, 3});
    std::cout << o.getPonto(0).x() << " " << o.getPonto(0).y() << "\n";
    o.transalacao(10, 20);
    std::cout << o.getPonto(0).x() << " " << o.getPonto(0).y() << "\n";
    return 0;
}
