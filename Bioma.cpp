#include "Bioma.h"
#include "iostream"
Bioma::Bioma(TipoBioma tipo, EstadoTerreno estado) : tipo(tipo), estado(estado) {}

Bioma::TipoBioma Bioma::getTipo() const { return tipo; }
Bioma::EstadoTerreno Bioma::getEstado() const { return estado; }

void Bioma::setTipo(TipoBioma nuevoTipo) { tipo = nuevoTipo; }
void Bioma::setEstado(EstadoTerreno nuevoEstado) { estado = nuevoEstado; }

std::string Bioma::tipoBiomaToString(TipoBioma tipo) {
    switch(tipo) {
        case TipoBioma::BOSQUE: return "Bosque";
        case TipoBioma::DESIERTO: return "Desierto";
        case TipoBioma::MONTAÑA: return "Montaña";
        default: return "Desconocido";
    }
}

std::string Bioma::estadoTerrenoToString(EstadoTerreno estado) {
    switch(estado) {
        case EstadoTerreno::NORMAL: return "Normal";
        case EstadoTerreno::FERTIL: return "Fértil";
        case EstadoTerreno::LETAL: return "Letal";
        case EstadoTerreno::CORRUPTO: return "Corrupto";
        default: return "Desconocido";
    }
}

// Método para aplicar efectos del bioma
void Bioma::aplicarEfecto(int& vida, int& energia, const std::string& nombre) const {
    switch (tipo) {
        case TipoBioma::DESIERTO:
            energia -= 10;
        std::cout << nombre << " pierde energía en el desierto debido al calor.\n";
        if (estado == EstadoTerreno::LETAL) {
            vida -= 5;
            std::cout << nombre << " pierde vida en terreno letal del desierto.\n";
        }
        break;
        case TipoBioma::BOSQUE:
            energia += 5;
        std::cout << nombre << " gana energía en el bosque gracias a la abundancia de recursos.\n";
        break;
        case TipoBioma::MONTAÑA:
            vida -= 2;
        std::cout << nombre << " pierde vida en la montaña debido al frío y la altura.\n";
        break;
        default:
            break;
    }
}
