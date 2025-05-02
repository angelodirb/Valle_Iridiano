#ifndef CRIATURA_H
#define CRIATURA_H

#include <iostream>
#include <string>

class Criatura {
public:
    int x, y, edad, vida, esperanza_vida;
    Criatura(int x_, int y_, int vida_, int esperanza_vida_);
    virtual std::string tipo() const = 0;
    virtual void atacar(Criatura* otra);
    virtual ~Criatura() {}
};

class CriaturaTerrestre : public Criatura {
public:
    CriaturaTerrestre(int x_, int y_, int vida_);
    std::string tipo() const override;
};

class CriaturaAerea : public Criatura {
public:
    CriaturaAerea(int x_, int y_, int vida_);
    std::string tipo() const override;
};

class CriaturaHibrida : public Criatura {
public:
    CriaturaHibrida(int x_, int y_, int vida_);
    std::string tipo() const override;
};

#endif
