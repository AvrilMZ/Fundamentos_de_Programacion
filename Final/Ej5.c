#include <stdbool.h>
#include <string.h>

#define MAX_NOMBRE 20
#define MAX_TIPO 10
#define MAX_FILAS 10
#define MAX_COLUMNAS 10
#define MAX_CULTIVOS 20
const char* ESPECIA = "especia";
const char* VERDURA = "verdura";
const char* FRUTA = "fruta";
const char* FLOR = "flor";

typedef struct cultivo {
    char nombre[MAX_NOMBRE];
    char tipo[MAX_TIPO];
    bool maduro;
    int peso;
} cultivo_t;

// PRE: 'tope_filas', 'tope_columnas' y 'tope_cultivos' deben estar inicializados correctamente.
// POST: Actualiza el vector 'cultivos' con los elementos de 'huerta' que cumplan 'maduro' y que tipo sea 'ESPECIA' o 'VERDURA'.
void guardar_cultivos(cultivo_t huerta[MAX_FILAS][MAX_COLUMNAS], int tope_filas, int tope_columnas, cultivo_t canasta[MAX_CULTIVOS], int* tope_cultivos) {
    for (int i = 0; i < tope_filas; i++) {
        for (int j = 0; j < tope_columnas; j++) {
            if ((strcmp(huerta[i][j].tipo, ESPECIA) == 0 || strcmp(huerta[i][j].tipo, VERDURA) == 0) && huerta[i][j].maduro) {
                canasta[*tope_cultivos] = huerta[i][j];
                (*tope_cultivos)++;
            }
        }
    }
}

int main() {
    return 0;
}

/*
----- PARTE TEÓRICA -----
1- ¿En qué consiste la inserción ordenada? Explicar detalladamente.

1- La inserción ordenada es un proceso donde se inserta un nuevo elemento en una lista manteniendo su orden. 
   Se compara el nuevo elemento con los existentes y se coloca en la posición correcta. Este proceso se repite para cada nuevo elemento.
*/