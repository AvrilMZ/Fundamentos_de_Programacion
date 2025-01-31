#include <stdio.h>
#include <stdbool.h>

#define MAX_FILAS 10
#define MAX_COLUMNAS 10
const char CESPED = 'C';
const char TESORO_FALSO = 'F';
const char POZO = 'P';
const char TESORO = 'T';
const int MIN_CANTIDAD_TESOROS_FALSOS = 5;

/* PRE: 'fila' y 'columna' deben estar en el rango posible de 'terreno'.
   POST: Devuelve true si en la posición hay 'POZO', de lo contrario, devuelve false.*/
bool es_pozo(char terreno[MAX_FILAS][MAX_COLUMNAS], int fila, int columna) {
    return terreno[fila][columna] == POZO;
}

/* PRE: - 'tope_filas' y 'tope_columnas' deben estar previamente inicializados;
        - 'ref_fila' y 'ref_columna' deben estar en el rango posible de 'terreno'.
   POST: Actualiza los valores 'ref_fila' y 'ref_columna' con la posición del primer 'POZO' encontrado.*/
void encontrar_pozo(char terreno[MAX_FILAS][MAX_COLUMNAS], int tope_filas, int tope_columnas, int* ref_fila, int* ref_columna) {
    bool pozo_encontrado = false;
    for (int i = 0; i < tope_filas && !pozo_encontrado; i++) {
        for (int j = 0; j < tope_columnas && !pozo_encontrado; j++) {
            if (terreno[i][j] == POZO) {
                *ref_fila = i;
                *ref_columna = j;
                pozo_encontrado = true;
            }
        }
    }
}

/* PRE: 'ref_fila' y 'ref_columna' deben estar en el rango posible de 'terreno'.
   POST: En caso de ser 'POZO' la posición dada, esta pasa a ser 'TESORO'.*/
void guardar_tesoro(char terreno[MAX_FILAS][MAX_COLUMNAS], int ref_fila, int ref_columna) {
    if (es_pozo(terreno, ref_fila, ref_columna)) terreno[ref_fila][ref_columna] = TESORO;
}

/* PRE: 'tope_filas' y 'tope_columnas' deben estar previamente inicializados.
   POST: Devuelve la cantidad de 'TESORO_FALSO' que hay en 'terreno'.*/
int contador_tesoros_falsos(char terreno[MAX_FILAS][MAX_COLUMNAS], int tope_filas, int tope_columnas) {
    int contador = 0;
    for (int i = 0; i < tope_filas; i++) {
        for (int j = 0; j < tope_columnas; j++) {
            if (terreno[i][j] == TESORO_FALSO) contador++;
        }
    }
    return contador;
}

int main() {
    char terreno[MAX_FILAS][MAX_COLUMNAS];
    int tope_filas = 10;
    int tope_columnas = 10;
    int fila_pozo = 0;
    int columna_pozo = 0;

    encontrar_pozo(terreno, tope_filas, tope_columnas, &fila_pozo, &columna_pozo);
    if (es_pozo(terreno, fila_pozo, columna_pozo) && contador_tesoros_falsos(terreno, tope_filas, tope_columnas) > MIN_CANTIDAD_TESOROS_FALSOS) {
        guardar_tesoro(terreno, fila_pozo, columna_pozo);
    }

    return 0;
}