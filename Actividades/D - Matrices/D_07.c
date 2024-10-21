#define MAX_FILAS 10
#define MAX_COLUMNAS 23

const char AMARILLO = 'A';
const char ROJO = 'R';
const char NEGRO = 'N';

const int VALOR_AMARILLO = 10;
const int VALOR_ROJO = 5;
const int VALOR_NEGRO = 2;
const int VALOR_FUERA = 0;

int calcular_puntaje_tiro(char blanco[MAX_FILAS][MAX_COLUMNAS], int tope_filas, int tope_columnas, int fila_tiro, int columna_tiro) {
    int puntaje = 0;

    if (fila_tiro > tope_filas || columna_tiro > tope_columnas) return VALOR_FUERA;

    if (blanco[fila_tiro][columna_tiro] == AMARILLO) puntaje = VALOR_AMARILLO;
    else if (blanco[fila_tiro][columna_tiro] == ROJO) puntaje = VALOR_ROJO;
    else if (blanco[fila_tiro][columna_tiro] == NEGRO) puntaje = VALOR_NEGRO;

    return puntaje;
}