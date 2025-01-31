#include <stdio.h>
#include "Clase_04_Ejercicio_1.h"

const int MIN_CANTIDAD_TESOROS_FALSOS = 5;

int main() {
    char terreno[MAX_FILAS][MAX_COLUMNAS];
    int tope_filas = 10;
    int tope_columnas = 10;
    
    if (contador_tesoros_falsos(terreno, tope_filas, tope_columnas) > MIN_CANTIDAD_TESOROS_FALSOS) guardar_tesoro_en_primer_pozo(terreno, tope_filas, tope_columnas);

    return 0;
}
