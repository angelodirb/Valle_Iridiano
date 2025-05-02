#ifndef TILE_H
#define TILE_H

#include <vector>

class Criatura; // Declaración adelantada

struct Tile {
    std::vector<Criatura*> criaturas;
};

#endif
