#include "CriaturaTerrestre.h"
#include <algorithm>
#include <cstdlib>

CriaturaTerrestre::CriaturaTerrestre(int x, int y, int vida) : Criatura(x, y, vida) {
    esperanza_vida = 15 + rand() % 17;
}

std::string CriaturaTerrestre::tipo() const { return "terrestre"; }

bool CriaturaTerrestre::estaOculta() const { return camuflaje_activo; }

void CriaturaTerrestre::mover(std::vector<std::vector<Tile>>& mapa) {
    int dx[] = {0, 0, -1, 1};
    int dy[] = {-1, 1, 0, 0};
    std::vector<int> dirs = {0, 1, 2, 3};
    std::random_shuffle(dirs.begin(), dirs.end());

    auto& actual = mapa[y][x];
    actual.criaturas.erase(std::remove(actual.criaturas.begin(), actual.criaturas.end(), this), actual.criaturas.end());

    for (int i : dirs) {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx >= 0 && nx < mapa.size() && ny >= 0 && ny < mapa.size()) {
            x = nx;
            y = ny;
            break;
        }
    }

    mapa[y][x].criaturas.push_back(this);
}
