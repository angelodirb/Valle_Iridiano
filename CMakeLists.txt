cmake_minimum_required(VERSION 3.30)
project(Proyect_final)

set(CMAKE_CXX_STANDARD 20)

add_executable(Proyect_final main.cpp
        criatura.cpp
        criatura.h
        Bioma.cpp
        Bioma.h
        Tile.cpp
        Tile.h
        Mapa.cpp
        Mapa.h
        CriaturaTerrestre.cpp
        CriaturaTerrestre.h
        CriaturaAerea.cpp
        CriaturaAerea.h
        Estado.cpp
        Estado.h)
