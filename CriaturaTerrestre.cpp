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
    if (energia <= 0) return;

    if (!mapa) return;

    std::vector<std::pair<int, int>> posiblesMovimientos;

    // Evaluar posiciones vecinas
    for (int dx = -1; dx <= 1; ++dx) {
        for (int dy = -1; dy <= 1; ++dy) {
            if (dx == 0 && dy == 0) continue; // Saltar la posición actual
            if (abs(dx) + abs(dy) != 1) continue; // Solo movimientos ortogonales

            int nx = posX + dx;
            int ny = posY + dy;

            // Verificar que la nueva posición esté dentro de los límites del mapa
            if (nx >= 0 && nx < mapa->getFilas() && ny >= 0 && ny < mapa->getColumnas()) {
                posiblesMovimientos.emplace_back(nx, ny);
            }
        }
    }

    // Si hay movimientos posibles, elegir uno al azar
    if (!posiblesMovimientos.empty()) {
        // Elegir un movimiento aleatorio
        int index = rand() % posiblesMovimientos.size();
        auto movimientoElegido = posiblesMovimientos[index];

        // Actualizar la posición de la criatura
        posX = movimientoElegido.first;
        posY = movimientoElegido.second;

        // Aquí puedes agregar lógica para actualizar el mapa y los ocupantes
        const Tile* tileDestino = mapa->getTile(posY, posX);
        if (tileDestino) {
            const_cast<Tile*>(tileDestino)->agregarOcupante(); // Agregar ocupante
        }

        std::cout << "CriaturaTerrestre camina a (" << posX << ", " << posY << "). Vida: " << vida << ", Energía: " << energia << std::endl;
        }

    std::cout << nombre << " no puede moverse, todas las casillas vecinas están ocupadas.\n";
}

void CriaturaTerrestre::actuar() {
    std::cout << nombre << " está caminando.\n";
}