#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "restaurant.h"

int main(){
    srand((unsigned)time(NULL));
    juego_t juego;
    int estado = estado_juego(juego);

    inicializar_juego(&juego);

    while (estado == 0) {
        mostrar_juego(juego);
    }

    if (estado == 1){
        printf("¡Ganaste!");
    } else if (estado == -1){
        printf("Perdiste");
    }

    return 0;
}