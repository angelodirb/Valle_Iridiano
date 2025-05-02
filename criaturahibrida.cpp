#include "criaturahibrida.h"

CriaturaHibrida::CriaturaHibrida(int x_, int y_, int vida_)
    : Criatura(x_, y_, vida_, 6) {}

string CriaturaHibrida::tipo() const {
    return "hibrida";
}
//
// Created by anto2 on 5/2/2025.
//

#include "criaturahibrida.h"
