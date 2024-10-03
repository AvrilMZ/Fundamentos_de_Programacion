#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "restaurant.h"

int main(){
    srand((unsigned)time(NULL));
    juego_t juego;

    inicializar_juego(&juego);
    mostrar_juego(juego);

    return 0;
}