//
// Created by HOME on 02/05/2025.
//


#include "ecosistema.h"
#include <iostream>
#include <fstream>
#include "json.hpp"
#include <cstdlib>
#include <algorithm>

using json = nlohmann::json;
using namespace std;

const double PROB_REPRODUCCION = 0.4;
const double PROB_ATAQUE = 0.3;

Ecosistema::Ecosistema() : mapa(MAPA_TAM, vector<Tile>(MAPA_TAM)) {
    cargarEstado();
    if (criaturas.empty()) {
        for (int i = 0; i < MAPA_TAM; ++i) {
            for (int j = 0; j < MAPA_TAM; ++j) {
                if (i < MAPA_TAM * 0.3)
                    mapa[i][j].tipoTerreno = FERTIL;
                else if (i < MAPA_TAM * 0.7)
                    mapa[i][j].tipoTerreno = NEUTRO;
                else
                    mapa[i][j].tipoTerreno = LETAL;
            }
        }
    }
}

void Ecosistema::mostrarMapa() const {
    for (int i = 0; i < MAPA_TAM; ++i) {
        for (int j = 0; j < MAPA_TAM; ++j) {
            mapa[i][j].mostrar();
            cout << " ";
        }
        cout << endl;
    }
}

void Ecosistema::mostrarResumen() const {
    int t = 0, a = 0, h = 0;
    for (const auto& c : criaturas) {
        if (c->tipo() == "terrestre") ++t;
        else if (c->tipo() == "aerea") ++a;
        else if (c->tipo() == "hibrida") ++h;
    }
    cout << "Criaturas terrestres: " << t << endl;
    cout << "Criaturas aereas: " << a << endl;
    cout << "Criaturas hibridas: " << h << endl;
}

void Ecosistema::crearCriatura(const string& tipo, int x, int y, int vida) {
    if (x < 0 || x >= MAPA_TAM || y < 0 || y >= MAPA_TAM) {
        cout << "Posición inválida.\n";
        return;
    }

    unique_ptr<Criatura> c;
    if (tipo == "terrestre") c = make_unique<CriaturaTerrestre>(x, y, vida);
    else if (tipo == "aerea") c = make_unique<CriaturaAerea>(x, y, vida);
    else if (tipo == "hibrida") c = make_unique<CriaturaHibrida>(x, y, vida);
    else {
        cout << "Tipo inválido.\n";
        return;
    }

    mapa[y][x].criaturas.push_back(c.get());
    criaturas.push_back(std::move(c));
}

void Ecosistema::ejecutarCiclo() {
    for (auto& c : criaturas)
        c->mover(mapa);

    procesarInteracciones();
    actualizarEstado();
}

void Ecosistema::procesarInteracciones() {
    for (int i = 0; i < MAPA_TAM; ++i) {
        for (int j = 0; j < MAPA_TAM; ++j) {
            auto& tile = mapa[i][j];
            auto& cs = tile.criaturas;

            if (cs.size() < 2) continue;

            vector<Criatura*> terrestres, aereas, hibridas;
            for (auto* c : cs) {
                if (c->tipo() == "terrestre") terrestres.push_back(c);
                else if (c->tipo() == "aerea") aereas.push_back(c);
                else if (c->tipo() == "hibrida") hibridas.push_back(c);
            }

            double probRepro = PROB_REPRODUCCION;
            if (tile.tipoTerreno == FERTIL) probRepro += 0.1;

            if (terrestres.size() >= 2 && (rand() / (double)RAND_MAX) < probRepro) {
                auto c = make_unique<CriaturaTerrestre>(j, i, 100);
                tile.criaturas.push_back(c.get());
                criaturas.push_back(std::move(c));
                cout << "Reproducción terrestre en (" << j << "," << i << ")\n";
            }
            if (aereas.size() >= 2 && (rand() / (double)RAND_MAX) < probRepro) {
                auto c = make_unique<CriaturaAerea>(j, i, 100);
                tile.criaturas.push_back(c.get());
                criaturas.push_back(std::move(c));
                cout << "Reproducción aérea en (" << j << "," << i << ")\n";
            }
            if (hibridas.size() >= 2 && (rand() / (double)RAND_MAX) < probRepro) {
                auto c = make_unique<CriaturaHibrida>(j, i, 100);
                tile.criaturas.push_back(c.get());
                criaturas.push_back(std::move(c));
                cout << "Reproducción híbrida en (" << j << "," << i << ")\n";
            }

            for (size_t k = 0; k + 1 < cs.size(); ++k) {
                if ((rand() / (double)RAND_MAX) < PROB_ATAQUE) {
                    int daño = cs[k]->vida / 3;
                    cs[k + 1]->vida -= daño;
                    cout << cs[k]->tipo() << " atacó a otra en (" << j << "," << i << ") e hizo " << daño << " de daño.\n";
                }
            }
        }
    }
}

void Ecosistema::actualizarEstado() {
    for (auto& c : criaturas) {
        c->edad++;
        if (mapa[c->y][c->x].tipoTerreno == LETAL)
            c->vida -= 1;
    }

    for (auto it = criaturas.begin(); it != criaturas.end();) {
        if ((*it)->vida <= 0 || (*it)->edad >= (*it)->esperanza_vida) {
            auto& tile = mapa[(*it)->y][(*it)->x];
            tile.criaturas.erase(
                std::remove(tile.criaturas.begin(), tile.criaturas.end(), it->get()),
                tile.criaturas.end()
            );
            cout << "Una criatura " << (*it)->tipo() << " ha muerto en (" << (*it)->x << "," << (*it)->y << ")\n";
            it = criaturas.erase(it);
        } else {
            ++it;
        }
    }
}

void Ecosistema::guardarEstado() const {
    json estado;
    estado["criaturas"] = json::array();

    for (const auto& c : criaturas) {
        estado["criaturas"].push_back({
            {"x", c->x}, {"y", c->y}, {"vida", c->vida},
            {"edad", c->edad}, {"esperanza_vida", c->esperanza_vida},
            {"tipo", c->tipo()}
        });
    }

    estado["mapa"] = json::array();
    for (int i = 0; i < MAPA_TAM; ++i) {
        json fila = json::array();
        for (int j = 0; j < MAPA_TAM; ++j)
            fila.push_back(mapa[i][j].tipoTerreno);
        estado["mapa"].push_back(fila);
    }

    ofstream out("partida.json");
    out << estado.dump(4);
}

void Ecosistema::cargarEstado() {
    ifstream in("partida.json");
    if (!in.is_open() || in.peek() == ifstream::traits_type::eof()) return;

    json estado;
    try {
        in >> estado;
    } catch (...) {
        cerr << "Error leyendo JSON\n";
        return;
    }

    for (const auto& jc : estado["criaturas"]) {
        int x = jc["x"], y = jc["y"], vida = jc["vida"];
        int edad = jc["edad"], esperanza = jc["esperanza_vida"];
        string tipo = jc["tipo"];
        Criatura* c = nullptr;

        if (tipo == "terrestre") c = new CriaturaTerrestre(x, y, vida);
        else if (tipo == "aerea") c = new CriaturaAerea(x, y, vida);
        else if (tipo == "hibrida") c = new CriaturaHibrida(x, y, vida);

        if (c) {
            c->edad = edad;
            c->esperanza_vida = esperanza;
            mapa[y][x].criaturas.push_back(c);
            criaturas.push_back(unique_ptr<Criatura>(c));
        }
    }

    if (estado.contains("mapa")) {
        const auto& jmapa = estado["mapa"];
        for (int i = 0; i < MAPA_TAM; ++i)
            for (int j = 0; j < MAPA_TAM; ++j)
                mapa[i][j].tipoTerreno = static_cast<TipoTerreno>(jmapa[i][j].get<int>());
    }
}
