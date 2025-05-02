//
// Created by HOME on 02/05/2025.
//


#include "criaturasterrestres.h"
#include "tile.h"
#include <algorithm>
#include <cstdlib>

#include "ecosistema.h"

CriaturaTerrestre::CriaturaTerrestre(int x, int y, int vida)
    : Criatura(x, y, vida) {
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
        if (nx >= 0 && nx < Ecosistema::MAPA_TAM && ny >= 0 && ny < Ecosistema::MAPA_TAM) {
            x = nx;
            y = ny;
            break;
        }
    }

    mapa[y][x].criaturas.push_back(this);
}