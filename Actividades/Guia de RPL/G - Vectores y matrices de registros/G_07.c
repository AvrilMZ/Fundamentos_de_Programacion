/*Andy se fue de vacaciones y para pasar el rato, sus juguetes juegan a las escondidas en su cuarto. Rex resulta ser muy malo para encontrar gente y ya se está empezando a frustrar. Sabe que hacer trampa está mal, pero espera que nadie lo descubra y te pide tu ayuda para encontrar a los demás juguetes.

Implementar una función que a partir de una matriz que representa el cuarto de Andy, sus respectivos topes y una posición que eligió Rex, devuelva true si hay un juguete en esa posición o false en caso contrario.

Notas:
La matriz que representa el cuarto de Andy tiene en cada posición suya un registro con los siguientes datos:
    Ocupado (booleano).
    Nombre de juguete (string).
    Nombre de escondite (string).
La matriz puede NO ser cuadrada.*/

#include <stdio.h>
#include <stdbool.h>
#define MAX_FILAS 100
#define MAX_COLUMNAS 100
#define MAX_NOMBRE 60

typedef struct escondite {
    bool ocupado;
    char nombre_juguete[MAX_NOMBRE];
    char nombre_escondite[MAX_NOMBRE];
} escondite_t;

typedef struct posicion {
    int fila;
    int columna;
} posicion_t;

bool hay_juguete(escondite_t cuarto[MAX_FILAS][MAX_COLUMNAS], int tope_filas, int tope_columnas, posicion_t posicion){
    if (posicion.fila < 0 || posicion.fila >= tope_filas || posicion.columna < 0 || posicion.columna >= tope_columnas) return false;
    return cuarto[posicion.fila][posicion.columna].ocupado;
}