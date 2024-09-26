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
const int CANTIDAD_CUCARACHAS = 0;
const int MAX_MESAS_INDIVIDUALES = 6;
const int MAX_MESAS_GRUPALES = 4;
const int OBJETIVO_DINERO = 150000;

void inicializar_terreno(juego_t juego) {
    for (int i = 0; i < MAX_FILAS; i++) {
        for (int j = 0; j < MAX_COLUMNAS; j++) {
            char contenido_posicion = VACIO;

            if (juego.mozo.posicion.fil == i && juego.mozo.posicion.col == j) {
                contenido_posicion = LINGUINI;
            } else if (juego.cocina.posicion.fil == i && juego.cocina.posicion.col == j) {
                contenido_posicion = COCINA;
            } else {
                for (int k = 0; k < juego.cantidad_obstaculos; k++) {
                    if (juego.obstaculos[k].posicion.fil == i && juego.obstaculos[k].posicion.col == j) {
                        switch (juego.obstaculos[k].tipo) {
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
                    switch (juego.herramientas[k].tipo) {
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

bool posicion_ocupada(coordenada_t posicion, coordenada_t posiciones_ocupadas[], int tope) {
    for (int i = 0; i < tope; i++) {
        if (posiciones_ocupadas[i].fil == posicion.fil && posiciones_ocupadas[i].col == posicion.col) {
            return true;
        }
    }
    return false;
}

void inicializar_mesas_individuales(mesa_t mesas_individuales[], coordenada_t posiciones_ocupadas[], int* cantidad_ocupadas) {
    for (int i = 0; i < MAX_MESAS_INDIVIDUALES; i++) {
        mesas_individuales[i].cantidad_lugares = MAX_MESAS_INDIVIDUALES;

        for (int j = 0; j < MAX_POSICION; j++) {
            do {
                mesas_individuales[i].posicion[j].fil = rand() % MAX_FILAS;
                mesas_individuales[i].posicion[j].col = rand() % MAX_COLUMNAS;
            } while (posicion_ocupada(mesas_individuales[i].posicion[j], posiciones_ocupadas, *cantidad_ocupadas));

            posiciones_ocupadas[(*cantidad_ocupadas)++] = mesas_individuales[i].posicion[j];
            printf(" %c", MESA);

        }
    }
}

void inicializar_mesas_grupales(mesa_t mesas_grupales[], coordenada_t posiciones_ocupadas[], int* cantidad_ocupadas) {
    for (int i = 0; i < MAX_MESAS_GRUPALES; i++) {
        mesas_grupales[i].cantidad_lugares = MAX_MESAS_GRUPALES;

        coordenada_t posicion_guia;
        int intentos = 0;
        do {
            posicion_guia.fil = rand() % (MAX_FILAS - 1) + 1;
            posicion_guia.col = rand() % (MAX_COLUMNAS - 1) + 1;
            intentos++;
            if (intentos > (MAX_FILAS * MAX_COLUMNAS)) return;
        } while (posicion_ocupada(posicion_guia, posiciones_ocupadas, *cantidad_ocupadas));

        coordenada_t posicion_1;
        posicion_1.fil = posicion_guia.fil;
        posicion_1.col = posicion_guia.col + 1;

        coordenada_t posicion_2;
        posicion_2.fil = posicion_guia.fil - 1;
        posicion_2.col = posicion_guia.col;

        coordenada_t posicion_3;
        posicion_3.fil = posicion_guia.fil - 1;
        posicion_3.col = posicion_guia.col + 1;
        
        while (posicion_ocupada(posicion_1, posiciones_ocupadas, *cantidad_ocupadas) ||
               posicion_ocupada(posicion_2, posiciones_ocupadas, *cantidad_ocupadas) ||
               posicion_ocupada(posicion_3, posiciones_ocupadas, *cantidad_ocupadas)) {
            
            do {
                posicion_guia.fil = rand() % (MAX_FILAS - 1) + 1;
                posicion_guia.col = rand() % (MAX_COLUMNAS - 1) + 1;
            } while (es_posicion_ocupada(posicion_guia, posiciones_ocupadas, *cantidad_ocupadas));

            posicion_1.fil = posicion_guia.fil;
            posicion_1.col = posicion_guia.col + 1;

            posicion_2.fil = posicion_guia.fil + 1;
            posicion_2.col = posicion_guia.col;

            posicion_3.fil = posicion_guia.fil + 1;
            posicion_3.col = posicion_guia.col + 1;
        }

        mesas_grupales[i].posicion[0] = posicion_guia;
        mesas_grupales[i].posicion[1] = posicion_1;
        mesas_grupales[i].posicion[2] = posicion_2;
        mesas_grupales[i].posicion[3] = posicion_3;

        for (int j = 0; j < MAX_MESAS_GRUPALES; j++) {
            posiciones_ocupadas[(*cantidad_ocupadas)++] = mesas_grupales[i].posicion[j];
            printf(" %c", MESA);
        }
    }
}

void inicializar_linguini(juego_t *juego, coordenada_t posiciones_ocupadas[], int* cantidad_ocupadas) {
    do {
        juego->mozo.posicion.fil  = rand() % MAX_FILAS;
        juego->mozo.posicion.col  = rand() % MAX_COLUMNAS;
    } while (posicion_ocupada(juego->mozo.posicion, posiciones_ocupadas, *cantidad_ocupadas));
    posiciones_ocupadas[(*cantidad_ocupadas)++] = juego->mozo.posicion;
    printf(" %c", LINGUINI);
}

void inicializar_cocina(juego_t *juego, coordenada_t posiciones_ocupadas[], int* cantidad_ocupadas) {
    do {
        juego->cocina.posicion.fil  = rand() % MAX_FILAS;
        juego->cocina.posicion.col  = rand() % MAX_COLUMNAS;
    } while (posicion_ocupada(juego->cocina.posicion, posiciones_ocupadas, *cantidad_ocupadas));
    posiciones_ocupadas[(*cantidad_ocupadas)++] = juego->cocina.posicion;
    printf(" %c", COCINA);
}

void inicializar_mopa(juego_t *juego, coordenada_t posiciones_ocupadas[], int* cantidad_ocupadas) {
    juego->herramientas[0].tipo = MOPA;
    do {
        juego->herramientas[0].posicion.fil  = rand() % MAX_FILAS;
        juego->herramientas[0].posicion.col  = rand() % MAX_COLUMNAS;
    } while (posicion_ocupada(juego->herramientas[0].posicion, posiciones_ocupadas, *cantidad_ocupadas));
    posiciones_ocupadas[(*cantidad_ocupadas)++] = juego->herramientas[0].posicion;
    printf(" %c", MOPA);
}

void inicializar_monedas(juego_t *juego, coordenada_t posiciones_ocupadas[], int* cantidad_ocupadas) {
    for (int i = 0; i < CANTIDAD_MONEDAS; i++){
        do {
            juego->herramientas[i].posicion.fil  = rand() % MAX_FILAS;
            juego->herramientas[i].posicion.col  = rand() % MAX_COLUMNAS;
        } while (posicion_ocupada(juego->herramientas[i].posicion, posiciones_ocupadas, *cantidad_ocupadas));
        posiciones_ocupadas[(*cantidad_ocupadas)++] = juego->herramientas[i].posicion;
        printf(" %c", MONEDA);
    }
}

void inicializar_patines(juego_t *juego, coordenada_t posiciones_ocupadas[], int* cantidad_ocupadas) {
    for (int i = 0; i < CANTIDAD_PATINES; i++){
        do {
            juego->herramientas[(CANTIDAD_MONEDAS - 1) + i].posicion.fil  = rand() % MAX_FILAS;
            juego->herramientas[(CANTIDAD_MONEDAS - 1) + i].posicion.col  = rand() % MAX_COLUMNAS;
        } while (posicion_ocupada(juego->herramientas[(CANTIDAD_MONEDAS - 1) + i].posicion, posiciones_ocupadas, *cantidad_ocupadas));
        posiciones_ocupadas[(*cantidad_ocupadas)++] = juego->herramientas[(CANTIDAD_MONEDAS - 1) + i].posicion;
        printf(" %c", PATINES);
    }
}

void inicializar_charcos(juego_t *juego, coordenada_t posiciones_ocupadas[], int* cantidad_ocupadas) {
    for (int i = 0; i < CANTIDAD_CHARCOS; i++){
        do {
            juego->obstaculos[i].posicion.fil  = rand() % MAX_FILAS;
            juego->obstaculos[i].posicion.col  = rand() % MAX_COLUMNAS;
        } while (posicion_ocupada(juego->obstaculos[i].posicion, posiciones_ocupadas, *cantidad_ocupadas));
        posiciones_ocupadas[(*cantidad_ocupadas)++] = juego->obstaculos[i].posicion;
        printf(" %c", CHARCO);
    }
}

void inicializar_cucarachas(juego_t *juego, coordenada_t posiciones_ocupadas[], int* cantidad_ocupadas) {
    for (int i = 0; i < CANTIDAD_CUCARACHAS; i++){
        do {
            juego->obstaculos[(CANTIDAD_CHARCOS - 1) + i].posicion.fil  = rand() % MAX_FILAS;
            juego->obstaculos[(CANTIDAD_CHARCOS - 1) + i].posicion.col  = rand() % MAX_COLUMNAS;
        } while (posicion_ocupada(juego->obstaculos[(CANTIDAD_CHARCOS - 1) + i].posicion, posiciones_ocupadas, *cantidad_ocupadas));
        posiciones_ocupadas[(*cantidad_ocupadas)++] = juego->obstaculos[(CANTIDAD_CHARCOS - 1) + i].posicion;
        printf(" %c", CUCARACHA);
    }
}
