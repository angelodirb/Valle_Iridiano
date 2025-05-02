#include <iostream>
#include "Mapa.h"
#include "CriaturaAerea.h"
#include "CriaturaTerrestre.h"
int main() {
    system("chcp 65001");
    Mapa mapa(5, 5);

    // Inicializar biomas en el mapa
    for (int i = 0; i < mapa.getFilas(); ++i) {
        for (int j = 0; j < mapa.getColumnas(); ++j) {
            // Asignar biomas de forma aleatoria para el ejemplo
            Bioma::TipoBioma tipo = static_cast<Bioma::TipoBioma>(std::rand() % 3);
            Bioma::EstadoTerreno estado = static_cast<Bioma::EstadoTerreno>(std::rand() % 4);
            mapa.getTile(i, j)->setBioma(Bioma(tipo, estado));
        }
    }

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