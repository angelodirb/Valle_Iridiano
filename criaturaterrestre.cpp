#include "CriaturaTerrestre.h"
#include "Tile.h"
#include <cstdlib>
#include <algorithm>

CriaturaTerrestre::CriaturaTerrestre(int x, int y, int vida) : Criatura(x, y, vida) {
    esperanza_vida = 15 + rand() % 17;
}

bool CriaturaTerrestre::estaOculta() const {
    return camuflaje_activo;
}

std::string CriaturaTerrestre::tipo() const {
    return "terrestre";
}

void CriaturaTerrestre::mover(std::vector<std::vector<Tile>>& mapa) {
    int dx[] = {0, 0, -1, 1};
    int dy[] = {-1, 1, 0, 0};
    std::vector<int> direcciones = {0, 1, 2, 3};
    std::random_shuffle(direcciones.begin(), direcciones.end());

    auto& casillaActual = mapa[y][x];
    casillaActual.criaturas.erase(
        std::remove(casillaActual.criaturas.begin(), casillaActual.criaturas.end(), this),
        casillaActual.criaturas.end()
    );

    for (int i : direcciones) {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx >= 0 && nx < MAPA_TAM && ny >= 0 && ny < MAPA_TAM) {
            x = nx;
            y = ny;
            break;
        }
    }

    mapa[y][x].criaturas.push_back(this);
}

void CriaturaTerrestre::mover(std::vector<std::vector<Tile>>& mapa) {
    int dx[] = {0, 0, -1, 1};
    int dy[] = {-1, 1, 0, 0};
    std::vector<int> direcciones = {0, 1, 2, 3};
    std::random_shuffle(direcciones.begin(), direcciones.end());

    mapa[y][x].criaturas.erase(
        std::remove(mapa[y][x].criaturas.begin(), mapa[y][x].criaturas.end(), this),
        mapa[y][x].criaturas.end()
    );

    for (int i : direcciones) {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx >= 0 && nx < 15 && ny >= 0 && ny < 15) {
            x = nx;
            y = ny;
            break;
        }
    }

    mapa[y][x].criaturas.push_back(this);
}
