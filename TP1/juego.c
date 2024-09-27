#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "restaurant.h"

int main(){
    srand((unsigned)time(NULL));
    juego_t *juego = {0};

    while (true){
        char accion = ' ';
        inicializar_juego(juego);
        mostrar_juego(*juego);
        printf("Ingrese un movimiento (W/S/A/D) ó interactue con la mopa (O):\n");
        scanf(" %c", &accion);
        realizar_jugada(juego, accion);
        
        int estado = estado_juego(*juego);
        if (estado == 1){
            printf("¡Ganaste!");
            return false;
        } else if (estado == -1){
            printf("Perdiste");
            return false;
        }
    } 

    return 0;
}