#ifndef TILE_H
#define TILE_H

#include <vector>
#include "Criatura.h"

enum TipoTerreno { FERTIL, NEUTRO, LETAL };

class Criatura; // forward declaration

class Tile {
public:
    std::vector<Criatura*> criaturas;
    TipoTerreno tipoTerreno;

    char mostrar() const;
};

#endif
