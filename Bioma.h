#ifndef BIOMA_H
#define BIOMA_H

#include <string>

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

    // Métodos para convertir enums a strings
    static std::string tipoBiomaToString(TipoBioma tipo);
    static std::string estadoTerrenoToString(EstadoTerreno estado);

    // Método para obtener el impacto del bioma
    void aplicarEfecto(int& vida, int& energia, const std::string& nombre) const;
};

#endif // BIOMA_H
