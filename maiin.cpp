#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <cstdlib>
#include "tiles.h"
#include "criatures.h"

using namespace std;

const int MAPA_TAM = 10;

void mostrarMapa(const vector<vector<Tile>>& mapa) {
    for (int i = 0; i < MAPA_TAM; ++i) {
        for (int j = 0; j < MAPA_TAM; ++j) {
            cout << mapa[i][j].mostrar() << " ";
        }
        cout << endl;
    }
}

int main() {
    srand(time(0));
    vector<vector<Tile>> mapa(MAPA_TAM, vector<Tile>(MAPA_TAM));
    vector<Criatura*> criaturas;

    while (true) {
        cout << "\n--- Mapa ---\n";
        mostrarMapa(mapa);

        cout << "\nComandos:\n";
        cout << "crear tipo x y   (tipo: aerea o terrestre)\n";
        cout << "ciclos\n";
        cout << "salir\n";

        string comando;
        cin >> comando;

        if (comando == "crear") {
            string tipo;
            int x, y;
            cin >> tipo >> x >> y;
            if (x < 0 || x >= MAPA_TAM || y < 0 || y >= MAPA_TAM) {
                cout << "Posición inválida.\n";
                continue;
            }

            if (tipo == "terrestre") {
                criaturas.push_back(new CriaturaTerrestre(x, y));
                mapa[y][x].criaturasEnCasilla++;
            } else if (tipo == "aerea") {
                criaturas.push_back(new CriaturaAerea(x, y));
                mapa[y][x].criaturasEnCasilla++;
            } else {
                cout << "Tipo inválido.\n";
            }

        } else if (comando == "ciclos") {
            for (auto c : criaturas) {
                c->mover(mapa);
            }

        } else if (comando == "salir") {
            break;
        } else {
            cout << "Comando no reconocido.\n";
        }
    }

    for (auto c : criaturas) {
        delete c;
    }

    return 0;
}
