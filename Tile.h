//
// Created by HOME on 02/05/2025.
//

#ifndef TILE_H
#define TILE_H



#include <vector>

class Criatura; // Declaración anticipada

enum TipoTerreno { FERTIL, NEUTRO, LETAL };

class Tile {
public:
    std::vector<Criatura*> criaturas;
    TipoTerreno tipoTerreno;

    char mostrar() const;
};


#endif //TILE_H
