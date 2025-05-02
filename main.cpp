#include <iostream>
#include "Mapa.h"
#include "CriaturaAerea.h"
#include "CriaturaTerrestre.h"

int main() {
    system("chcp 65001");
    Mapa mapa(6, 6); // Mapa de 6x6

    // No es necesario inicializar biomas aquí, ya se hace en Mapa::inicializarMapa()

    CriaturaTerrestre tigre("Tigre", 100, 50, 0, 0, &mapa);
    CriaturaAerea aguila("Águila", 80, 70, 4, 4, &mapa);

    // Agregar criaturas a los tiles correspondientes
    Tile* tileTigre = mapa.getTile(0, 0);
    if (tileTigre) tileTigre->agregarOcupante(); // Usar agregarOcupante

    Tile* tileAguila = mapa.getTile(4, 4);
    if (tileAguila) tileAguila->agregarOcupante(); // Usar agregarOcupante

    std::cout << "Mapa inicial:\n";
    mapa.mostrarMapa();

    // Mover criaturas
    tigre.mover();
    aguila.mover();

    std::cout << "\nMapa después de mover criaturas:\n";
    mapa.mostrarMapa();

    // Mostrar estado de las criaturas
    std::cout << "Estado de las criaturas después de moverse:\n";
    std::cout << "Tigre - Vida: " << tigre.getVida() << ", Energía: " << tigre.getEnergia() << "\n";
    std::cout << "Águila - Vida: " << aguila.getVida() << ", Energía: " << aguila.getEnergia() << "\n";

    tigre.actuar();
    aguila.actuar();

    return 0;
}