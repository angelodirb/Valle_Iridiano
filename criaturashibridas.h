//
// Created by HOME on 02/05/2025.
//

#ifndef CRIATURASHIBRIDAS_H
#define CRIATURASHIBRIDAS_H



#include "criaturasterrestres.h"
#include "criaturasaereas.h"

class CriaturaHibrida : public CriaturaTerrestre, public CriaturaAerea {
public:
    CriaturaHibrida(int x, int y, int vida);

    std::string tipo() const override;
    void mover(std::vector<std::vector<Tile>>& mapa) override;

    bool estaOculta() const;
    bool puedeSobrevolar() const;
};



#endif //CRIATURASHIBRIDAS_H
