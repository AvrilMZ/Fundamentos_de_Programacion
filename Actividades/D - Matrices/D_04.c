#include <stdio.h>
#include <stdbool.h>
#define MAX_FILAS 5
#define MAX_COLUMNAS 5

int const ATACAR = 0;

bool conviene_atacar(int serpientes[MAX_FILAS][MAX_COLUMNAS], int tope_fila, int tope_columna) {
    int suma_comportamientos = 0;
    for (int i = 0; i < tope_fila; i++) {
        for (int j = 0; j < tope_columna; j++) {
            suma_comportamientos += serpientes[i][j];
        }
    }
    return suma_comportamientos < ATACAR;
}