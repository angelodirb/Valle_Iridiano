#ifndef MAPA_H
#define MAPA_H

#include "Tile.h"
#include <vector>

class Mapa {
public:
    Mapa(int filas, int columnas);
    void inicializarMapa();
    Tile* getTile(int fila, int columna);
    void mostrarMapa() const;

private:
    int filas;                     // Número de filas en el mapa
    int columnas;                  // Número de columnas en el mapa
    std::vector<std::vector<Tile>> tiles; // Matriz de tiles
};

#endif // MAPA_H