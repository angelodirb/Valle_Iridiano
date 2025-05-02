#ifndef MAPA_H
#define MAPA_H

const int MAPA_TAM = 10;

class Tile {
public:
    bool tieneCriatura = false;

    char mostrar() const {
        return tieneCriatura ? 'C' : '.';
    }
};


#endif //MAPA_H
