#include <iostream>
#include <vector>
#include <string>
#include "mapa.h"
#include "criatura.h"

using namespace std;

int main() {
    vector<vector<Tile>> mapa(MAPA_TAM, vector<Tile>(MAPA_TAM));
    Criatura* criatura = nullptr;

    while (true) {
        cout << "\n--- Mapa ---\n";
        mostrarMapa(mapa);

        cout << "\nComandos disponibles:\n";
        cout << "1. crear x y\n";
        cout << "2. mover direccion (arriba/abajo/izquierda/derecha)\n";
        cout << "3. salir\n";

        string comando;
        cin >> comando;

        if (comando == "crear") {
            int x, y;
            cin >> x >> y;
            if (x >= 0 && x < MAPA_TAM && y >= 0 && y < MAPA_TAM) {
                if (criatura) delete criatura; // Borra la anterior si ya había
                criatura = new Criatura(x, y);
                mapa[y][x].tieneCriatura = true;
            } else {
                cout << "Posición inválida.\n";
            }
        } else if (comando == "mover") {
            if (!criatura) {
                cout << "Primero crea una criatura.\n";
                continue;
            }
            string direccion;
            cin >> direccion;
            moverCriatura(mapa, *criatura, direccion);
        } else if (comando == "salir") {
            break;
        } else {
            cout << "Comando no reconocido.\n";
        }
    }

    delete criatura; // Liberar memoria
    return 0;
}

