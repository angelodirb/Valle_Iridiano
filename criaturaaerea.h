#ifndef CRIATURAAEREA_H
#define CRIATURAAEREA_H

#include "criatura.h"

class CriaturaAerea : virtual public Criatura {
public:
    int altura_vuelo = 1;

    CriaturaAerea(int x, int y, int vida);
    bool puedeSobrevolar() const;
    std::string tipo() const override;
    void mover(std::vector<std::vector<Tile>>& mapa) override;
};

#endif
