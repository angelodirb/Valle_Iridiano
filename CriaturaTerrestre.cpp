#include "CriaturaTerrestre.h"
#include <iostream>

CriaturaTerrestre::CriaturaTerrestre(std::string nombre, int vida, int energia, int x, int y)
    : Criatura(nombre, vida, energia, x, y, "Terrestre") {}

void CriaturaTerrestre::mover() {
    // Lógica para mover la criatura terrestre
    std::cout << nombre << " se mueve por el terreno terrestre." << std::endl;
}

void CriaturaTerrestre::actuar() {
    // Lógica para actuar, como atacar o defender
    std::cout << nombre << " realiza una acción terrestre." << std::endl;
}