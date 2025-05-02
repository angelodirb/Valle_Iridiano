#ifndef TILE_H
#define TILE_H

#include <vector>

class Criatura;

class Tile {
public:
    std::vector<Criatura*> criaturas;

    char mostrar() const;
};

#endif
