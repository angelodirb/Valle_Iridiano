#include <iostream>
#include <vector>
#include <memory>
#include <cstdlib>
#include <ctime>
#include <algorithm>

#include "tiles.h"
#include "criaturaTerrestre.h"
#include "criaturaAerea.h"
#include "criaturahibrida.h"

using namespace std;

const int MAPA_TAM = 10;
const double PROB_REPRODUCCION = 0.2;
const double PROB_ATAQUE = 0.3;

void mostrarMapa(const vector<vector<Tile>>& mapa) {
    for (int i = 0; i < MAPA_TAM; ++i) {
        for (int j = 0; j < MAPA_TAM; ++j) {
            cout << mapa[i][j].criaturas.size() << " ";
        }
        cout << "\n";
    }
}

void interacciones(vector<vector<Tile>>& mapa, vector<unique_ptr<Criatura>>& criaturas) {
    for (int i = 0; i < MAPA_TAM; ++i) {
        for (int j = 0; j < MAPA_TAM; ++j) {
            auto& tile = mapa[i][j];
            vector<Criatura*>& cs = tile.criaturas;

            if (cs.size() < 2) continue;

            vector<Criatura*> terrestres, aereas, hibridas;

            for (auto* c : cs) {
                if (c->tipo() == "terrestre") terrestres.push_back(c);
                else if (c->tipo() == "aerea") aereas.push_back(c);
                else if (c->tipo() == "hibrida") hibridas.push_back(c);
            }

            if (terrestres.size() >= 2 && ((double)rand() / RAND_MAX) < PROB_REPRODUCCION) {
                criaturas.push_back(make_unique<CriaturaTerrestre>(j, i, 100));
                tile.criaturas.push_back(criaturas.back().get());
                cout << "Nueva criatura terrestre nacida en (" << j << "," << i << ")\n";
            }
            if (aereas.size() >= 2 && ((double)rand() / RAND_MAX) < PROB_REPRODUCCION) {
                criaturas.push_back(make_unique<CriaturaAerea>(j, i, 100));
                tile.criaturas.push_back(criaturas.back().get());
                cout << "Nueva criatura aerea nacida en (" << j << "," << i << ")\n";
            }
            if (hibridas.size() >= 2 && ((double)rand() / RAND_MAX) < PROB_REPRODUCCION) {
                criaturas.push_back(make_unique<CriaturaHibrida>(j, i, 100));
                tile.criaturas.push_back(criaturas.back().get());
                cout << "Nueva criatura hibrida nacida en (" << j << "," << i << ")\n";
            }

            for (size_t k = 0; k + 1 < cs.size(); ++k) {
                if (((double)rand() / RAND_MAX) < PROB_ATAQUE) {
                    cs[k]->atacar(cs[k + 1]);
                }
            }
        }
    }

    for (auto& c : criaturas) c->edad++;

    for (auto it = criaturas.begin(); it != criaturas.end(); ) {
        if ((*it)->vida <= 0 || (*it)->edad >= (*it)->esperanza_vida) {
            auto& tile = mapa[(*it)->y][(*it)->x];
            tile.criaturas.erase(remove(tile.criaturas.begin(), tile.criaturas.end(), it->get()), tile.criaturas.end());
            it = criaturas.erase(it);
        } else {
            ++it;
        }
    }
}

int main() {
    srand(time(0));
    vector<vector<Tile>> mapa(MAPA_TAM, vector<Tile>(MAPA_TAM));
    vector<unique_ptr<Criatura>> criaturas;

    criaturas.push_back(make_unique<CriaturaTerrestre>(5, 5, 100));
    mapa[5][5].criaturas.push_back(criaturas.back().get());

    criaturas.push_back(make_unique<CriaturaAerea>(5, 5, 100));
    mapa[5][5].criaturas.push_back(criaturas.back().get());

    criaturas.push_back(make_unique<CriaturaHibrida>(5, 5, 100));
    mapa[5][5].criaturas.push_back(criaturas.back().get());

    int ciclos = 10;
    for (int ciclo = 1; ciclo <= ciclos; ++ciclo) {
        cout << "\n🌱 Ciclo " << ciclo << "\n";
        interacciones(mapa, criaturas);
        mostrarMapa(mapa);
    }

    return 0;
}
