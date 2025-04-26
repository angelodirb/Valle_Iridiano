#include "Tile.h"

Tile::Tile(std::string tipo, bool ocupado) : tipo(tipo), ocupado(ocupado) {}

std::string Tile::getTipo() const {
    return tipo;
}

bool Tile::isOcupado() const {
    return ocupado;
}

void Tile::setOcupado(bool estado) {
    ocupado = estado;
}