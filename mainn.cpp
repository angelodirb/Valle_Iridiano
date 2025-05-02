#include <iostream>
#include <vector>
#include <memory>
#include <string>
#include <cstdlib>
#include <ctime>
#include "tile.h"
#include "CriaturaTerrestre.h"
#include "Criaturaaerea.h"
#include "CriaturaHibrida.h"

int main() {
    const int MAPA_TAM = 15;
    const double PROB_REPRODUCCION = 0.3;
    const double PROB_ATAQUE = 0.3;

    std::srand(std::time(0));
    std::vector<std::vector<Tile>> mapa(MAPA_TAM, std::vector<Tile>(MAPA_TAM));
    std::vector<std::unique_ptr<Criatura>> criaturas;

    auto mostrarMapa = [&](const std::vector<std::vector<Tile>>& mapa) {
        for (int i = 0; i < MAPA_TAM; ++i) {
            for (int j = 0; j < MAPA_TAM; ++j) {
                std::cout << mapa[i][j].mostrar() << " ";
            }
            std::cout << "\n";
        }
    };

    auto interacciones = [&](std::vector<std::unique_ptr<Criatura>>& criaturas) {
        for (int i = 0; i < MAPA_TAM; ++i) {
            for (int j = 0; j < MAPA_TAM; ++j) {
                auto& tile = mapa[i][j];
                auto& cs = tile.criaturas;
                if (cs.size() < 2) continue;

                std::vector<Criatura*> terrestres, aereas, hibridas;
                for (auto* c : cs) {
                    if (c->tipo() == "terrestre") terrestres.push_back(c);
                    else if (c->tipo() == "aerea") aereas.push_back(c);
                    else if (c->tipo() == "hibrida") hibridas.push_back(c);
                }

                auto reproducir = [&](const std::string& tipo) {
                    if (((double)rand() / RAND_MAX) < PROB_REPRODUCCION) {
                        std::unique_ptr<Criatura> nueva;
                        if (tipo == "terrestre") nueva = std::make_unique<CriaturaTerrestre>(j, i, 100);
                        if (tipo == "aerea") nueva = std::make_unique<CriaturaAerea>(j, i, 100);
                        if (tipo == "hibrida") nueva = std::make_unique<CriaturaHibrida>(j, i, 100);
                        tile.criaturas.push_back(nueva.get());
                        criaturas.push_back(std::move(nueva));
                        std::cout << "Reproducción de " << tipo << " en (" << j << "," << i << ")\n";
                    }
                };

                if (terrestres.size() >= 2) reproducir("terrestre");
                if (aereas.size() >= 2) reproducir("aerea");
                if (hibridas.size() >= 2) reproducir("hibrida");

                for (size_t k = 0; k + 1 < cs.size(); ++k) {
                    if (((double)rand() / RAND_MAX) < PROB_ATAQUE) {
                        int daño = cs[k]->vida / 3;
                        cs[k + 1]->vida -= daño;
                        std::cout << cs[k]->tipo() << " atacó en (" << j << "," << i << ") daño: " << daño << "\n";
                    }
                }
            }
        }

        for (auto& c : criaturas) c->edad++;

        for (auto it = criaturas.begin(); it != criaturas.end();) {
            if ((*it)->vida <= 0 || (*it)->edad >= (*it)->esperanza_vida) {
                auto& tile = mapa[(*it)->y][(*it)->x];
                tile.criaturas.erase(std::remove(tile.criaturas.begin(), tile.criaturas.end(), it->get()), tile.criaturas.end());
                std::cout << (*it)->tipo() << " murió en (" << (*it)->x << "," << (*it)->y << ")\n";
                it = criaturas.erase(it);
            } else ++it;
        }
    };

    while (true) {
        std::cout << "Comando (crear tipo x y vida / ciclos / salir): ";
        std::string cmd; std::cin >> cmd;

        if (cmd == "crear") {
            std::string tipo; int x, y, vida;
            std::cin >> tipo >> x >> y >> vida;
            if (x < 0 || x >= MAPA_TAM || y < 0 || y >= MAPA_TAM) {
                std::cout << "Posición inválida.\n";
                continue;
            }

            std::unique_ptr<Criatura> nueva;
            if (tipo == "terrestre") nueva = std::make_unique<CriaturaTerrestre>(x, y, vida);
            else if (tipo == "aerea") nueva = std::make_unique<CriaturaAerea>(x, y, vida);
            else if (tipo == "hibrida") nueva = std::make_unique<CriaturaHibrida>(x, y, vida);
            else {
                std::cout << "Tipo inválido.\n";
                continue;
            }

            mapa[y][x].criaturas.push_back(nueva.get());
            criaturas.push_back(std::move(nueva));
        }
        else if (cmd == "ciclos") {
            for (auto& c : criaturas) c->mover(mapa);
            interacciones(criaturas);
            mostrarMapa(mapa);
        }
        else if (cmd == "salir") break;
        else std::cout << "Comando no reconocido.\n";
    }

    return 0;
}
