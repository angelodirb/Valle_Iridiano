#ifndef BIOMA_H
#define BIOMA_H

class Bioma {
public:
    enum class TipoBioma { BOSQUE, DESIERTO, MONTAÑA };
    enum class EstadoTerreno { NORMAL, FERTIL, LETAL, CORRUPTO };

private:
    TipoBioma tipo;
    EstadoTerreno estado;

public:
    Bioma(TipoBioma tipo, EstadoTerreno estado);
    TipoBioma getTipo() const;
    EstadoTerreno getEstado() const;
    void setTipo(TipoBioma nuevoTipo);
    void setEstado(EstadoTerreno nuevoEstado);
};

#endif // BIOMA_H