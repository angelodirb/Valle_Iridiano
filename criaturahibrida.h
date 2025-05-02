#ifndef CRIATURAHIBRIDA_H
#define CRIATURAHIBRIDA_H

#include "criaturs.h"

class CriaturaHibrida : public Criatura {
public:
    CriaturaHibrida(int x_, int y_, int vida_);
    string tipo() const override;
};

#endif
