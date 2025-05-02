#ifndef TILE_H
#define TILE_H

#include "criatura.h"
#include <vector>

enum TipoTerreno { FERTIL, NEUTRO, LETAL };

class Tile {
public:
    std::vector<Criatura*> criaturas;
    TipoTerreno tipoTerreno;

    char mostrar() const;
};

#endif // TILE_H
