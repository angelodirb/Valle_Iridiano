#ifndef CRIATURA_H
#define CRIATURA_H

#include <string>
#include "json.hpp"
#include "Mapa.h"

class Criatura {
protected:
    std::string nombre;
    int vida;
    int energia;
    int posX;
    int posY;
    std::string tipo;
    int edad; // Agregar atributo edad
    int esperanzaVida; // Agregar atributo esperanza de vida

public:
    Criatura(std::string nombre, int vida, int energia, int x, int y, std::string tipo);
    virtual ~Criatura() = default;

    // Métodos para obtener vida y energía
    int getVida() const { return vida; }
    int getEnergia() const { return energia; }

    // Métodos para obtener edad y esperanza de vida
    int getEdad() const { return edad; } // Método para obtener edad
    int getEsperanzaVida() const { return esperanzaVida; } // Método para obtener esperanza de vida

    // Método para modificar vida
    void setVida(int nuevaVida) { vida = nuevaVida; }

    // Método mover sin parámetros
    virtual void mover() = 0; // Método virtual puro
    virtual void actuar() = 0;

    nlohmann::json toJson() const;
    void fromJson(const nlohmann::json& j);

    // Getter para posición
    int getX() const { return posX; }
    int getY() const { return posY; }

    // Para asignar mapa si se requiere en mover()
    void setMapa(Mapa* mapa) { this->mapa = mapa; }

    void incrementarEdad() { edad++; }

protected:
    Mapa* mapa = nullptr; // Puntero al mapa, opcional para facilitar mover sin parámetros
};

#endif // CRIATURA_H