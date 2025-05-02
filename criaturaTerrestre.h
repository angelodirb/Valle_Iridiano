#ifndef CRIATURATERRESTRE_H
#define CRIATURATERRESTRE_H

#include "criatur.h"

class CriaturaTerrestre : public Criatura {
public:
    CriaturaTerrestre(int x_, int y_, int vida_);
    string tipo() const override;
};

#endif
