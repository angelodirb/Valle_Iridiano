#include "Tile.h"

Tile::Tile(std::string tipo, Bioma bioma)
    : tipo(tipo), bioma(bioma), ocupantes(0) {} // Inicializar ocupantes en 0

std::string Tile::getTipo() const {
    return tipo;
}

int Tile::getOcupantes() const {
    return ocupantes; // Retorna la cantidad de ocupantes
}

void Tile::agregarOcupante() {
    ocupantes++; // Incrementa el contador de ocupantes
}

void Tile::eliminarOcupante() {
    if (ocupantes > 0) {
        ocupantes--; // Decrementa el contador de ocupantes
    }
}

Bioma Tile::getBioma() const {
    return bioma; // Retorna el bioma asociado al tile
}

void Tile::setBioma(const Bioma& bioma) {
    this->bioma = bioma; // Establece el bioma asociado al tile
}