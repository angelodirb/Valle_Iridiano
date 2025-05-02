#include "Mapa.h"
#include <iostream>

Mapa::Mapa(int filas, int columnas) : filas(filas), columnas(columnas) {
    inicializarMapa();
}

void Mapa::inicializarMapa() {
    tiles.resize(filas, std::vector<Tile>(columnas, Tile("tierra", Bioma(Bioma::TipoBioma::BOSQUE, Bioma::EstadoTerreno::NORMAL))));
    // Aquí puedes personalizar los biomas de cada tile según sea necesario
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
            char simbBioma = ' ';
            switch (tile.getBioma().getTipo()) {
                case Bioma::TipoBioma::BOSQUE: simbBioma = 'B'; break;
                case Bioma::TipoBioma::DESIERTO: simbBioma = 'D'; break;
                case Bioma::TipoBioma::MONTAÑA: simbBioma = 'M'; break;
                default: simbBioma = '?'; break;
            }
            int ocupantes = tile.getOcupantes();
            if (ocupantes > 0) {
                std::cout << simbBioma << " " << ocupantes << " ";
            } else {
                std::cout << simbBioma << " . ";
            }
        }
        std::cout << std::endl;
    }
}