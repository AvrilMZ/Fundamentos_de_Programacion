#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "restaurant.h"

#define ARRIBA 'W'
#define ABAJO 'S'
#define DERECHA 'D'
#define IZQUIERDA 'A'
#define MOPA 'O'
#define LINGUINI 'L'
const char MESA = 'T';
#define COCINA 'C'
#define CHARCO 'H'
const int CANTIDAD_CHARCOS = 5;
#define MONEDA 'M'
const int CANTIDAD_MONEDAS = 8;
#define PATINES 'P'
const int CANTIDAD_PATINES = 5;
#define CUCARACHA ' '

void mostrar_juego(juego_t juego){
    system("clear");
    
    for (int i = 0; i < MAX_FILAS; i++){
        for (int j = 0; j < MAX_COLUMNAS; j++){
            char contenido_posicion = ' ';

            if (juego.mozo.posicion.fil == i && juego.mozo.posicion.col == j){
                contenido_posicion = LINGUINI;
            } else if (juego.cocina.posicion.fil == i && juego.cocina.posicion.col == j){
                contenido_posicion = COCINA;
            } else {
                for (int k = 0; k < juego.cantidad_obstaculos; k++){
                    if (juego.obstaculos[k].posicion.fil == i && juego.obstaculos[k].posicion.col == j){
                        switch (juego.obstaculos[k].tipo){
                            case CHARCO:
                                contenido_posicion = CHARCO;
                            break;
                            case CUCARACHA:
                                contenido_posicion = CUCARACHA;
                            break;
                        }
                    }
                }
            }

            for (int k = 0; k < juego.cantidad_herramientas; k++){
                if (juego.herramientas[k].posicion.fil == i && juego.herramientas[k].posicion.col == j){
                    switch (juego.herramientas[k].tipo){
                        case MONEDA:
                            contenido_posicion = MONEDA;
                        break;
                        case PATINES:
                            contenido_posicion = PATINES;
                        break;
                        case MOPA:
                            contenido_posicion = MOPA;
                        break;

                    }
                }  
                
            }

            printf("| %c  ", contenido_posicion);
        }
        
        printf("|\n");
    }
}

int main(){
    juego_t juego;
    mostrar_juego(juego);
    return 0;
}