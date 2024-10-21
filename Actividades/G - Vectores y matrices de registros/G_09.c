#include <stdio.h>
#include <stdbool.h>
#define MAX_FILAS 50
#define MAX_COLUMNAS 4

typedef struct casilla {
    int cantidad_avanzar;
    int cantidad_atrasar;
    bool es_obstaculo;
} casilla_t;

int jugar_sapito(casilla_t laguna[MAX_FILAS][MAX_COLUMNAS], int tope_filas, int tope_columnas, int fila_elegida){
    
}