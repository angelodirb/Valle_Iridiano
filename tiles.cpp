#include "tiles.h"

char Tile::mostrar() const {
    if (criaturasEnCasilla == 0) return '.';
    else if (criaturasEnCasilla < 10) return '0' + criaturasEnCasilla;
    else return '*';
}
