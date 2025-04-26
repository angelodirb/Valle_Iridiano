#ifndef TILE_H
#define TILE_H

#include <string>

class Tile {
private:
    std::string tipo; // Tipo de terreno (ej. "agua", "tierra")
    bool ocupado;     // Indica si el tile está ocupado

public:
    Tile(std::string tipo, bool ocupado);
    std::string getTipo() const;
    bool isOcupado() const;
    void setOcupado(bool estado);

};

#endif // TILE_H