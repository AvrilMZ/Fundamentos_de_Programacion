#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "restaurant.h"

#define ARRIBA 'W'
#define ABAJO 'S'
#define DERECHA 'D'
#define IZQUIERDA 'A'
#define MOPA 'O'
#define CHARCO 'H'
#define MONEDA 'M'
#define PATINES 'P'
#define CUCARACHA ' '
#define MAX_MESAS_INDIVIDUALES 6
#define MAX_MESAS_GRUPALES 4

const char LINGUINI = 'L';
const char MESA = 'T';
const char COCINA = 'C';
const char VACIO = ' ';

const int CANTIDAD_CHARCOS = 5;
const int CANTIDAD_MONEDAS = 8;
const int CANTIDAD_PATINES = 5;
const int CANTIDAD_CUCARACHAS = 0;
const int OBJETIVO_DINERO = 150000;
const int MAX_MOVIMIENTOS = 200;

// PRE: 
// POST: Imprime por pantalla el terreno de juego con los elementos en sus posiciones.
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

// PRE: 
// POST: Devuelve true si la posicion ya esta almacenada en el vector posiciones_ocupadas, de lo contrario devuelve false.
bool es_posicion_ocupada(coordenada_t posicion, coordenada_t posiciones_ocupadas[], int cantidad_posiciones_ocupadas) {
    for (int i = 0; i < cantidad_posiciones_ocupadas; i++) {
        if (posiciones_ocupadas[i].fil == posicion.fil && posiciones_ocupadas[i].col == posicion.col) {
            return true;
        }
    }
    return false;
}

// PRE: 
// POST: 
/*
bool es_pasillos_libres(mesa_t mesas[], int max_mesas, coordenada_t posiciones_ocupadas[], int* cantidad_posiciones_ocupadas) {
    coordenada_t posicion_guia;

    for (int i = 0; i < max_mesas; i++) {
        for (int j = 0; j < mesas[i].cantidad_lugares; j++) {
            posicion_guia = mesas[i].posicion[j];
            int rango = 0;

            if (mesas[i].cantidad_lugares == 1) {
                rango = 1;
            } else rango = 2;
            

            if (mesas[i].cantidad_lugares == 4) {

                for (int x = -1; x <= 1; x++) {
                    for (int y = -1; y <= 1; y++) {

                        if (abs(x) + abs(y) == 1) {
                            coordenada_t nueva_pos = {posicion_guia.col + x, posicion_guia.fil + y};
                            if (es_posicion_ocupada(nueva_pos, posiciones_ocupadas, *cantidad_posiciones_ocupadas)) {
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
                            if (es_posicion_ocupada(nueva_pos, posiciones_ocupadas, *cantidad_posiciones_ocupadas)) {
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
*/

// PRE: 
// POST: Inicializa todas las mesas individuales en una posicion aleatoria, si la posicion ya esta ocupada le asigna 
//       nuevamente otra aleatoria.
void inicializar_mesas_individuales(mesa_t mesas_individuales[], coordenada_t posiciones_ocupadas[], int* cantidad_posiciones_ocupadas) {
    for (int i = 0; i < MAX_MESAS_INDIVIDUALES; i++) {
        mesas_individuales[i].cantidad_lugares = 1;
        
        int intentos = 0;
        do {
            mesas_individuales[i].posicion[0].fil = rand() % MAX_FILAS;
            mesas_individuales[i].posicion[0].col = rand() % MAX_COLUMNAS;
            intentos++;
            if (intentos > (MAX_FILAS * MAX_COLUMNAS)) return -1;
        } while (es_posicion_ocupada(mesas_individuales[i].posicion[0], posiciones_ocupadas, *cantidad_posiciones_ocupadas));

        posiciones_ocupadas[*cantidad_posiciones_ocupadas] = mesas_individuales[i].posicion[0];
        *cantidad_posiciones_ocupadas++;
        printf(" %c", MESA);
    }
}

// PRE: 
// POST: Inicializa todas las mesas grupales en una posicion aleatoria, si la posicion ya esta ocupada le asigna 
//       nuevamente otra aleatoria.
void inicializar_mesas_grupales(mesa_t mesas_grupales[], coordenada_t posiciones_ocupadas[], int* cantidad_posiciones_ocupadas) {
    for (int i = 0; i < MAX_MESAS_GRUPALES; i++) {
        mesas_grupales[i].cantidad_lugares = 4;

        coordenada_t posicion_guia;
        int intentos = 0;
        do {
            posicion_guia.fil = rand() % (MAX_FILAS - 1);
            posicion_guia.col = rand() % (MAX_COLUMNAS - 1);
            intentos++;
            if (intentos > ((MAX_FILAS * MAX_COLUMNAS) - (MAX_FILAS + MAX_COLUMNAS))) return -1;
        } while (es_posicion_ocupada(posicion_guia, posiciones_ocupadas, *cantidad_posiciones_ocupadas));

        coordenada_t posicion_derecha;
        posicion_derecha.fil = posicion_guia.fil;
        posicion_derecha.col = posicion_guia.col + 1;

        coordenada_t posicion_abajo;
        posicion_abajo.fil = posicion_guia.fil - 1;
        posicion_abajo.col = posicion_guia.col;

        coordenada_t posicion_abajo_derecha;
        posicion_abajo_derecha.fil = posicion_guia.fil - 1;
        posicion_abajo_derecha.col = posicion_guia.col + 1;
        
        while (es_posicion_ocupada(posicion_derecha, posiciones_ocupadas, *cantidad_posiciones_ocupadas) ||
               es_posicion_ocupada(posicion_abajo, posiciones_ocupadas, *cantidad_posiciones_ocupadas) ||
               es_posicion_ocupada(posicion_abajo_derecha, posiciones_ocupadas, *cantidad_posiciones_ocupadas)) {
            
            do {
                posicion_guia.fil = rand() % (MAX_FILAS - 1);
                posicion_guia.col = rand() % (MAX_COLUMNAS - 1);
            } while (es_posicion_ocupada(posicion_guia, posiciones_ocupadas, *cantidad_posiciones_ocupadas));

            posicion_derecha.fil = posicion_guia.fil;
            posicion_derecha.col = posicion_guia.col + 1;

            posicion_abajo.fil = posicion_guia.fil + 1;
            posicion_abajo.col = posicion_guia.col;

            posicion_abajo_derecha.fil = posicion_guia.fil + 1;
            posicion_abajo_derecha.col = posicion_guia.col + 1;
        }

        mesas_grupales[i].posicion[0] = posicion_guia;
        mesas_grupales[i].posicion[1] = posicion_derecha;
        mesas_grupales[i].posicion[2] = posicion_abajo;
        mesas_grupales[i].posicion[3] = posicion_abajo_derecha;

        for (int j = 0; j < mesas_grupales[i].cantidad_lugares; j++) {
            posiciones_ocupadas[*cantidad_posiciones_ocupadas] = mesas_grupales[i].posicion[j];
            *cantidad_posiciones_ocupadas++;
            printf(" %c", MESA);
        }
    }
}

// PRE: 
// POST: Inicializa al personaje en una posicion aleatoria, si la posicion ya esta ocupada le asigna
//       nuevamente otra aleatoria.
void inicializar_linguini(juego_t *juego, coordenada_t posiciones_ocupadas[], int* cantidad_posiciones_ocupadas) {
    int intentos = 0;
    do {
        juego->mozo.posicion.fil = rand() % MAX_FILAS;
        juego->mozo.posicion.col = rand() % MAX_COLUMNAS;
        intentos++;
        if (intentos > (MAX_FILAS * MAX_COLUMNAS)) return -1;
    } while (es_posicion_ocupada(juego->mozo.posicion, posiciones_ocupadas, *cantidad_posiciones_ocupadas));

    posiciones_ocupadas[*cantidad_posiciones_ocupadas] = juego->mozo.posicion;
    *cantidad_posiciones_ocupadas++;
    printf(" %c", LINGUINI);
}

// PRE: 
// POST: Inicializa a la cocina en una posicion aleatoria, si la posicion ya esta ocupada le asigna
//       nuevamente otra aleatoria.
void inicializar_cocina(juego_t *juego, coordenada_t posiciones_ocupadas[], int* cantidad_posiciones_ocupadas) {
    int intentos = 0;
    do {
        juego->cocina.posicion.fil = rand() % MAX_FILAS;
        juego->cocina.posicion.col = rand() % MAX_COLUMNAS;
        intentos++;
        if (intentos > (MAX_FILAS * MAX_COLUMNAS)) return -1;
    } while (es_posicion_ocupada(juego->cocina.posicion, posiciones_ocupadas, *cantidad_posiciones_ocupadas));

    posiciones_ocupadas[*cantidad_posiciones_ocupadas] = juego->cocina.posicion;
    *cantidad_posiciones_ocupadas++;
    printf(" %c", COCINA);
}

//RESVISAR!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
void inicializar_herramienta(juego_t *juego, int tipo_herramienta, coordenada_t posiciones_ocupadas[], int *cantidad_posiciones_ocupadas) {
    coordenada_t posicion;
    int intentos = 0;

    do {
        posicion.fil = rand() % MAX_FILAS;
        posicion.col = rand() % MAX_COLUMNAS;
        intentos++;
        if (intentos > (MAX_FILAS * MAX_COLUMNAS)) return -1; 
    } while (es_posicion_ocupada(posicion, posiciones_ocupadas, *cantidad_posiciones_ocupadas));

    juego->herramientas[*cantidad_posiciones_ocupadas].tipo = tipo_herramienta;
    juego->herramientas[*cantidad_posiciones_ocupadas].posicion = posicion;

    posiciones_ocupadas[*cantidad_posiciones_ocupadas] = posicion;
    *cantidad_posiciones_ocupadas++;
}

//RESVISAR!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
void inicializar_mopa(juego_t *juego, coordenada_t posiciones_ocupadas[], int *cantidad_posiciones_ocupadas) {
    inicializar_herramienta(juego, MOPA, posiciones_ocupadas, cantidad_posiciones_ocupadas);
}

//RESVISAR!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
void inicializar_monedas(juego_t *juego, coordenada_t posiciones_ocupadas[], int *cantidad_posiciones_ocupadas) {
    for (int i = 0; i < CANTIDAD_MONEDAS; i++) {
        inicializar_herramienta(juego, MONEDA, posiciones_ocupadas, cantidad_posiciones_ocupadas);
    }
}

//RESVISAR!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
void inicializar_patines(juego_t *juego, coordenada_t posiciones_ocupadas[], int *cantidad_posiciones_ocupadas) {
    for (int i = 0; i < CANTIDAD_PATINES; i++) {
        inicializar_herramienta(juego, PATINES, posiciones_ocupadas, cantidad_posiciones_ocupadas);
    }
}



// PRE: 
// POST: Inicializa la mopa en una posicion aleatoria, si la posicion ya esta ocupada le asigna
//       nuevamente otra aleatoria.
void inicializar_mopa(juego_t *juego, coordenada_t posiciones_ocupadas[], int* cantidad_posiciones_ocupadas) {
    juego->herramientas[0].tipo = MOPA;

    int intentos = 0;
    do {
        juego->herramientas[0].posicion.fil = rand() % MAX_FILAS;
        juego->herramientas[0].posicion.col = rand() % MAX_COLUMNAS;
        intentos++;
        if (intentos > (MAX_FILAS * MAX_COLUMNAS)) return -1;
    } while (es_posicion_ocupada(juego->herramientas[0].posicion, posiciones_ocupadas, *cantidad_posiciones_ocupadas));

    posiciones_ocupadas[*cantidad_posiciones_ocupadas] = juego->herramientas[0].posicion;
    *cantidad_posiciones_ocupadas++;
    printf(" %c", MOPA);
}

// PRE: 
// POST: Inicializa las monedas en posiciones aleatorias, si la posicion ya esta ocupada le asigna
//       nuevamente otra aleatoria.
void inicializar_monedas(juego_t *juego, coordenada_t posiciones_ocupadas[], int* cantidad_posiciones_ocupadas) {
    int intentos = 0;
    for (int i = 0; i < CANTIDAD_MONEDAS; i++) {
        do {
            juego->herramientas[i].posicion.fil  = rand() % MAX_FILAS;
            juego->herramientas[i].posicion.col  = rand() % MAX_COLUMNAS;
            intentos++;
            if (intentos > (MAX_FILAS * MAX_COLUMNAS)) return -1;
        } while (es_posicion_ocupada(juego->herramientas[i].posicion, posiciones_ocupadas, *cantidad_posiciones_ocupadas));

        posiciones_ocupadas[*cantidad_posiciones_ocupadas] = juego->herramientas[i].posicion;
        *cantidad_posiciones_ocupadas++;
        printf(" %c", MONEDA);
    }
}

// PRE: 
// POST: Inicializa los patines en posiciones aleatorias, si la posicion ya esta ocupada le asigna
//       nuevamente otra aleatoria.
void inicializar_patines(juego_t *juego, coordenada_t posiciones_ocupadas[], int* cantidad_posiciones_ocupadas) {
    int intentos = 0;
    for (int i = 0; i < CANTIDAD_PATINES; i++) {
        do {
            juego->herramientas[(CANTIDAD_MONEDAS - 1) + i].posicion.fil  = rand() % MAX_FILAS;
            juego->herramientas[(CANTIDAD_MONEDAS - 1) + i].posicion.col  = rand() % MAX_COLUMNAS;
            intentos++;
            if (intentos > (MAX_FILAS * MAX_COLUMNAS)) return -1;
        } while (es_posicion_ocupada(juego->herramientas[(CANTIDAD_MONEDAS - 1) + i].posicion, posiciones_ocupadas, *cantidad_posiciones_ocupadas));

        posiciones_ocupadas[*cantidad_posiciones_ocupadas] = juego->herramientas[(CANTIDAD_MONEDAS - 1) + i].posicion;
        *cantidad_posiciones_ocupadas++;
        printf(" %c", PATINES);
    }
}

//RESVISAR!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
void inicializar_obstaculo(juego_t *juego, int tipo_obstaculo, coordenada_t posiciones_ocupadas[], int *cantidad_posiciones_ocupadas) {
    coordenada_t posicion;
    int intentos = 0;

    do {
        posicion.fil = rand() % MAX_FILAS;
        posicion.col = rand() % MAX_COLUMNAS;
        intentos++;
        if (intentos > (MAX_FILAS * MAX_COLUMNAS)) return -1; 
    } while (es_posicion_ocupada(posicion, posiciones_ocupadas, *cantidad_posiciones_ocupadas));

    juego->obstaculos[*cantidad_posiciones_ocupadas].tipo = tipo_obstaculo;
    juego->obstaculos[*cantidad_posiciones_ocupadas].posicion = posicion;

    posiciones_ocupadas[*cantidad_posiciones_ocupadas] = posicion;
    *cantidad_posiciones_ocupadas++;
}

//RESVISAR!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
void inicializar_charcos(juego_t *juego, coordenada_t posiciones_ocupadas[], int *cantidad_posiciones_ocupadas) {
    for (int i = 0; i < CANTIDAD_CHARCOS; i++) {
        inicializar_obstaculo(juego, CHARCO, posiciones_ocupadas, cantidad_posiciones_ocupadas);
    }
}

//RESVISAR!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
void inicializar_cucarachas(juego_t *juego, coordenada_t posiciones_ocupadas[], int *cantidad_posiciones_ocupadas) {
    for (int i = 0; i < CANTIDAD_CUCARACHAS; i++) {
        inicializar_obstaculo(juego, CUCARACHA, posiciones_ocupadas, cantidad_posiciones_ocupadas);
    }
}

// PRE: 
// POST: Inicializa los charcos en posiciones aleatorias, si la posicion ya esta ocupada le asigna
//       nuevamente otra aleatoria.
void inicializar_charcos(juego_t *juego, coordenada_t posiciones_ocupadas[], int* cantidad_posiciones_ocupadas) {
    int intentos = 0;
    for (int i = 0; i < CANTIDAD_CHARCOS; i++) {
        do {
            juego->obstaculos[i].posicion.fil  = rand() % MAX_FILAS;
            juego->obstaculos[i].posicion.col  = rand() % MAX_COLUMNAS;
            intentos++;
            if (intentos > (MAX_FILAS * MAX_COLUMNAS)) return -1;
        } while (es_posicion_ocupada(juego->obstaculos[i].posicion, posiciones_ocupadas, *cantidad_posiciones_ocupadas));

        posiciones_ocupadas[*cantidad_posiciones_ocupadas] = juego->obstaculos[i].posicion;
        *cantidad_posiciones_ocupadas++;
        printf(" %c", CHARCO);
    }
}

// PRE: 
// POST: Inicializa las cucarachas en posiciones aleatorias, si la posicion ya esta ocupada le asigna
//       nuevamente otra aleatoria.
void inicializar_cucarachas(juego_t *juego, coordenada_t posiciones_ocupadas[], int* cantidad_posiciones_ocupadas) {
    int intentos = 0;
    for (int i = 0; i < CANTIDAD_CUCARACHAS; i++) {
        do {
            juego->obstaculos[(CANTIDAD_CHARCOS - 1) + i].posicion.fil  = rand() % MAX_FILAS;
            juego->obstaculos[(CANTIDAD_CHARCOS - 1) + i].posicion.col  = rand() % MAX_COLUMNAS;
            intentos++;
            if (intentos > (MAX_FILAS * MAX_COLUMNAS)) return -1;
        } while (es_posicion_ocupada(juego->obstaculos[(CANTIDAD_CHARCOS - 1) + i].posicion, posiciones_ocupadas, *cantidad_posiciones_ocupadas));

        posiciones_ocupadas[*cantidad_posiciones_ocupadas] = juego->obstaculos[(CANTIDAD_CHARCOS - 1) + i].posicion;
        *cantidad_posiciones_ocupadas++;
        printf(" %c", CUCARACHA);
    }
}

// PRE: 
// POST: Cambia el estado de cada herramienta si es que se interactura con la misma.
void interaccion_herramientas(juego_t *juego, coordenada_t posiciones_ocupadas[], int* cantidad_posiciones_ocupadas) {
    for (int i = 0; i < MAX_HERRAMIENTAS; i++) {
        if (juego->mozo.posicion.fil == juego->herramientas[i].posicion.fil && juego->mozo.posicion.col == juego->herramientas[i].posicion.col) {
            if (juego->herramientas[i].tipo == MONEDA) {
                juego->dinero++;

                for (int j = i; j < *cantidad_posiciones_ocupadas - 1; j++) {
                    posiciones_ocupadas[j] = posiciones_ocupadas[j + 1];
                }
                (*cantidad_posiciones_ocupadas)--;
            } else if (juego->herramientas[i].tipo == PATINES) {
                juego->mozo.patines_puestos = true;
            } else if (juego->herramientas[i].tipo == MOPA) {
                //si se preciona la O que "juego->mozo.tiene_mopa = true;"
            }
        }
    }
}

//PRE: 
//POST: Retorna true si el mozo interactuó con la mopa, ya sea para agarrarla o soltarla.
//      Retorna false si el mozo no estaba en la misma posición que la mopa.
bool manejar_mopa(juego_t *juego, coordenada_t posiciones_ocupadas[], int *cantidad_posiciones_ocupadas) {
    if (juego->mozo.posicion.fil == juego->herramientas[0].posicion.fil && juego->mozo.posicion.col == juego->herramientas[0].posicion.col) {
        if (juego->mozo.tiene_mopa == false) {
            juego->mozo.tiene_mopa = true;
        } else {
            coordenada_t posicion_mopa = juego->mozo.posicion;
            if (es_posicion_ocupada(posicion_mopa, posiciones_ocupadas, *cantidad_posiciones_ocupadas) == false) {
                juego->mozo.tiene_mopa = false;
                posiciones_ocupadas[*cantidad_posiciones_ocupadas] = posicion_mopa;
                *cantidad_posiciones_ocupadas++;
            }
        }
        return true;
    }
    return false;
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
    inicializar_linguini(juego, posiciones_ocupadas, &cantidad_posiciones_ocupadas);
    inicializar_mopa(juego, posiciones_ocupadas, &cantidad_posiciones_ocupadas);
    inicializar_monedas(juego, posiciones_ocupadas, &cantidad_posiciones_ocupadas);
    inicializar_patines(juego, posiciones_ocupadas, &cantidad_posiciones_ocupadas);
    inicializar_charcos(juego, posiciones_ocupadas, &cantidad_posiciones_ocupadas);
    inicializar_cucarachas(juego, posiciones_ocupadas, &cantidad_posiciones_ocupadas);
    inicializar_terreno(*juego);
}

// PRE: El juego debe estar inicializado previamente con `inicializar_juego` y la acción debe ser válida.
// POST: Realizará la acción recibida por parámetro.
void realizar_jugada(juego_t *juego, char accion) {
    while (accion != ARRIBA && accion != ABAJO && accion != DERECHA && accion != IZQUIERDA && accion != MOPA){
        printf("Ingrese un movimiento valido (W/S/A/D) ó interactue con la mopa (O):\n");
        scanf(" %c", &accion);
    }

    switch (accion) {
        case ARRIBA:
            if (juego->mozo.posicion.fil > 0) {
                juego->mozo.posicion.fil--;
                juego->movimientos++;
            }
        break;
        case ABAJO:
            if (juego->mozo.posicion.fil < MAX_FILAS - 1) {
                juego->mozo.posicion.fil++;
                juego->movimientos++;
            }
        break;
        case DERECHA:
            if (juego->mozo.posicion.col < MAX_COLUMNAS - 1) {
                juego->mozo.posicion.col++;
                juego->movimientos++;
            }
        break;
        case IZQUIERDA:
            if (juego->mozo.posicion.col > 0) {
                juego->mozo.posicion.col--;
                juego->movimientos++;
            }
        break;
        case MOPA:
            manejar_mopa(juego, posiciones_ocupadas, &cantidad_posiciones_ocupadas);
        break;
    }
}

// PRE: El juego debe estar inicializado previamente con `inicializar_juego`.
// POST: Imprime el juego por pantalla.
void mostrar_juego(juego_t juego) {
    while (juego.movimientos < MAX_MOVIMIENTOS) {
        system("clear");
        inicializar_terreno(juego);
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
