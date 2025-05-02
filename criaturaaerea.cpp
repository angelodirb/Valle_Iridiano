#include "CriaturaAerea.h"
#include <cstdlib>
#include <algorithm>

CriaturaAerea::CriaturaAerea(int x, int y, int vida) : Criatura(x, y, vida) {
    esperanza_vida = 20 + rand() % 6;
}

std::string CriaturaAerea::tipo() const { return "aerea"; }

bool CriaturaAerea::puedeSobrevolar() const { return altura_vuelo > 0; }

void CriaturaAerea::mover(std::vector<std::vector<Tile>>& mapa) {
    auto& actual = mapa[y][x];
    actual.criaturas.erase(std::remove(actual.criaturas.begin(), actual.criaturas.end(), this), actual.criaturas.end());

    int nx = x + (rand() % 5 - 2);
    int ny = y + (rand() % 5 - 2);

    if (nx >= 0 && nx < mapa.size() && ny >= 0 && ny < mapa.size()) {
        x = nx;
        y = ny;
    }

    mapa[y][x].criaturas.push_back(this);
}
