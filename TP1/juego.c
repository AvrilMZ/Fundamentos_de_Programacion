#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "restaurant.h"

int main(){
    srand((unsigned)time(NULL));
    juego_t juego;
    juego.cantidad_mesas = 0;
    juego.cantidad_herramientas = 0;
    juego.cantidad_obstaculos = 0;
    juego.movimientos = 0;
    juego.dinero = 0;

    inicializar_juego(&juego);
    mostrar_juego(juego);

    return 0;
}