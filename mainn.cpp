#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include "Tile.h"
#include "Criaturas.h"
#include "Utilidades.h"

const int MAPA_TAM = 10;

int main() {
    srand(time(0));

    std::vector<std::vector<Tile>> mapa(MAPA_TAM, std::vector<Tile>(MAPA_TAM));
    Criatura* criatura = nullptr;

    while (true) {
        std::cout << "\n--- Mapa ---\n";
        mostrarMapa(mapa);

        std::cout << "\nComandos disponibles:\n";
        std::cout << "1. crear x y\n";
        std::cout << "2. mover (movimiento aleatorio)\n";
        std::cout << "3. salir\n";

        std::string comando;
        std::cin >> comando;

        if (comando == "crear") {
            int x, y;
            std::cin >> x >> y;
            if (x >= 0 && x < MAPA_TAM && y >= 0 && y < MAPA_TAM) {
                if (criatura) {
                    mapa[criatura->y][criatura->x].tieneCriatura = false;
                    delete criatura;
                }
                criatura = new Criatura(x, y);
                mapa[y][x].tieneCriatura = true;
            } else {
                std::cout << "Posición inválida.\n";
            }
        } else if (comando == "mover") {
            if (!criatura) {
                std::cout << "Primero crea una criatura.\n";
                continue;
            }
            moverCriaturaAleatoria(mapa, *criatura);
        } else if (comando == "salir") {
            break;
        } else {
            std::cout << "Comando no reconocido.\n";
        }
    }

    delete criatura;
    return 0;
}
