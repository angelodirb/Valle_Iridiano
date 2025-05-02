//
// Created by HOME on 02/05/2025.
//

#include "criaturashibridas.h"

#include "criaturashibridas.h"
#include <cstdlib>

CriaturaHibrida::CriaturaHibrida(int x, int y, int vida)
    : Criatura(x, y, vida),
      CriaturaTerrestre(x, y, vida),
      CriaturaAerea(x, y, vida) {
    esperanza_vida = 18 + rand() % 8;
}

std::string CriaturaHibrida::tipo() const {
    return "hibrida";
}

void CriaturaHibrida::mover(std::vector<std::vector<Tile>>& mapa) {
    if (rand() % 2 == 0)
        CriaturaTerrestre::mover(mapa);
    else
        CriaturaAerea::mover(mapa);
}

bool CriaturaHibrida::estaOculta() const {
    return CriaturaTerrestre::estaOculta();
}

bool CriaturaHibrida::puedeSobrevolar() const {
    return CriaturaAerea::puedeSobrevolar();
}