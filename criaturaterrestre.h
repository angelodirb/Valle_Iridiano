#ifndef CRIATURATERRESTRE_H
#define CRIATURATERRESTRE_H

#include "Criatura.h"
#include "Tile.h"
#include <vector>

class CriaturaTerrestre : virtual public Criatura {
public:
    bool camuflaje_activo = false;

    CriaturaTerrestre(int x, int y, int vida);

    bool estaOculta() const;
    std::string tipo() const override;
    void mover(std::vector<std::vector<Tile>>& mapa) override;
};

#endif // CRIATURATERRESTRE_H
