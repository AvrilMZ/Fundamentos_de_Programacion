#include <stdbool.h>
#define MAX_FILAS 5
#define MAX_COLUMNAS 5

const char CIUDADANO = 'C';
const char PELIGRO = 'P';

bool quedan_ciudadanos_en_peligro(char tebas[MAX_FILAS][MAX_COLUMNAS]) {
    bool ciudadano_sin_ayuda = false;
    for (int i = 0; i < MAX_FILAS; i++) {
        for (int j = 0; j < MAX_COLUMNAS; j++) {
            if (tebas[i][j] == PELIGRO) return ciudadano_sin_ayuda = true;
        }
    }
    return ciudadano_sin_ayuda;
}