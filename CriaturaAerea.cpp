#include "CriaturaAerea.h"
#include <iostream>

CriaturaAerea::CriaturaAerea(std::string nombre, int vida, int energia, int x, int y)
    : Criatura(nombre, vida, energia, x, y, "Aérea") {}

void CriaturaAerea::mover() {
    // Lógica para mover la criatura aérea
    std::cout << nombre << " vuela por el aire." << std::endl;
}

void CriaturaAerea::actuar() {
    // Lógica para actuar, como atacar o defender
    std::cout << nombre << " realiza una acción aérea." << std::endl;
}