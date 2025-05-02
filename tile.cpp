#include "Tile.h"

char Tile::mostrar() const {
    return tieneCriatura ? 'C' : '.';
}
