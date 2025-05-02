#include "criaturaAerea.h"

CriaturaAerea::CriaturaAerea(int x_, int y_, int vida_)
    : Criatura(x_, y_, vida_, 8) {}

string CriaturaAerea::tipo() const {
    return "aerea";
}
