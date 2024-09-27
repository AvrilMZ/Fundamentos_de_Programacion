#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "restaurant.h"

#define ARRIBA 'W'
#define ABAJO 'S'
#define DERECHA 'D'
#define IZQUIERDA 'A'
#define MOPA 'O'
#define MAX_MESAS_INDIVIDUALES 6
#define MAX_MESAS_GRUPALES 4

const char LINGUINI = 'L';
const char MESA = 'T';
const char COCINA = 'C';
const char CHARCO = 'H';
const char MONEDA = 'M';
const char PATINES = 'P';
const char CUCARACHA = ' ';
const char VACIO = ' ';

const int CANTIDAD_CHARCOS = 5;
const int CANTIDAD_MONEDAS = 8;
const int CANTIDAD_PATINES = 5;
const int CANTIDAD_CUCARACHAS = 0;
const int OBJETIVO_DINERO = 150000;
const int MAX_MOVIMIENTOS = 200;

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

bool pasillos_libres(mesa_t mesas[], int max_mesas, coordenada_t posiciones_ocupadas[], int* cantidad_ocupadas) {
    coordenada_t posicion_guia;

    for (int i = 0; i < max_mesas; i++) {
        for (int j = 0; j < mesas[i].cantidad_lugares; j++) {
            posicion_guia = mesas[i].posicion[j];
            int rango = 0;

            if (mesas[i].cantidad_lugares == 1) {
                rango = 1;
            } else rango = 2;
            

            if (mesas[i].cantidad_lugares = 1) {

                for (int x = -1; x <= 1; x++) {
                    for (int y = -1; y <= 1; y++) {

                        if (abs(x) + abs(y) == 1) {
                            coordenada_t nueva_pos = {posicion_guia.col + x, posicion_guia.fil + y};
                            if (posicion_ocupada(nueva_pos, posiciones_ocupadas, *cantidad_ocupadas)) {
                                return false;
                            }
                        }
                    }
                }

            } else if (mesas[i].cantidad_lugares == 4) {
                for (int x = -2; x <= 2; x++) {
                    for (int y = -2; y <= 2; y++) {

                        if (abs(x) + abs(y) <= 2) {
                            coordenada_t nueva_pos = {posicion_guia.col + x, posicion_guia.fil + y};
                            if (posicion_ocupada(nueva_pos, posiciones_ocupadas, *cantidad_ocupadas)) {
                                return false;
                            }
                        }
                    }
                }
            }
        }
    }

    return true;
}

void inicializar_mesas_individuales(mesa_t mesas_individuales[], coordenada_t posiciones_ocupadas[], int* cantidad_ocupadas) {
    for (int i = 0; i < MAX_MESAS_INDIVIDUALES; i++) {
        mesas_individuales[i].cantidad_lugares = 1;

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
        mesas_grupales[i].cantidad_lugares = 4;

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
            } while (posicion_ocupada(posicion_guia, posiciones_ocupadas, *cantidad_ocupadas));

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
    for (int i = 0; i < CANTIDAD_MONEDAS; i++) {
        do {
            juego->herramientas[i].posicion.fil  = rand() % MAX_FILAS;
            juego->herramientas[i].posicion.col  = rand() % MAX_COLUMNAS;
        } while (posicion_ocupada(juego->herramientas[i].posicion, posiciones_ocupadas, *cantidad_ocupadas));
        posiciones_ocupadas[(*cantidad_ocupadas)++] = juego->herramientas[i].posicion;
        printf(" %c", MONEDA);
    }
}

void inicializar_patines(juego_t *juego, coordenada_t posiciones_ocupadas[], int* cantidad_ocupadas) {
    for (int i = 0; i < CANTIDAD_PATINES; i++) {
        do {
            juego->herramientas[(CANTIDAD_MONEDAS - 1) + i].posicion.fil  = rand() % MAX_FILAS;
            juego->herramientas[(CANTIDAD_MONEDAS - 1) + i].posicion.col  = rand() % MAX_COLUMNAS;
        } while (posicion_ocupada(juego->herramientas[(CANTIDAD_MONEDAS - 1) + i].posicion, posiciones_ocupadas, *cantidad_ocupadas));
        posiciones_ocupadas[(*cantidad_ocupadas)++] = juego->herramientas[(CANTIDAD_MONEDAS - 1) + i].posicion;
        printf(" %c", PATINES);
    }
}

void inicializar_charcos(juego_t *juego, coordenada_t posiciones_ocupadas[], int* cantidad_ocupadas) {
    for (int i = 0; i < CANTIDAD_CHARCOS; i++) {
        do {
            juego->obstaculos[i].posicion.fil  = rand() % MAX_FILAS;
            juego->obstaculos[i].posicion.col  = rand() % MAX_COLUMNAS;
        } while (posicion_ocupada(juego->obstaculos[i].posicion, posiciones_ocupadas, *cantidad_ocupadas));
        posiciones_ocupadas[(*cantidad_ocupadas)++] = juego->obstaculos[i].posicion;
        printf(" %c", CHARCO);
    }
}

void inicializar_cucarachas(juego_t *juego, coordenada_t posiciones_ocupadas[], int* cantidad_ocupadas) {
    for (int i = 0; i < CANTIDAD_CUCARACHAS; i++) {
        do {
            juego->obstaculos[(CANTIDAD_CHARCOS - 1) + i].posicion.fil  = rand() % MAX_FILAS;
            juego->obstaculos[(CANTIDAD_CHARCOS - 1) + i].posicion.col  = rand() % MAX_COLUMNAS;
        } while (posicion_ocupada(juego->obstaculos[(CANTIDAD_CHARCOS - 1) + i].posicion, posiciones_ocupadas, *cantidad_ocupadas));
        posiciones_ocupadas[(*cantidad_ocupadas)++] = juego->obstaculos[(CANTIDAD_CHARCOS - 1) + i].posicion;
        printf(" %c", CUCARACHA);
    }
}

void interaccion_herramientas(juego_t *juego) {
    for (int i = 0; i < MAX_HERRAMIENTAS; i++) {
        if (juego->mozo.posicion.fil == juego->herramientas[i].posicion.fil && juego->mozo.posicion.col == juego->herramientas[i].posicion.col) {
            if (juego->herramientas[i].tipo == MONEDA) {
                juego->dinero++;
            } else if (juego->herramientas[i].tipo == PATINES) {
                juego->mozo.patines_puestos = true;
            } //falta q pasaria con la mopa
        }
    }
}

// PRE: -
// POST: Inicializará el juego, cargando toda la información inicial de Linguini, las mesas, las herramientas y los obstáculos.
void inicializar_juego(juego_t *juego) {
    coordenada_t posiciones_ocupadas[(MAX_FILAS * MAX_COLUMNAS) / 2];
    int cantidad_posiciones_ocupadas = 0;
    mesa_t mesas_individuales[MAX_MESAS_INDIVIDUALES];
    mesa_t mesas_grupales[MAX_MESAS_GRUPALES];
    
    inicializar_mesas_grupales(mesas_grupales, posiciones_ocupadas, &cantidad_posiciones_ocupadas);
    inicializar_mesas_individuales(mesas_individuales, posiciones_ocupadas, &cantidad_posiciones_ocupadas);
    inicializar_cocina(juego, posiciones_ocupadas, &cantidad_posiciones_ocupadas);
    inicializar_patines(juego, posiciones_ocupadas, &cantidad_posiciones_ocupadas);
    inicializar_charcos(juego, posiciones_ocupadas, &cantidad_posiciones_ocupadas);
    inicializar_mopa(juego, posiciones_ocupadas, &cantidad_posiciones_ocupadas);
    inicializar_linguini(juego, posiciones_ocupadas, &cantidad_posiciones_ocupadas);
    inicializar_cucarachas(juego, posiciones_ocupadas, &cantidad_posiciones_ocupadas);
    inicializar_monedas(juego, posiciones_ocupadas, &cantidad_posiciones_ocupadas);
    inicializar_terreno(*juego);
}

// PRE: El juego debe estar inicializado previamente con `inicializar_juego` y la acción debe ser válida.
// POST: Realizará la acción recibida por parámetro. Para este primer TP solo se implementará el funcionamiento para mover al jugador y agarrar/soltar la mopa.
void realizar_jugada(juego_t *juego, char accion) {
    while (accion != ARRIBA && accion != ABAJO && accion != DERECHA && accion != IZQUIERDA && accion != MOPA){
        printf("Ingrese un movimiento valido (W/S/A/D) ó interactue con la mopa (O):\n");
        scanf(" %c", &accion);
    }

    switch (accion) {
        case ARRIBA:
            if (juego->mozo.posicion.fil > 0) {
                juego->mozo.posicion.fil--;
            }
        break;
        case ABAJO:
            if (juego->mozo.posicion.fil < MAX_FILAS - 1) {
                juego->mozo.posicion.fil++;
            }
        break;
        case DERECHA:
            if (juego->mozo.posicion.col < MAX_COLUMNAS - 1) {
                juego->mozo.posicion.col++;
            }
        break;
        case IZQUIERDA:
            if (juego->mozo.posicion.col > 0) {
                juego->mozo.posicion.col--;
            }
        break;
        case MOPA:
            if (juego->mozo.tiene_mopa == false) {
                juego->mozo.tiene_mopa = true;
            } else juego->mozo.tiene_mopa = false;
        break;
    }
}

// PRE: El juego debe estar inicializado previamente con `inicializar_juego`.
// POST: Imprime el juego por pantalla.
void mostrar_juego(juego_t juego) {
    while (juego.movimientos < MAX_MOVIMIENTOS) {
        system("clear");
        inicializar_terreno(juego);
        juego.movimientos++;
    }
}

// PRE: El juego deberá estar inicializado previamente con `inicializar_juego`
// POST: Devuelve: 1 si es ganado, -1 si es perdido, 0 si se sigue jugando.
//       El juego se dará por ganado cuando se termina el día y se consiguieron las monedas necesarias.
//       Se dará por perdido si se termina el día y no se llegó al monto.
int estado_juego(juego_t juego) {
    if (juego.movimientos == MAX_MOVIMIENTOS){
        if (juego.dinero == OBJETIVO_DINERO){
            return 1;
        } else return -1;
    } else return 0;
}
