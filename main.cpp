#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include <memory>
#include "Mapa.h"
#include "CriaturaAerea.h"
#include "CriaturaTerrestre.h"
#include "Estado.h" // Archivo con guardarEstado y cargarEstado

const int MAPA_TAM = 6;

void interacciones(Mapa& mapa, std::vector<std::unique_ptr<Criatura>>& criaturas) {
    for (int i = 0; i < MAPA_TAM; ++i) {
        for (int j = 0; j < MAPA_TAM; ++j) {
            const Tile* tile = mapa.getTile(i, j); // Obtener puntero a const Tile

            if (!tile) continue;

            int ocupantes = tile->getOcupantes(); // Obtener cantidad de ocupantes

            if (ocupantes <= 1) continue;

            // Aquí puedes implementar otras lógicas de interacciones
        }
    }

    for (auto it = criaturas.begin(); it != criaturas.end();) {
        auto& c = *it;

        c->incrementarEdad(); // Incrementar edad de la criatura

        const Tile* tile = mapa.getTile(c->getY(), c->getX());
        if (tile && tile->getBioma().getEstado() == Bioma::EstadoTerreno::LETAL) {
            c->setVida(c->getVida() - 1); // Modificar vida
        }

        if (c->getVida() <= 0 || c->getEdad() >= c->getEsperanzaVida()) {
            if (tile) {
                const_cast<Tile*>(tile)->eliminarOcupante(); // Eliminar ocupante
            }
            std::cout << "Una criatura ha muerto en (" << c->getX() << "," << c->getY() << ")\n";
            it = criaturas.erase(it); // Eliminar criatura
        } else {
            ++it;
        }
    }
}

int main() {
    system("chcp 65001");
    Mapa mapa(MAPA_TAM, MAPA_TAM);
    std::vector<std::unique_ptr<Criatura>> criaturas;

    srand(static_cast<unsigned>(time(nullptr)));

    // Cargar estado de la partida si existe
    cargarEstado(criaturas, mapa);

    if (criaturas.empty()) {
        mapa.inicializarMapa();
    }

    while (true) {
        std::cout << "\n--- Mapa ---\n";
        mapa.mostrarMapa();

        std::cout << "\nComandos:\n";
        std::cout << "crear\n";
        std::cout << "ciclos\n";
        std::cout << "salir\n";

        std::string comando;
        std::cin >> comando;

        if (comando == "crear") {
            std::string tipo;
            int x, y, vida;

            std::cout << "Ingrese el tipo de criatura (terrestre/aerea): ";
            std::cin >> tipo;

            std::cout << "Ingrese la posición X (0 a " << MAPA_TAM - 1 << "): ";
            std::cin >> x;

            std::cout << "Ingrese la posición Y (0 a " << MAPA_TAM - 1 << "): ";
            std::cin >> y;

            std::cout << "Ingrese la vida de la criatura: ";
            std::cin >> vida;

            if (x < 0 || x >= MAPA_TAM || y < 0 || y >= MAPA_TAM) {
                std::cout << "Posición inválida." << std::endl;
                continue;
            }

            if (tipo == "terrestre") {
                criaturas.push_back(std::make_unique<CriaturaTerrestre>("CriaturaTerrestre", vida, 100, x, y, &mapa));
                const_cast<Tile*>(mapa.getTile(y, x))->agregarOcupante(); // Agregar ocupante
            } else if (tipo == "aerea") {
                criaturas.push_back(std::make_unique<CriaturaAerea>("CriaturaAerea", vida, 100, x, y, &mapa));
                const_cast<Tile*>(mapa.getTile(y, x))->agregarOcupante(); // Agregar ocupante
            } else {
                std::cout << "Tipo inválido. Usa 'terrestre' o 'aerea'." << std::endl;
            }
        } else if (comando == "ciclos") {
            for (auto& c : criaturas) {
                c->mover(); // Mover criaturas
            }
            interacciones(mapa, criaturas); // Lógica de interacciones
        } else if (comando == "salir") {
            guardarEstado(criaturas, mapa); // Guardar estado
            std::cout << "Partida guardada correctamente." << std::endl;
            break;
        } else {
            std::cout << "Comando no reconocido. Intente de nuevo.\n";
        }
    }

    return 0;
}