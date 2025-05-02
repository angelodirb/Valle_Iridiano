#include "criatures.h"
#include <cstdlib>
#include <algorithm>

const int MAPA_TAM = 10;

Criatura::Criatura(int x, int y) : x(x), y(y) {}
Criatura::~Criatura() {}

CriaturaTerrestre::CriaturaTerrestre(int x, int y) : Criatura(x, y) {}

void CriaturaTerrestre::mover(std::vector<std::vector<Tile>>& mapa) {
    int dx[] = {0, 0, -1, 1};
    int dy[] = {-1, 1, 0, 0};

    std::vector<int> direcciones = {0, 1, 2, 3};
    std::random_shuffle(direcciones.begin(), direcciones.end());

    mapa[y][x].criaturasEnCasilla--;

    for (int i : direcciones) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 0 && nx < MAPA_TAM && ny >= 0 && ny < MAPA_TAM) {
            x = nx;
            y = ny;
            break;
        }
    }

    mapa[y][x].criaturasEnCasilla++;
}

CriaturaAerea::CriaturaAerea(int x, int y) : Criatura(x, y) {}

void CriaturaAerea::mover(std::vector<std::vector<Tile>>& mapa) {
    mapa[y][x].criaturasEnCasilla--;

    int dx = (rand() % 5) - 2;
    int dy = (rand() % 5) - 2;

    int nx = x + dx;
    int ny = y + dy;

    if (nx >= 0 && nx < MAPA_TAM && ny >= 0 && ny < MAPA_TAM) {
        x = nx;
        y = ny;
    }

    mapa[y][x].criaturasEnCasilla++;
}
