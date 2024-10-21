#include <stdbool.h>
#define MAX_FILAS 30
#define MAX_COLUMNAS 25

const char SHERE = 'S';
const char MOWGLI = 'M';
const char VACIO = 'V';

bool escapar(char templo[MAX_FILAS][MAX_COLUMNAS], int tope_filas, int tope_columnas, int nueva_fila, int nueva_columna) {
    if (nueva_fila < 0 || nueva_fila >= tope_filas || nueva_columna < 0 || nueva_columna >= tope_columnas) return false;

    if (templo[nueva_fila][nueva_columna] == SHERE || (nueva_fila == -1 && nueva_columna == -1)) return false;

    for (int i = 0; i < tope_filas; i++) {
        for (int j = 0; j < tope_columnas; j++) {
            if (templo[i][j] == SHERE) {
                int diferencia_fila = nueva_fila - i;
                int diferencia_columna = nueva_columna - j;
                if (diferencia_fila * diferencia_fila + diferencia_columna * diferencia_columna < 4) return false;
            }
        }
    }

    for (int i = 0; i < tope_filas; i++) {
        for (int j = 0; j < tope_columnas; j++) {
            if (templo[i][j] == MOWGLI) templo[i][j] = VACIO;
        }
    }
    
    templo[nueva_fila][nueva_columna] = MOWGLI;

    return true;
}