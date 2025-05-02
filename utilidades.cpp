#include "Utilidades.h"
#include <iostream>
#include <cstdlib>

const int MAPA_TAM = 10;

void mostrarMapa(const std::vector<std::vector<Tile>>& mapa) {
    for (int i = 0; i < MAPA_TAM; ++i) {
        for (int j = 0; j < MAPA_TAM; ++j) {
            std::cout << mapa[i][j].mostrar() << " ";
        }
        std::cout << std::endl;
    }
}

void moverCriaturaAleatoria(std::vector<std::vector<Tile>>& mapa, Criatura& criatura) {
    mapa[criatura.y][criatura.x].tieneCriatura = false;

    int direccion = rand() % 4;

    switch (direccion) {
    case 0: if (criatura.y > 0) criatura.y--; break;
    case 1: if (criatura.y < MAPA_TAM - 1) criatura.y++; break;
    case 2: if (criatura.x > 0) criatura.x--; break;
    case 3: if (criatura.x < MAPA_TAM - 1) criatura.x++; break;
    }

    mapa[criatura.y][criatura.x].tieneCriatura = true;
}
