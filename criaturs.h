#ifndef CRIATURS_H
#define CRIATURS_H

#include <string>
#include <vector>

class Tile;

class Criatura {
public:
    int x, y;
    int vida;

    Criatura(int x, int y, int vida);
    virtual ~Criatura() = default;

    virtual void mover(std::vector<std::vector<Tile>>& mapa) = 0;
    virtual std::string tipo() const = 0;
};

#endif
