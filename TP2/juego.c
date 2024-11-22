#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "restaurant.h"

#define ROJO_NEGRITA "\e[1;31m"
#define VERDE_NEGRITA "\e[1;32m"
#define BLANCO_NEGRITA "\e[1;37m"
#define NORMAL "\e[0m"

const char ARRIBA = 'W';
const char ABAJO = 'S';
const char DERECHA = 'D';
const char IZQUIERDA = 'A';
const char MOPA = 'O';
const char TOMAR_PEDIDO = 'T';
const char USAR_PATINES = 'P';
const int ESTADO_GANAR = 1;
const int SEGUIR_JUGANDO = 0;
const int ESTADO_PERDER = -1;

// POST: Devuelve 'true' si es un carácter de acción válida, de lo contrario devuelve 'false'.
bool es_accion_valida(char accion) {
    return (accion == ARRIBA || accion == ABAJO || accion == DERECHA || accion == IZQUIERDA || accion == MOPA || accion == TOMAR_PEDIDO || accion == USAR_PATINES);
}

// POST: Solicita la interacción al usuario preguntando nuevamente si esta no es válida.
void accion_usuario(char* accion) {
    printf("Ingrese un movimiento (W/S/A/D), interactúa con la mopa (O), usa los patines (P), ó toma pedidos (T):\n");
    scanf(" %c", accion);

    while (!es_accion_valida(*accion)) {
        printf("Movimiento invalido. Ingrese un movimiento (W/S/A/D), interactúa con la mopa (O), usa los patines (P), ó toma pedidos (T):\n");
        scanf(" %c", accion);
    }
}

/* PRE: El valor pasado en 'estado' debe ser 1 ó -1.
   POST: Si el estado del juego es 1 devuelve que ganó, si es -1 devuelve que perdió.*/
void cierre_juego(int estado) {
    if (estado == ESTADO_GANAR) {
        printf("\n%s========================================%s\n", BLANCO_NEGRITA, NORMAL);
        printf("        %s¡Felicidades, ganaste!%s        \n", VERDE_NEGRITA, NORMAL);
        printf("%s========================================%s\n\n", BLANCO_NEGRITA, NORMAL);
    } else if (estado == ESTADO_PERDER) {
        printf("\n%s========================================%s\n", BLANCO_NEGRITA, NORMAL);
        printf("              %s¡Perdiste!%s                  \n", ROJO_NEGRITA, NORMAL);
        printf("          %s¡Inténtalo de nuevo!%s            \n", ROJO_NEGRITA, NORMAL);
        printf("%s========================================%s\n\n", BLANCO_NEGRITA, NORMAL);
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
    destruir_juego(&juego);

    return 0;
}