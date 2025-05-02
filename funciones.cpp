#include "mapa.h"
#include "criatura.h"
#include <iostream>

using namespace std;

// Función para mostrar el mapa
void mostrarMapa(const vector<vector<Tile>>& mapa) {
    for (int i = 0; i < MAPA_TAM; ++i) {
        for (int j = 0; j < MAPA_TAM; ++j) {
            cout << mapa[i][j].mostrar() << " ";
        }
        cout << endl;
    }
}

// Función para mover la criatura
void moverCriatura(vector<vector<Tile>>& mapa, Criatura& criatura, const string& direccion) {
    // Quitar criatura de la casilla actual
    mapa[criatura.y][criatura.x].tieneCriatura = false;

    if (direccion == "arriba" && criatura.y > 0) criatura.y--;
    else if (direccion == "abajo" && criatura.y < MAPA_TAM - 1) criatura.y++;
    else if (direccion == "izquierda" && criatura.x > 0) criatura.x--;
    else if (direccion == "derecha" && criatura.x < MAPA_TAM - 1) criatura.x++;
    else cout << "Movimiento inválido o fuera de límites.\n";

    // Poner criatura en la nueva posición
    mapa[criatura.y][criatura.x].tieneCriatura = true;
}