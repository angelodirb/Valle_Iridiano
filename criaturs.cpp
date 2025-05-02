#include "criaturs.h"
#include <iostream>

Criatura::Criatura(int x_, int y_, int vida_, int esperanza_vida_)
    : x(x_), y(y_), edad(0), vida(vida_), esperanza_vida(esperanza_vida_) {}

void Criatura::atacar(Criatura* otra) {
    int daño = vida / 3;
    otra->vida -= daño;
    std::cout << tipo() << " atacó e hizo " << daño << " de daño.\n";
}

CriaturaTerrestre::CriaturaTerrestre(int x_, int y_, int vida_)
    : Criatura(x_, y_, vida_, 10) {}

std::string CriaturaTerrestre::tipo() const {
    return "terrestre";
}

CriaturaAerea::CriaturaAerea(int x_, int y_, int vida_)
    : Criatura(x_, y_, vida_, 8) {}

std::string CriaturaAerea::tipo() const {
    return "aerea";
}

CriaturaHibrida::CriaturaHibrida(int x_, int y_, int vida_)
    : Criatura(x_, y_, vida_, 6) {}

std::string CriaturaHibrida::tipo() const {
    return "hibrida";
}
