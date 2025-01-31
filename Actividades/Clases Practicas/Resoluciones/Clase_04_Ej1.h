#ifndef CLASE_04_EJE1_H
#define CLASE_04_EJ1_H

#define MAX_FILAS 10
#define MAX_COLUMNAS 10

typedef struct posicion {
    int fila;
    int columna;
} posicion_t;

/* PRE: 'tope_filas' y 'tope_columnas' deben estar previamente inicializados.
   POST: Itera por 'terreno' hasta encontrar la primera aparición de 'POZO', luego esa posición pasa a ser 'TESORO'.*/
void guardar_tesoro_en_primer_pozo(char terreno[MAX_FILAS][MAX_COLUMNAS], int tope_filas, int tope_columnas);

/* PRE: 'tope_filas' y 'tope_columnas' deben estar previamente inicializados.
   POST: Devuelve la cantidad de 'TESORO_FALSO' que hay en 'terreno'.*/
int contador_tesoros_falsos(char terreno[MAX_FILAS][MAX_COLUMNAS], int tope_filas, int tope_columnas);

#endif