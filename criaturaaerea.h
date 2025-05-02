#ifndef CRIATURA_AEREA_H
#define CRIATURA_AEREA_H

#include "Criatura.h"

class CriaturaAerea : virtual public Criatura {
public:
    int altura_vuelo = 1;

    CriaturaAerea(int x, int y, int vida);
    std::string tipo() const override;
    bool puedeSobrevolar() const;
    void mover(std::vector<std::vector<Tile>>& mapa) override;
};

#endif
