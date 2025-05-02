#include "CriaturaTerrestre.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

CriaturaTerrestre::CriaturaTerrestre(std::string nombre, int vida, int energia, int x, int y, Mapa* mapa)
    : Criatura(nombre, vida, energia, x, y, "Terrestre") {
    this->mapa = mapa;
    std::srand((unsigned)time(nullptr));
}

void CriaturaTerrestre::mover() {
    if (energia <= 0) {
        std::cout << nombre << " no tiene energía para moverse.\n";
        return; // No se puede mover si no hay energía
    }

    if (!mapa) {
        std::cout << nombre << ": Mapa no asignado, no puedo moverme.\n";
        return;
    }

    // Movimiento simple aleatorio a tile vecino válido
    const int posiblesX[] = {posX - 1, posX + 1, posX, posX};
    const int posiblesY[] = {posY, posY, posY - 1, posY + 1};

    for (int i = 0; i < 4; ++i) {
        int nx = posiblesX[i];
        int ny = posiblesY[i];

        if (nx >= 0 && nx < mapa->getFilas() && ny >= 0 && ny < mapa->getColumnas()) {
            Tile* tileDestino = mapa->getTile(nx, ny);
            if (tileDestino) {
                Tile* tileActual = mapa->getTile(posX, posY);
                if (tileActual) {
                    tileActual->eliminarOcupante(); // Eliminar ocupante del tile actual
                }

                posX = nx;
                posY = ny;
                tileDestino->agregarOcupante(); // Agregar ocupante al nuevo tile

                // Aplicar efecto del bioma en vida y energía
                tileDestino->getBioma().aplicarEfecto(vida, energia, nombre);

                std::cout << nombre << " camina a (" << posX << ", " << posY << "). Vida: " << vida << ", Energía: " << energia << "\n";
                return;
            }
        }
    }
    std::cout << nombre << " no puede moverse, todas las casillas vecinas están ocupadas.\n";
}

void CriaturaTerrestre::actuar() {
    std::cout << nombre << " está caminando.\n";
}