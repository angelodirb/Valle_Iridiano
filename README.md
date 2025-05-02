# 🧬 Ecosistema de Criaturas - Simulador en C++

## 📌 Descripción del Proyecto

Este proyecto es un **simulador de ecosistemas en consola desarrollado en C++**, donde diferentes tipos de criaturas (`terrestres`, `aéreas`, `híbridas`) interactúan dentro de un mapa dividido por zonas ecológicas: fértil, neutro y letal.

### 🎯 Propósito del sistema

El objetivo del simulador es modelar el comportamiento autónomo de criaturas que pueden moverse, atacar, reproducirse y morir según reglas predefinidas. Además, se incorpora **persistencia de datos** mediante **serialización en formato JSON**, lo que permite guardar y continuar la simulación entre sesiones.

### 🔧 ¿Qué problema resuelve?

- Automatiza la simulación de un entorno dinámico con múltiples agentes (criaturas).
- Guarda el estado del ecosistema para evitar perder el progreso.
- Permite observar la evolución de la población bajo condiciones controladas (reproducción, muerte, daño, tipo de terreno).
- Se puede usar para estudios básicos de simulación, patrones emergentes o incluso como introducción a IA basada en reglas.

### 👥 Usuarios objetivo

- Estudiantes de ingeniería de sistemas, software o ciencias de la computación.
- Docentes que enseñan estructuras de datos, programación orientada a objetos, simulación de agentes o serialización en C++.
- Desarrolladores interesados en simulaciones basadas en reglas simples y estructuras dinámicas.
- Cualquier persona que desee aprender a **estructurar proyectos grandes en C++** con separación modular de clases y persistencia de datos.

---

## 📁 Estructura modular del código

```plaintext
├── main.cpp
├── Tile.h
├── Tile.cpp
├── Criatura.h
├── CriaturaTerrestre.h
├── CriaturaTerrestre.cpp
├── CriaturaAerea.h
├── CriaturaAerea.cpp
├── CriaturaHibrida.h
├── CriaturaHibrida.cpp
├── json.hpp             <-- Librería nlohmann/json
├── partida.json         <-- Estado serializado del ecosistema
└── README.md
l
