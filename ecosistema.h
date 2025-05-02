//
// Created by HOME on 02/05/2025.
//

#ifndef ECOSISTEMA_H
#define ECOSISTEMA_H





#include "tile.h"
#include "criaturasterrestres.h"
#include "criaturasaereas.h"
#include "criaturashibridas.h"
#include <vector>
#include <memory>
#include <string>

    class Ecosistema {
    public:
        static const int MAPA_TAM = 15;

        Ecosistema();

        void mostrarMapa() const;
        void mostrarResumen() const;
        void crearCriatura(const std::string& tipo, int x, int y, int vida);
        void ejecutarCiclo();
        void guardarEstado() const;

    private:
        std::vector<std::vector<Tile>> mapa;
        std::vector<std::unique_ptr<Criatura>> criaturas;

        void cargarEstado();
        void procesarInteracciones();
        void actualizarEstado();
    };



#endif //ECOSISTEMA_H
