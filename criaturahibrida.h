#ifndef CRIATURA_HIBRIDA_H
#define CRIATURA_HIBRIDA_H

#include "CriaturaTerrestre.h"
#include "CriaturaAerea.h"

class CriaturaHibrida : public CriaturaTerrestre, public CriaturaAerea {
public:
    CriaturaHibrida(int x, int y, int vida);
    std::string tipo() const override;
    void mover(std::vector<std::vector<Tile>>& mapa) override;
    bool estaOculta() const;
    bool puedeSobrevolar() const;
};

#endif
