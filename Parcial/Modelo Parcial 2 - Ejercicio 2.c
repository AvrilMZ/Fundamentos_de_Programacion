#include <stdbool.h>

#define MAX_FILAS 10
#define MAX_COLUMNAS 10

//PRE: 'mapa' no debe estar vacio y 'tope_fil', 'tope_col', 'vida' deben ser estrictamente mayores a cero.
//POST: Devuelve true si hay alguna columna cuya sumatoria de elementos sea menor al valor ingresado como 'vida', en caso contrario devuelve false.
bool puedo_pasar(int mapa[MAX_FILAS][MAX_COLUMNAS], int tope_fil, int tope_col, int vida) {
    for (int j = 0; j < tope_col; j++) {
        int danio_total_columna = 0;
        for (int i = 0; i < tope_fil; i++) {
            danio_total_columna += mapa[i][j];
        }
        if (vida > danio_total_columna) return true;
    }
    return false;
}