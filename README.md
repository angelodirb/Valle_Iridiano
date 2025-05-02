@startuml

' Definición de enumeración
enum TipoTerreno {
FERTIL
NEUTRO
LETAL
}

class Criatura {
- x : int
- y : int
- vida : int
- edad : int
- esperanza_vida : int
+ tipo() : string
+ mover(mapa : vector<vector<Tile>>) : void
  }

class CriaturaTerrestre {
- camuflaje_activo : bool
+ estaOculta() : bool
+ tipo() : string
+ mover(mapa : vector<vector<Tile>>) : void
  }

class CriaturaAerea {
- altura_vuelo : int
+ puedeSobrevolar() : bool
+ tipo() : string
+ mover(mapa : vector<vector<Tile>>) : void
  }

class CriaturaHibrida {
+ tipo() : string
+ mover(mapa : vector<vector<Tile>>) : void
+ estaOculta() : bool
+ puedeSobrevolar() : bool
  }

class Tile {
- criaturas : vector<Criatura*>
- tipoTerreno : TipoTerreno
+ mostrar() : char
  }

CriaturaTerrestre --|> Criatura
CriaturaAerea --|> Criatura
CriaturaHibrida --|> CriaturaTerrestre
CriaturaHibrida --|> CriaturaAerea

Tile "1" *-- "*" Criatura : contiene

@enduml
