#ifndef TIILES_H
#define TIILES_H

#include <vector>
#include "criaturs.h"

class Tile {
public:
    std::vector<Criatura*> criaturas;

    char mostrar() const;
};

#endif
