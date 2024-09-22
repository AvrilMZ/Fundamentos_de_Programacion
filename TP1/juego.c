#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "restaurant.h"

int main(){
    srand((unsigned)time(NULL));
    juego_t *juego;
    inicializar_juego(juego);

    while (true){
        char accion = ' ';
        mostrar_juego(*juego);
        printf("Utilice W, S, A, D para moverse ó la O para interactuar con la mopa:\n");
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