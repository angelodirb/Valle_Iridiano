#ifndef CRIATURES_H
#define CRIATURES_H

#include <vector>
#include "tiles.h"

class Criatura {
public:
    int x, y;
    Criatura(int x, int y);
    virtual ~Criatura();
    virtual void mover(std::vector<std::vector<Tile>>& mapa) = 0;
};

class CriaturaTerrestre : public Criatura {
public:
    CriaturaTerrestre(int x, int y);
    void mover(std::vector<std::vector<Tile>>& mapa) override;
};

class CriaturaAerea : public Criatura {
public:
    CriaturaAerea(int x, int y);
    void mover(std::vector<std::vector<Tile>>& mapa) override;
};

#endif
