#include "tile.h"
#include "criatura.h"

char Tile::mostrar() const {
    if (criaturas.empty()) return '.';
    if (criaturas.size() < 10) return '0' + criaturas.size();
    return '*';
}
