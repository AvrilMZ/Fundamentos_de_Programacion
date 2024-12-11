/*Dipper, Mabel y Wendy están realizando la ancestral técnica de lanzar una piedra al agua de forma tal que salte un par de veces, la idea es que llegue lo más lejos posible. Alguna gente conoce esta técnica con el nombre de “sapito”. Están usándola para distraerse un rato en el descanso de Wendy.

Realizar una función que dada una matriz que representa el cuerpo de agua en el que están jugando (una laguna en este caso), sus respectivos topes y número de fila en el que decidieron tirar devuelva la cantidad de lugares que pudieron recorrer con su piedra. Revisar bien las reglas.

Reglas:
Hay una matriz que representa la laguna, cada posición de esta representa un casillero el cual tiene la siguiente información:
    Casillas que avanza (entero).
    Si es una casilla con obstaculo (booleano).
    Cantidad de casilleros que atrasa (entero).
En cada casilla tenes cantidad a avanzar y, si es un obstaculo, cantidad a atrasar. Por lo que la cantidad total de casillas a avanzar final va a estar dado por cantidad_avanzar - cantidad_atrasar si tiene obstaculo, sino simplemente es cantidad_avanzar. Tener en cuenta que si esta cuenta da negativa o nula no se mueve del casillero y se termina el juego.
Si la cantidad de casillas a avanzar generan que la piedra salga de los límites de la laguna (dados por los topes), entonces no se avanza y se termina el juego.
El jugador puede elegir la fila en la que empieza su piedra. Esto quiere decir que la piedra empieza en la columna 0 de la fila elegida, y solo se va a recorrer esa fila (ya que siempre se avanza para adelante en la misma fila, nunca se cambia de fila). Osea, se empieza en la posición cero y en esta se debe hacer el cálculo de cuánto avanzar.
Una vez que se termina el juego se debe devolver el índice de la columna en la que terminó la piedra.

Notas:
La matriz puede NO ser cuadrada.
Recordar que se debe devolver el índice de la columna en la que quedó la piedra.
La fila elegida que se pasa por parámetro es una fila válida de la matriz, no hace falta validación.
Recordar validar que no se pase del máximo de columna al avanzar.*/

#include <stdio.h>
#include <stdbool.h>
#define MAX_FILAS 50
#define MAX_COLUMNAS 4

typedef struct casilla {
    int cantidad_avanzar;
    int cantidad_atrasar;
    bool es_obstaculo;
} casilla_t;

int jugar_sapito(casilla_t laguna[MAX_FILAS][MAX_COLUMNAS], int tope_filas, int tope_columnas, int fila_elegida){
    int columna_actual = 0;

    while (columna_actual < tope_columnas) {
        int cantidad_avanzar = laguna[fila_elegida][columna_actual].cantidad_avanzar;
        int cantidad_atrasar = laguna[fila_elegida][columna_actual].cantidad_atrasar;
        bool es_obstaculo = laguna[fila_elegida][columna_actual].es_obstaculo;

        int avance_total;
        if (es_obstaculo) avance_total = cantidad_avanzar - cantidad_atrasar;
        else avance_total = cantidad_avanzar;

        if (avance_total <= 0 || columna_actual + avance_total >= tope_columnas) return columna_actual;

        columna_actual += avance_total;
    }

    return columna_actual;
}