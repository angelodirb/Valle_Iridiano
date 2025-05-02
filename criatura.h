#ifndef CRIATURA_H
#define CRIATURA_H

#include <vector>
#include <string>

class Tile;

class Criatura {
public:
    int x, y;
    int vida;
    int edad = 0;
    int esperanza_vida;
    virtual std::string tipo() const = 0;

    Criatura(int x, int y, int vida);
    virtual ~Criatura() {}

    virtual void mover(std::vector<std::vector<Tile>>& mapa) = 0;
};

#endif // CRIATURA_H
