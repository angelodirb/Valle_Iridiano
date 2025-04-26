#include "Mapa.h"
#include <iostream>

Mapa::Mapa(int filas, int columnas) : filas(filas), columnas(columnas) {
    inicializarMapa();
}

void Mapa::inicializarMapa() {
    tiles.resize(filas, std::vector<Tile>(columnas, Tile("tierra", false)));
}

Tile* Mapa::getTile(int fila, int columna) {
    if (fila >= 0 && fila < filas && columna >= 0 && columna < columnas) {
        return &tiles[fila][columna];
    }
    return nullptr; // Retorna nullptr si las coordenadas son inválidas
}

void Mapa::mostrarMapa() const {
    for (const auto& fila : tiles) {
        for (const auto& tile : fila) {
            std::cout << tile.getTipo() << (tile.isOcupado() ? " (Ocupado) " : " (Libre) ") << "| ";
        }
        std::cout << std::endl;
    }
}