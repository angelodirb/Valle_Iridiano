#include "Criaturaaerea.h"
#include "tile.h"
#include <cstdlib>

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
    mapa[y][x].criaturas.erase(
        std::remove(mapa[y][x].criaturas.begin(), mapa[y][x].criaturas.end(), this),
        mapa[y][x].criaturas.end()
    );

    int nx = x + (rand() % 5 - 2);
    int ny = y + (rand() % 5 - 2);

    if (nx >= 0 && nx < 15 && ny >= 0 && ny < 15) {
        x = nx;
        y = ny;
    }

    mapa[y][x].criaturas.push_back(this);
}
