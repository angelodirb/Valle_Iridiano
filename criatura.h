#ifndef CRIATURA_H
#define CRIATURA_H

#include <string>
#include <vector>

class Tile;

class Criatura {
public:
    int x, y;
    int vida;
    int edad = 0;
    int esperanza_vida;

    Criatura(int x, int y, int vida);
    virtual ~Criatura() {}
    virtual std::string tipo() const = 0;
    virtual void mover(std::vector<std::vector<Tile>>& mapa) = 0;
};

#endif
