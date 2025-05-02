#include "CriaturaAerea.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

CriaturaAerea::CriaturaAerea(std::string nombre, int vida, int energia, int x, int y, Mapa* mapa)
    : Criatura(nombre, vida, energia, x, y, "Aérea") {
    this->mapa = mapa;
    std::srand((unsigned)time(nullptr));
}

void CriaturaAerea::mover() {
    if (energia <= 0) {
        std::cout << nombre << " no tiene energía para moverse.\n";
        return;
    }

    if (!mapa) {
        std::cout << nombre << ": Mapa no asignado, no puedo moverme.\n";
        return;
    }

    std::vector<std::pair<int, int>> posiblesMovimientos;

    // Evaluar las 8 posiciones vecinas (incluyendo diagonales)
    for (int dx = -1; dx <= 1; ++dx) {
        for (int dy = -1; dy <= 1; ++dy) {
            if (dx == 0 && dy == 0) continue; // No considerar el tile actual

            int nx = posX + dx;
            int ny = posY + dy;

            // Verificar límites del mapa
            if (nx >= 0 && nx < mapa->getFilas() && ny >= 0 && ny < mapa->getColumnas()) {
                posiblesMovimientos.emplace_back(nx, ny);
            }
        }
    }

    if (!posiblesMovimientos.empty()) {
        // Elegir un movimiento aleatorio
        int indice = rand() % posiblesMovimientos.size();
        auto movimiento = posiblesMovimientos[indice];

        const Tile* tileActual = mapa->getTile(posY, posX);
        const Tile* tileDestino = mapa->getTile(movimiento.second, movimiento.first);

        if (tileActual && tileDestino) {
            // Actualizar ocupantes en los tiles usando const_cast para modificación
            const_cast<Tile*>(tileActual)->eliminarOcupante();
            const_cast<Tile*>(tileDestino)->agregarOcupante();

            // Actualizar posición de la criatura
            posX = movimiento.first;
            posY = movimiento.second;

            // Aplicar efectos del bioma (si tienes esta función)
            tileDestino->getBioma().aplicarEfecto(vida, energia, nombre);

            std::cout << nombre << " vuela a (" << posX << ", " << posY << "). Vida: " << vida << ", Energía: " << energia << "\n";
        }
    } else {
        std::cout << nombre << " no tiene movimientos disponibles.\n";
    }
}

void CriaturaAerea::actuar() {
    std::cout << nombre << " está volando.\n";
}