#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include <memory>
#include "tiiles.h"
#include "criaturaTerrestre.h"
#include "criaturaAerea.h"

using namespace std;

const int MAPA_TAM = 10;
const int DAÑO_FIJO = 10;
const double PROB_REPRODUCCION = 0.3;
const double PROB_ATAQUE = 0.1;

void mostrarMapa(const vector<vector<Tile>>& mapa) {
    for (int i = 0; i < MAPA_TAM; ++i) {
        for (int j = 0; j < MAPA_TAM; ++j) {
            cout << mapa[i][j].mostrar() << " ";
        }
        cout << endl;
    }
}

void interacciones(vector<vector<Tile>>& mapa, vector<unique_ptr<Criatura>>& criaturas) {
    for (int i = 0; i < MAPA_TAM; ++i) {
        for (int j = 0; j < MAPA_TAM; ++j) {
            auto& cs = mapa[i][j].criaturas;
            if (cs.size() < 2) continue;

            vector<Criatura*> terrestres, aereas;
            for (auto* c : cs) {
                if (c->tipo() == "terrestre") terrestres.push_back(c);
                else if (c->tipo() == "aerea") aereas.push_back(c);
            }

            auto reproducirYAtacar = [&](vector<Criatura*>& grupo, const string& tipo) {
                if (grupo.size() >= 2 && ((double)rand() / RAND_MAX) < PROB_REPRODUCCION) {
                    if (tipo == "terrestre")
                        criaturas.push_back(make_unique<CriaturaTerrestre>(j, i, 100));
                    else
                        criaturas.push_back(make_unique<CriaturaAerea>(j, i, 100));
                    mapa[i][j].criaturas.push_back(criaturas.back().get());
                    cout << "Se ha reproducido una criatura " << tipo << " en (" << j << "," << i << ")\n";
                }

                for (size_t k = 0; k + 1 < grupo.size(); ++k) {
                    if (((double)rand() / RAND_MAX) < PROB_ATAQUE) {
                        grupo[k + 1]->vida -= DAÑO_FIJO;
                        cout << tipo << " atacó a otra en (" << j << "," << i << ") y le hizo " << DAÑO_FIJO << " de daño.\n";
                    }
                }
            };

            reproducirYAtacar(terrestres, "terrestre");
            reproducirYAtacar(aereas, "aerea");
        }
    }

    for (auto it = criaturas.begin(); it != criaturas.end(); ) {
        if ((*it)->vida <= 0) {
            auto& tile = mapa[(*it)->y][(*it)->x];
            tile.criaturas.erase(
                remove(tile.criaturas.begin(), tile.criaturas.end(), it->get()),
                tile.criaturas.end()
            );
            cout << "Una criatura " << (*it)->tipo() << " ha muerto en (" << (*it)->x << "," << (*it)->y << ")\n";
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

    while (true) {
        cout << "\n--- Mapa ---\n";
        mostrarMapa(mapa);

        cout << "\nComandos:\n";
        cout << "crear tipo x y vida\n";
        cout << "ciclos\n";
        cout << "salir\n";

        string comando;
        cin >> comando;

        if (comando == "crear") {
            string tipo;
            int x, y, vida;
            cin >> tipo >> x >> y >> vida;

            if (x < 0 || x >= MAPA_TAM || y < 0 || y >= MAPA_TAM) {
                cout << "Posición inválida.\n";
                continue;
            }

            if (tipo == "terrestre") {
                criaturas.push_back(make_unique<CriaturaTerrestre>(x, y, vida));
                mapa[y][x].criaturas.push_back(criaturas.back().get());
            } else if (tipo == "aerea") {
                criaturas.push_back(make_unique<CriaturaAerea>(x, y, vida));
                mapa[y][x].criaturas.push_back(criaturas.back().get());
            } else {
                cout << "Tipo inválido.\n";
            }

        } else if (comando == "ciclos") {
            for (auto& c : criaturas) {
                c->mover(mapa);
            }
            interacciones(mapa, criaturas);

        } else if (comando == "salir") {
            break;
        } else {
            cout << "Comando no reconocido.\n";
        }
    }

    return 0;
}
