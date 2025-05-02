#ifndef CRIATURAHIBRIDA_H
#define CRIATURAHIBRIDA_H

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

#endif // CRIATURAHIBRIDA_H
