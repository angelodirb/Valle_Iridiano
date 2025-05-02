#ifndef ESTADO_H
#define ESTADO_H

#include <vector>
#include <memory>
#include "Mapa.h"
#include "Criatura.h"
#include "json.hpp"

void guardarEstado(const std::vector<std::unique_ptr<Criatura>>& criaturas, const Mapa& mapa);
void cargarEstado(std::vector<std::unique_ptr<Criatura>>& criaturas, Mapa& mapa);

#endif // ESTADO_H