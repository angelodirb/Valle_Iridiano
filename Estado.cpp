#include "Estado.h"
#include <fstream>
#include <iostream>
#include "CriaturaAerea.h"
#include "CriaturaTerrestre.h"

using json = nlohmann::json;

void guardarEstado(const std::vector<std::unique_ptr<Criatura>>& criaturas, const Mapa& mapa) {
    json estado;
    estado["criaturas"] = json::array();
    for (const auto& c : criaturas) {
        estado["criaturas"].push_back(c->toJson());
    }

    estado["mapa"] = json::array();
    for (int i = 0; i < mapa.getFilas(); ++i) {
        json fila = json::array();
        for (int j = 0; j < mapa.getColumnas(); ++j) {
            fila.push_back(static_cast<int>(mapa.getTile(i, j)->getBioma().getTipo()));
        }
        estado["mapa"].push_back(fila);
    }

    std::ofstream out("partida.json");
    out << estado.dump(4);
}

void cargarEstado(std::vector<std::unique_ptr<Criatura>>& criaturas, Mapa& mapa) {
    std::ifstream in("partida.json");
    if (!in.is_open() || in.peek() == std::ifstream::traits_type::eof()) return;

    json estado;
    in >> estado;

    for (const auto& jc : estado["criaturas"]) {
        int x = jc["posX"], y = jc["posY"], vida = jc["vida"];
        std::string tipo = jc["tipo"];
        Criatura* c = nullptr;

        if (tipo == "Aérea" || tipo == "aerea" || tipo == "AEREA")
            c = new CriaturaAerea("CriaturaAerea", vida, 100, x, y, &mapa);
        else if (tipo == "Terrestre" || tipo == "terrestre" || tipo == "TERRESTRE")
            c = new CriaturaTerrestre("CriaturaTerrestre", vida, 100, x, y, &mapa);

        if (c) {
            criaturas.push_back(std::unique_ptr<Criatura>(c));
            const Tile* tile = mapa.getTile(y, x); // Obtener el puntero a const Tile
            if (tile) {
                const_cast<Tile*>(tile)->agregarOcupante(); // Usar const_cast para modificar el tile
            }
        }
    }
}