#ifndef CRIATURA_H
#define CRIATURA_H

#include <string>
#include <nlohmann/json.hpp>

class Criatura {
protected:
    std::string nombre;
    int vida;
    int energia;
    int posX;
    int posY;
    std::string tipo;

public:
    Criatura(std::string nombre, int vida, int energia, int x, int y, std::string tipo);
    virtual void mover() = 0; // Método virtual puro
    virtual void actuar() = 0; // Método virtual puro
    virtual nlohmann::json toJson() const;
    virtual void fromJson(const nlohmann::json& j);
};

#endif // CRIATURA_H