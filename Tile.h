#ifndef TILE_H
#define TILE_H

#include <string>
#include "Bioma.h" // Incluir la clase Bioma

class Tile {
public:
    Tile(std::string tipo, Bioma bioma); // Constructor
    std::string getTipo() const;
    int getOcupantes() const;          // Obtener cantidad ocupante
    void agregarOcupante();            // Añadir ocupante (+1)
    void eliminarOcupante();           // Eliminar ocupante (-1)
    Bioma getBioma() const; // Método para obtener el bioma
    void setBioma(const Bioma& bioma); // Método para establecer el bioma

private:
    std::string tipo; // Tipo de terreno (ej. "agua", "tierra")
    Bioma bioma;     // Bioma asociado al tile
    int ocupantes;   // Número de criaturas en el tile
};

#endif // TILE_H