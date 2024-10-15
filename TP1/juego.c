#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "restaurant.h"

const char ARRIBA = 'W';
const char ABAJO = 'S';
const char DERECHA = 'D';
const char IZQUIERDA = 'A';
const char MOPA = 'O';

int main(){
    srand((unsigned)time(NULL));
    juego_t juego;

    inicializar_juego(&juego);

    int estado = 0;
    while (estado == 0){
        mostrar_juego(juego);

        char accion = ' ';
        printf("Ingrese un movimiento (W/S/A/D) o interactúa con la mopa (O):\n");
        scanf(" %c", &accion);
        while (accion != ARRIBA || accion != ABAJO || accion != DERECHA || accion != IZQUIERDA || accion != MOPA) {
            printf("Movimiento invalido. Ingrese un movimiento (W/S/A/D) ó interactue con la mopa (O):\n");
            scanf(" %c", &accion);
        }

        estado = estado_juego(juego);
    }

    if (estado == 1){
        printf("¡Ganaste!");
    } else if (estado == -1){
        printf("Perdiste");
    }

    return 0;
}