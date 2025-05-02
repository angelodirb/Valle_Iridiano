//
// Created by HOME on 02/05/2025.
//

#include "tile.h"
#include "criaturas.h"
#include <iostream>

char Tile::mostrar() const {
    if (criaturas.empty()) {
        switch (tipoTerreno) {
            case FERTIL:  std::cout << "B"; break;
            case NEUTRO:  std::cout << "D"; break;
            case LETAL:   std::cout << "M"; break;
        }
        return '\0';
    }

    char c = (criaturas.size() < 10) ? '0' + criaturas.size() : '*';
    std::cout << c;
    return '\0';
}