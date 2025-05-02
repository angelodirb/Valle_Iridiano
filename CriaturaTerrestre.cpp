#include "CriaturaTerrestre.h"
#include <iostream>
#include "Tile.h"
#include "Mapa.h"

CriaturaTerrestre::CriaturaTerrestre(std::string nombre, int vida, int energia, int x, int y)
    : Criatura(nombre, vida, energia, x, y, "Terrestre") {}

bool CriaturaTerrestre::puedeMoverA(int nuevaX, int nuevaY, Mapa& mapa) const {
    const Tile* destino = mapa.getTile(nuevaX, nuevaY);
    return destino && (destino->esFertil() || destino->esNeutro());
}

void CriaturaTerrestre::actuar() {
    // Lógica para actuar, como atacar o defender
    std::cout << nombre << " realiza una acción terrestre." << std::endl;
}