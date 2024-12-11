#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "restaurant.h"

const char ARRIBA = 'W';
const char ABAJO = 'S';
const char DERECHA = 'D';
const char IZQUIERDA = 'A';
const char MOPA = 'O';
const char* GANAR = "¡Ganaste!";
const char* PERDER = "Perdiste";
const int ESTADO_GANAR = 1;
const int SEGUIR_JUGANDO = 0;
const int ESTADO_PERDER = -1;

// POST: Devuelve 'true' si es un carácter de acción válida, de lo contrario devuelve 'false'.
bool es_accion_valida(char accion) {
    return (accion == ARRIBA || accion == ABAJO || accion == DERECHA || accion == IZQUIERDA || accion == MOPA);
}

// POST: Solicita la interacción al usuario preguntando nuevamente si esta no es válida.
void accion_usuario(char* accion) {
    printf("Ingrese un movimiento (%c/%c/%c/%c), interactúa con la mopa (%c):\n", ARRIBA, ABAJO, DERECHA, IZQUIERDA, MOPA);
    scanf(" %c", accion);

    while (!es_accion_valida(*accion)) {
        printf("Movimiento invalido. Ingrese un movimiento (%c/%c/%c/%c) ó interactue con la mopa (%c):\n", ARRIBA, ABAJO, DERECHA, IZQUIERDA, MOPA);
        scanf(" %c", accion);
    }
}

/* PRE: El valor pasado en 'estado' debe ser 1 ó -1.
   POST: Si el estado del juego es 1 devuelve que ganó, si es -1 devuelve que perdió.*/
void cierre_juego(int estado) {
    if (estado == ESTADO_GANAR) {
        printf("%s", GANAR);
    } else if (estado == ESTADO_PERDER) {
        printf("%s", PERDER);
    }
}

int main() {
    srand((unsigned)time(NULL));
    juego_t juego;

    inicializar_juego(&juego);

    int estado = 0;
    while (estado == SEGUIR_JUGANDO) {
        mostrar_juego(juego);

        char accion = ' ';
        accion_usuario(&accion);
        realizar_jugada(&juego, accion);
        
        estado = estado_juego(juego);
    }

    cierre_juego(estado);
    
    return 0;
}