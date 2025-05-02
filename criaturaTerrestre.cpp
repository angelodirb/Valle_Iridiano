#include "criaturaTerrestre.h"

CriaturaTerrestre::CriaturaTerrestre(int x_, int y_, int vida_)
    : Criatura(x_, y_, vida_, 10) {}

string CriaturaTerrestre::tipo() const {
    return "terrestre";
}
