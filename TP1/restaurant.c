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

// PRE: -
// POST: Inicializará el juego, cargando toda la información inicial de Linguini, las mesas, las herramientas y los obstáculos.
void inicializar_juego(juego_t *juego){
    do {
        juego->mozo.posicion.fil = rand() % MAX_FILAS;
        juego->mozo.posicion.col = rand() % MAX_COLUMNAS;

        juego->cocina.posicion.fil = rand() % MAX_FILAS;
        juego->cocina.posicion.col = rand() % MAX_COLUMNAS;
        
        for (int i = 0; i < MAX_OBSTACULOS; i++){
            juego->obstaculos[i].posicion.fil = rand() % MAX_FILAS;
            juego->obstaculos[i].posicion.col = rand() % MAX_COLUMNAS;
        }

        for (int i = 0; i < MAX_HERRAMIENTAS; i++){
            juego->herramientas[i].posicion.fil = rand() % MAX_FILAS;
            juego->herramientas[i].posicion.col = rand() % MAX_COLUMNAS;
        }

        //Modificar criterios del while
    } while (juego->cocina.posicion.fil == juego->mozo.posicion.fil && juego->cocina.posicion.col == juego->mozo.posicion.col);
    
    //Rehacer toda la logica de las mesas y agregar los pasillos
    juego->cantidad_mesas = 0;
    for (int i = 0; i < MAX_MESAS; i++) {
        coordenada_t nueva_posicion;
        bool posicion_ocupada;

        do {
            posicion_ocupada = false;
            nueva_posicion.fil = rand() % MAX_FILAS;
            nueva_posicion.col = rand() % MAX_COLUMNAS;

            for (int j = 0; j < juego->cantidad_mesas; j++) {
                if (juego->mesas[j].posicion[0].fil == nueva_posicion.fil &&juego->mesas[j].posicion[0].col == nueva_posicion.col) {
                    posicion_ocupada = true;
                    break;
                }
            }

            if (juego->cocina.posicion.fil == nueva_posicion.fil && juego->cocina.posicion.col == nueva_posicion.col) {
                posicion_ocupada = true;
            }
            if (juego->mozo.posicion.fil == nueva_posicion.fil && juego->mozo.posicion.col == nueva_posicion.col) {
                posicion_ocupada = true;
            }

        } while (posicion_ocupada);

        juego->mesas[i].posicion[0] = nueva_posicion;
        juego->cantidad_mesas++;
    }
}

// PRE: El juego debe estar inicializado previamente con `inicializar_juego` y la acción debe ser válida.
// POST: Realizará la acción recibida por parámetro. Para este primer TP solo se implementará el funcionamiento para mover al jugador y agarrar/soltar la mopa.
void realizar_jugada(juego_t *juego, char accion){
    switch (accion) { //Cambia la posicion pero no actualiza el caracter de la matriz
        case ARRIBA:
            if (juego->mozo.posicion.fil > 0){
                juego->mozo.posicion.fil--;
            }
        break;
        case ABAJO:
            if (juego->mozo.posicion.fil < MAX_FILAS - 1){
                juego->mozo.posicion.fil++;
            }
        break;
        case DERECHA:
            if (juego->mozo.posicion.col < MAX_COLUMNAS - 1){
                juego->mozo.posicion.col++;
            }
        break;
        case IZQUIERDA:
            if (juego->mozo.posicion.col > 0){
                juego->mozo.posicion.col--;
            }
        break;
        case MOPA:
            if (juego->mozo.tiene_mopa == false){
                juego->mozo.tiene_mopa = true;
            } else juego->mozo.tiene_mopa = false;
        break;
    }
}

// PRE: El juego debe estar inicializado previamente con `inicializar_juego`.
// POST: Imprime el juego por pantalla.
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

// PRE: El juego deberá estar inicializado previamente con `inicializar_juego`
// POST: Devuelve: 1 si es ganado, -1 si es perdido, 0 si se sigue jugando.
//       El juego se dará por ganado cuando se termina el día y se consiguieron las monedas necesarias.
//       Se dará por perdido si se termina el día y no se llegó al monto.
int estado_juego(juego_t juego){

}
