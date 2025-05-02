#include "criaturs.h"
#include <iostream>

Criatura::Criatura(int x_, int y_, int vida_, int esperanza_vida_)
    : x(x_), y(y_), edad(0), vida(vida_), esperanza_vida(esperanza_vida_) {}

void Criatura::atacar(Criatura* otra) {
    int daño = vida / 3;
    otra->vida -= daño;
    std::cout << tipo() << " atacó e hizo " << daño << " de daño.\n";
}
