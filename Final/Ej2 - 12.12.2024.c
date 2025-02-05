#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_PIEL 10
#define MAX_DIENTES 30
#define MAX_FILAS 10
#define MAX_COLUMNAS 10
const char CARNIVORO = 'C';
const char HERVIVORO = 'H';
const char OMNIVORO = 'O';
const char* PELAJE = "pelaje";
const char* ESCAMAS = "escamas";
const char* PLUMAJE = "plumaje";
const int PELIGRO_DIENTES_FILOSOS = 3;

typedef struct animal {
    char alimentacion;
    char piel[MAX_PIEL];
    dientes_t dientes;
    bool venenoso;
} animal_t;

typedef struct dientes {
    int cantidad_dientes;
    bool dientes_filosos[MAX_DIENTES];
} dientes_t;

// PRE: 'posicion_fila' y 'posicion_columna' deben ser validas.
// POST: Devuelve true si hay un animal peligroso en esa posicion, de lo contrario, devuelve false.
bool hay_animal_peligroso(animal_t selva[MAX_FILAS][MAX_COLUMNAS], int posicion_fila, int posicion_columna) {
    int contador_dientes_filosos = 0;
    for (int i = 0; i < selva[posicion_fila][posicion_columna].dientes.cantidad_dientes; i++) {
        if (selva[posicion_fila][posicion_columna].dientes.dientes_filosos[i] == true) {
            contador_dientes_filosos++;
        }
    }

    if ((selva[posicion_fila][posicion_columna].alimentacion == CARNIVORO || 
        selva[posicion_fila][posicion_columna].alimentacion == OMNIVORO) &&
        contador_dientes_filosos >= PELIGRO_DIENTES_FILOSOS) return true;
    else if ((selva[posicion_fila][posicion_columna].alimentacion == CARNIVORO || 
    selva[posicion_fila][posicion_columna].alimentacion == OMNIVORO) && 
    strcmp(selva[posicion_fila][posicion_columna].piel, ESCAMAS) == 0 &&
    selva[posicion_fila][posicion_columna].venenoso) return true;
    else return false;
}

// PRE: -
// POST: Devuelve true si la cordenada esta dentro del rango de la matriz, de lo contrario devuelve false.
bool es_coordenada_valida(int fila, int columna) {
    return (fila >= 0 && fila < MAX_FILAS && columna >= 0 && columna < MAX_COLUMNAS);
}

/* PRE: - 'fila_jane' y 'columna_jane' deben ser validos;
        - 'tope_filas' y 'tope_columnas' deben estar inicializadas correctamente.*/
// POST: Devuelve la cantidad de animales peligrosos que hay alrededor de la posicion pasada, incluyendo diagonales.
int contador_animales_peligrosos(animal_t selva[MAX_FILAS][MAX_COLUMNAS], int fila_jane, int columna_jane) {
    int contador = 0;

    if (es_coordenada_valida(fila_jane + 1, columna_jane) && hay_animal_peligroso(selva, fila_jane + 1, columna_jane)) contador++; // Arriba
    if (es_coordenada_valida(fila_jane + 1, columna_jane - 1) && hay_animal_peligroso(selva, fila_jane + 1, columna_jane - 1)) contador++; // Arriba izquierda
    if (es_coordenada_valida(fila_jane + 1, columna_jane + 1) && hay_animal_peligroso(selva, fila_jane + 1, columna_jane + 1)) contador++; // Arriba derecha
    if (es_coordenada_valida(fila_jane - 1, columna_jane) && hay_animal_peligroso(selva, fila_jane - 1, columna_jane)) contador++; // Abajo
    if (es_coordenada_valida(fila_jane - 1, columna_jane + 1) && hay_animal_peligroso(selva, fila_jane - 1, columna_jane + 1)) contador++; // Abajo derecha
    if (es_coordenada_valida(fila_jane - 1, columna_jane - 1) && hay_animal_peligroso(selva, fila_jane - 1, columna_jane - 1)) contador++; // Abajo izquierda
    if (es_coordenada_valida(fila_jane, columna_jane - 1) && hay_animal_peligroso(selva, fila_jane, columna_jane - 1)) contador++; // Izquierda
    if (es_coordenada_valida(fila_jane, columna_jane + 1) && hay_animal_peligroso(selva, fila_jane, columna_jane + 1)) contador++; // Derecha

    return contador;
}

/*
----- PARTE TEÓRICA -----
1- ¿Cuál es la diferencia entre el tope y el máximo de un vector? ¿Qué representa cada uno?

1- El máximo de un vector define la cantidad máxima de elementos que este puede contener, mientras que el tope define la cantidad de elementos que este vector tiene (por lo que el tope nunca puede ser mayor al máximo).
*/