#ifndef UTILIDADES_H
#define UTILIDADES_H

#include <vector>
#include "Tile.h"
#include "Criaturas.h"

void mostrarMapa(const std::vector<std::vector<Tile>>& mapa);
void moverCriaturaAleatoria(std::vector<std::vector<Tile>>& mapa, Criatura& criatura);

#endif
