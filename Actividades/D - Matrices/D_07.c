/*Mérida, hija del rey Fergus, decidió que como primogénita del clan Dunbroch, ella puede participar en los juegos de las Tierras Altas con el fin de disputar su propia mano en matrimonio. Quién puede casarse con Mérida se determina a partir de una competencia de tiro con arco. Si el blanco al que se debe tirar es representado por una matriz, se pide:

Implementar una función que dada una matriz que representa un blanco, devuelva el puntaje de ese tiro. El puntaje está dado dependiendo de en qué posición de éste fue el tiro:
Amarillo: 10 puntos.
Rojo: 5 puntos.
Negro: 2 puntos.
Por afuera del blanco: 0 puntos.

Tener en cuenta:
La matriz es de caracteres, donde cada posición puede representar un color:
Amarillo (A).
Rojo (R).
Negro (N).
La matriz no es necesariamente cuadrada y tiene sus respectivos topes. Por lo que se toma al tiro por fuera del blanco cuando éste está por fuera de los límites definidos por los topes de la matriz.

Ejemplo:
Con la matriz de 5x5:
N N R N N
N R A R N
N R N R N
N R A R N
N N R N N
Y el tiro:
fila = 2
columna = 1
El resultado esperado de la función es 5 ya que da en uno rojo.*/

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