#ifndef CRIATURATERRESTRE_H
#define CRIATURATERRESTRE_H

#include "Criatura.h"

class CriaturaTerrestre : public Criatura {
public:
    CriaturaTerrestre(std::string nombre, int vida, int energia, int x, int y);
    bool puedeMoverA(int nuevaX, int nuevaY, Mapa& mapa) const override;
    void actuar() override;
};

#endif // CRIATURATERRESTRE_H
