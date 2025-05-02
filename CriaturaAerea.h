#ifndef CRIATURAAEREA_H
#define CRIATURAAEREA_H

#include "Criatura.h"

class CriaturaAerea : public Criatura {
public:
    CriaturaAerea(std::string nombre, int vida, int energia, int x, int y, Mapa* mapa);
    void mover() override;
    void actuar() override;
};

#endif // CRIATURAAEREA_H