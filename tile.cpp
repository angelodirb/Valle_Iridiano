#include "tile.h"
#include <iostream>

char Tile::mostrar() const {
    if (criaturas.empty()) {
        switch (tipoTerreno) {
            case FERTIL:  std::cout << "\033[42mF\033[0m"; break;
            case NEUTRO:  std::cout << "\033[43mN\033[0m"; break;
            case LETAL:   std::cout << "\033[40mL\033[0m"; break;
        }
        return '\0';
    }

    char c = (criaturas.size() < 10) ? '0' + criaturas.size() : '*';
    std::cout << c;
    return '\0';
}

