#include <stdio.h>
#include <stdbool.h>
#define MAX_FILAS 100
#define MAX_COLUMNAS 100
#define MAX_NOMBRE 60

typedef struct escondite {
    bool ocupado;
    char nombre_juguete[MAX_NOMBRE];
    char nombre_escondite[MAX_NOMBRE];
} escondite_t;

typedef struct posicion {
    int fila;
    int columna;
} posicion_t;

bool hay_juguete(escondite_t cuarto[MAX_FILAS][MAX_COLUMNAS], int tope_filas, int tope_columnas, posicion_t posicion){
    
}