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

    char accion = ' ';
    while (estado_juego(juego) == 0){
        mostrar_juego(juego);

        if (juego.mozo.tiene_mopa == true){
            printf("Tiene la mopa. ");
        } else printf("No tiene la mopa. ");

        printf("Ingrese un movimiento (W/S/A/D) ó interactue con la mopa (O):\n");
        scanf(" %c", &accion);
        realizar_jugada(&juego, accion);
        
        int estado = estado_juego(juego);
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