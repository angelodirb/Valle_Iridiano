//
// Created by HOME on 02/05/2025.
//

#ifndef CRIATURASTERRESTRES_H
#define CRIATURASTERRESTRES_H



#include "criaturas.h"
#include <vector>

class CriaturaTerrestre : virtual public Criatura {
public:
    bool camuflaje_activo = false;

    CriaturaTerrestre(int x, int y, int vida);

    bool estaOculta() const;
    std::string tipo() const override;
    void mover(std::vector<std::vector<Tile>>& mapa) override;
};




#endif //CRIATURASTERRESTRES_H
