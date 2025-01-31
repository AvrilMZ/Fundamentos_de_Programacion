#include <stdbool.h>
#include "Clase_04_Ejercicio_1.h"

const char CESPED = 'C';
const char TESORO_FALSO = 'F';
const char POZO = 'P';
const char TESORO = 'T';

/* PRE: 'posicion' debe estar en el rango posible de 'terreno'.
   POST: Devuelve true si en la posición hay 'POZO', de lo contrario, devuelve false.*/
bool es_pozo(char terreno[MAX_FILAS][MAX_COLUMNAS], posicion_t posicion) {
    return terreno[posicion.fila][posicion.columna] == POZO;
}

/* PRE: 'tope_filas' y 'tope_columnas' deben estar previamente inicializados.
   POST: Devuelve la posición del primer 'POZO' encontrado en el 'terreno'. Si no hay pozos, devuelve una posición inválida (-1, -1).*/
posicion_t encontrar_pozo(char terreno[MAX_FILAS][MAX_COLUMNAS], int tope_filas, int tope_columnas) {
    posicion_t posicion;
    for (int i = 0; i < tope_filas; i++) {
        for (int j = 0; j < tope_columnas; j++) {
            if (terreno[i][j] == POZO) {
                posicion.fila = i;
                posicion.columna = j;
                return posicion;
            }
        }
    }
    posicion.fila = -1;
    posicion.columna = -1;
    return posicion;
}

/* PRE: 'posicion_ref' debe estar en el rango posible de 'terreno'.
   POST: En caso de ser 'POZO' la posición dada, esta pasa a ser 'TESORO'.*/
void guardar_tesoro(char terreno[MAX_FILAS][MAX_COLUMNAS], posicion_t posicion_ref) {
    if (es_pozo(terreno, posicion_ref)) {
        terreno[posicion_ref.fila][posicion_ref.columna] = TESORO;
    }
}

/* PRE: 'tope_filas' y 'tope_columnas' deben estar previamente inicializados.
   POST: Itera por 'terreno' hasta encontrar la primera aparición de 'POZO', luego esa posición pasa a ser 'TESORO'.*/
void guardar_tesoro_en_primer_pozo(char terreno[MAX_FILAS][MAX_COLUMNAS], int tope_filas, int tope_columnas) {
    posicion_t posicion = encontrar_pozo(terreno, tope_filas, tope_columnas);
    if (posicion.fila != -1) {
        guardar_tesoro(terreno, posicion);
    }
}

/* PRE: 'tope_filas' y 'tope_columnas' deben estar previamente inicializados.
   POST: Devuelve la cantidad de 'TESORO_FALSO' que hay en 'terreno'.*/
int contador_tesoros_falsos(char terreno[MAX_FILAS][MAX_COLUMNAS], int tope_filas, int tope_columnas) {
    int contador = 0;
    for (int i = 0; i < tope_filas; i++) {
        for (int j = 0; j < tope_columnas; j++) {
            if (terreno[i][j] == TESORO_FALSO) {
                contador++;
            }
        }
    }
    return contador;
}