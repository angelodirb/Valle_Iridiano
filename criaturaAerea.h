#ifndef CRIATURA_TERRESTRE_H
#define CRIATURA_TERRESTRE_H

#include "criaturs.h"

class CriaturaTerrestre : public Criatura {
public:
    CriaturaTerrestre(int x, int y, int vida);
    std::string tipo() const override;
    void mover(std::vector<std::vector<Tile>>& mapa) override;
};

#endif
