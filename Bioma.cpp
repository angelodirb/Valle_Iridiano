#include "Bioma.h"

Bioma::Bioma(TipoBioma tipo, EstadoTerreno estado) : tipo(tipo), estado(estado) {}

Bioma::TipoBioma Bioma::getTipo() const { return tipo; }
Bioma::EstadoTerreno Bioma::getEstado() const { return estado; }

void Bioma::setTipo(TipoBioma nuevoTipo) { tipo = nuevoTipo; }
void Bioma::setEstado(EstadoTerreno nuevoEstado) { estado = nuevoEstado; }