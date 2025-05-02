#ifndef CRIATURAAEREA_H
#define CRIATURAAEREA_H

#include "criaturs.h"

class CriaturaAerea : public Criatura {
public:
    CriaturaAerea(int x_, int y_, int vida_);
    string tipo() const override;
};

#endif
