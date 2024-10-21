#include <stdio.h>
#define MAX_FILAS 5
#define MAX_COLUMNAS 5

const char MANCUERNAS = 'M';
const char PASTO = 'P';

int mancuernas_perdidas(char bosque[MAX_FILAS][MAX_COLUMNAS]){
    int cantidad_mancuernas = 0;
    for (int i = 0; i < MAX_FILAS; i++) {
        for (int j = 0; j < MAX_COLUMNAS; j++) {
            if (bosque[i][j] == MANCUERNAS) cantidad_mancuernas++;
        }
    }
    return cantidad_mancuernas;
}