#ifndef CRIATURA_H
#define CRIATURA_H

#include <string>
#include "json.hpp"
#include "Mapa.h"


class Criatura {
protected:
    std::string nombre;
    int vida;
    int X;
    int Y;

public:
    Criatura(std::string nombre, int x, int y);
    virtual bool puedeMoverA(int nuevaX, int nuevaY, Mapa& mapa) const = 0;
    virtual void mover(int x,int y, Mapa& mapa);
    virtual void actuar();
    int getX() const;
    int getY() const;
    virtual nlohmann::json toJson() const;
    virtual void fromJson(const nlohmann::json& j);
};

#endif // CRIATURA_H