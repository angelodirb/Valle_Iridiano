//
// Created by HOME on 02/05/2025.
//

#include "criaturasaereas.h"

#include "tile.h"
#include <cstdlib>
#include <algorithm>

#include "ecosistema.h"

CriaturaAerea::CriaturaAerea(int x, int y, int vida)
    : Criatura(x, y, vida) {
    esperanza_vida = 20 + rand() % 6;
}

bool CriaturaAerea::puedeSobrevolar() const {
    return altura_vuelo > 0;
}

std::string CriaturaAerea::tipo() const {
    return "aerea";
}

void CriaturaAerea::mover(std::vector<std::vector<Tile>>& mapa) {
    auto& casillaActual = mapa[y][x];
    casillaActual.criaturas.erase(
        std::remove(casillaActual.criaturas.begin(), casillaActual.criaturas.end(), this),
        casillaActual.criaturas.end()
    );

    int nx = x + (rand() % 5 - 2);
    int ny = y + (rand() % 5 - 2);

    if (nx >= 0 && nx < Ecosistema::MAPA_TAM && ny >= 0 && ny < Ecosistema::MAPA_TAM) {
        x = nx;
        y = ny;
    }

    mapa[y][x].criaturas.push_back(this);
}