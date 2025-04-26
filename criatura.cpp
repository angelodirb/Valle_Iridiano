#include "Criatura.h"

Criatura::Criatura(std::string nombre, int vida, int energia, int x, int y, std::string tipo)
    : nombre(nombre), vida(vida), energia(energia), posX(x), posY(y), tipo(tipo) {}

nlohmann::json Criatura::toJson() const {
    return {
            {"nombre", nombre},
            {"vida", vida},
            {"energia", energia},
            {"posX", posX},
            {"posY", posY},
            {"tipo", tipo}
    };
}

void Criatura::fromJson(const nlohmann::json& j) {
    nombre = j.at("nombre").get<std::string>();
    vida = j.at("vida").get<int>();
    energia = j.at("energia").get<int>();
    posX = j.at("posX").get<int>();
    posY = j.at("posY").get<int>();
    tipo = j.at("tipo").get<std::string>();
}