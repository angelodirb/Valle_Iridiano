#ifndef CRIATURS_H
#define CRIATURS_H

#include <string>
using namespace std;

class Criatura {
public:
    int x, y, edad, vida, esperanza_vida;
    Criatura(int x_, int y_, int vida_, int esperanza_vida_);
    virtual string tipo() const = 0;
    virtual void atacar(Criatura* otra);
    virtual ~Criatura() {}
};

#endif
