#include "ecosistema.h"
#include <iostream>
#include <string>

int main() {
    Ecosistema eco;

    while (true) {
        eco.mostrarResumen();
        std::cout << "\n--- Valle Iridiano ---\n";
        eco.mostrarMapa();

        std::cout << "\nComandos:\ncrear tipo x y vida\nciclos\nsalir\n";

        std::string comando;
        std::cin >> comando;

        if (comando == "crear") {
            std::string tipo;
            int x, y, vida;
            std::cin >> tipo >> x >> y >> vida;
            eco.crearCriatura(tipo, x, y, vida);

        } else if (comando == "ciclos") {
            eco.ejecutarCiclo();
        } else if (comando == "salir") {
            eco.guardarEstado();
            break;
        } else {
            std::cout << "Comando no reconocido.\n";
        }
    }

    return 0;
}

