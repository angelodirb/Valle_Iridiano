#include "Criatura.h"

Criatura::Criatura(std::string nombre, int x, int y)
    : nombre(nombre), vida(100), X(x), Y(y) {}

void Criatura::mover(int nuevaX, int nuevaY, Mapa& mapa) {
    if (puedeMoverA(nuevaX, nuevaY, mapa)) {
        X = nuevaX;
        Y = nuevaY;
    }
}

int Criatura::getX() const { return posX; }
int Criatura::getY() const { return posY; }


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