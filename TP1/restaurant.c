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

const int CANTIDAD_LUGARES_MESA_GRUPAL = 4;
const int CANTIDAD_CHARCOS = 5;
const int CANTIDAD_MONEDAS = 8;
const int CANTIDAD_PATINES = 5;
const int CANTIDAD_CUCARACHAS = 0;
const int OBJETIVO_DINERO = 150000;
const int MAX_MOVIMIENTOS = 200;

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
char buscar_herramienta(juego_t juego, int fila, int columna){
    for (int i = 0; i < juego.cantidad_herramientas; i++) {
        if (juego.herramientas[i].posicion.fil == fila && juego.herramientas[i].posicion.col == columna) {
            switch (juego.herramientas[i].tipo) {
                case MONEDA:
                    return MONEDA;
                case PATINES:
                    return PATINES;
                case MOPA:
                    return MOPA;
            }
        }
    }
    return VACIO;
}

// PRE: 
// POST: 
char buscar_obstaculo(juego_t juego, int fila, int columna){
    for (int i = 0; i < juego.cantidad_obstaculos; i++) {
        if (juego.obstaculos[i].posicion.fil == fila && juego.obstaculos[i].posicion.col == columna) {
            switch (juego.obstaculos[i].tipo) {
                case CHARCO:
                    return CHARCO;
                case CUCARACHA:
                    return CUCARACHA;
            }
        }
    }
    return VACIO;
}

// PRE: 
// POST: 
char obtener_contenido_posicion(juego_t juego, int fila, int columna){
    for (int i = 0; i < (MAX_MESAS_INDIVIDUALES + MAX_MESAS_GRUPALES); i++) {
        for (int j = 0; j < juego.mesas[i].cantidad_lugares; j++){
            if (juego.mesas[i].posicion[j].fil == fila && juego.mesas[i].posicion[j].col == columna) {
                return MESA;
            }
        }
    }

    if (juego.mozo.posicion.fil == fila && juego.mozo.posicion.col == columna) {
        return LINGUINI;
    }

    if (juego.cocina.posicion.fil == fila && juego.cocina.posicion.col == columna) {
        return COCINA;
    }
    
    char herramienta = buscar_herramienta(juego, fila, columna);
    if (herramienta != VACIO) {
        return herramienta;
    }

    char obstaculo = buscar_obstaculo(juego, fila, columna);
    if (obstaculo != VACIO) {
        return obstaculo;
    }

    return VACIO;
}

// PRE: 
// POST: 
void inicializar_terreno(juego_t juego) {
    for (int i = 0; i < MAX_FILAS; i++) {
        for (int j = 0; j < MAX_COLUMNAS; j++) {
            char contenido_posicion = VACIO;
            contenido_posicion = obtener_contenido_posicion(juego, i, j);
            printf("| %c  ", contenido_posicion);
        }
        printf("|\n");
    }
}

/*
// PRE: 
// POST: 
void pasillos_mesa_individual(coordenada_t mesa, coordenada_t posiciones_ocupadas_pasillos[], int* cantidad_posiciones_ocupadas_pasillos){
    coordenada_t pasillo;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (i != 0 || j != 0) {
                pasillo.fil = mesa.fil + i;
                pasillo.col = mesa.col + j;
            
                if (!es_posicion_ocupada(pasillo, posiciones_ocupadas_pasillos, *cantidad_posiciones_ocupadas_pasillos)) {
                    posiciones_ocupadas_pasillos[*cantidad_posiciones_ocupadas_pasillos] = pasillo;
                    (*cantidad_posiciones_ocupadas_pasillos)++;
                }
            }
        }
    }
}

// PRE: 
// POST: Inicializa todas las mesas individuales en una posicion aleatoria, si la posicion ya esta ocupada le asigna 
//       nuevamente otra aleatoria.
void inicializar_mesas_individuales(juego_t *juego, coordenada_t posiciones_ocupadas[], int* cantidad_posiciones_ocupadas, coordenada_t posiciones_ocupadas_pasillos[], int* cantidad_posiciones_ocupadas_pasillos) {
    juego->cantidad_mesas = 0;
    for (int i = 0; i < MAX_MESAS_INDIVIDUALES; i++) {
        juego->mesas[i].cantidad_lugares = 1;
        
        int intentos = 0;
        bool posicion_valida = true;
        do {
            juego->mesas[i].posicion[0].fil = rand() % MAX_FILAS;
            juego->mesas[i].posicion[0].col = rand() % MAX_COLUMNAS;

            if (es_posicion_ocupada(juego->mesas[i].posicion[0], posiciones_ocupadas, *cantidad_posiciones_ocupadas)) {
                posicion_valida = false;
            }

            *cantidad_posiciones_ocupadas_pasillos = 0;
            pasillos_mesa_individual(juego->mesas[i].posicion[0], posiciones_ocupadas_pasillos, cantidad_posiciones_ocupadas_pasillos);

            for (int j = 0; j < *cantidad_posiciones_ocupadas_pasillos; j++) {
                if (es_posicion_ocupada(posiciones_ocupadas_pasillos[j], posiciones_ocupadas, *cantidad_posiciones_ocupadas)) {
                    posicion_valida = false;
                }
            }

            intentos++;
            if (intentos > (MAX_FILAS * MAX_COLUMNAS)) return;
        } while (!posicion_valida);

        posiciones_ocupadas[*cantidad_posiciones_ocupadas] = juego->mesas[i].posicion[0];
        (*cantidad_posiciones_ocupadas)++;

        juego->cantidad_mesas++;
    }
}
*/

void pasillos_mesa_individual(coordenada_t mesa, coordenada_t posiciones_ocupadas_pasillos[], int* cantidad_posiciones_ocupadas_pasillos) {
    *cantidad_posiciones_ocupadas_pasillos = 0; // Resetear el contador

    // Definir posiciones de pasillo: todas las posiciones alrededor de la mesa
    coordenada_t posibles_pasillos[8] = {
        {mesa.fil - 1, mesa.col - 1}, // Arriba Izquierda
        {mesa.fil - 1, mesa.col},     // Arriba
        {mesa.fil - 1, mesa.col + 1}, // Arriba Derecha
        {mesa.fil, mesa.col - 1},     // Izquierda
        {mesa.fil, mesa.col + 1},     // Derecha
        {mesa.fil + 1, mesa.col - 1}, // Abajo Izquierda
        {mesa.fil + 1, mesa.col},     // Abajo
        {mesa.fil + 1, mesa.col + 1}  // Abajo Derecha
    };

    // Verificar si esas posiciones están ocupadas y agregarlas al vector de pasillos
    for (int i = 0; i < 8; i++) {
        if (!es_posicion_ocupada(posibles_pasillos[i], posiciones_ocupadas_pasillos, *cantidad_posiciones_ocupadas_pasillos)) {
            posiciones_ocupadas_pasillos[*cantidad_posiciones_ocupadas_pasillos] = posibles_pasillos[i];
            (*cantidad_posiciones_ocupadas_pasillos)++;
        }
    }
}

// PRE: 
// POST: Inicializa todas las mesas individuales en una posición aleatoria, si la posición ya está ocupada le asigna nuevamente otra aleatoria.
void inicializar_mesas_individuales(juego_t *juego, coordenada_t posiciones_ocupadas[], int* cantidad_posiciones_ocupadas, coordenada_t posiciones_ocupadas_pasillos[], int* cantidad_posiciones_ocupadas_pasillos) {
    juego->cantidad_mesas = 0;
    
    for (int i = 0; i < MAX_MESAS_INDIVIDUALES; i++) {
        juego->mesas[i].cantidad_lugares = 1;
        int intentos = 0;
        bool posicion_valida = false;

        do {
            juego->mesas[i].posicion[0].fil = rand() % MAX_FILAS;
            juego->mesas[i].posicion[0].col = rand() % MAX_COLUMNAS;

            // Comprobar si la posición de la mesa está ocupada
            if (!es_posicion_ocupada(juego->mesas[i].posicion[0], posiciones_ocupadas, *cantidad_posiciones_ocupadas)) {
                pasillos_mesa_individual(juego->mesas[i].posicion[0], posiciones_ocupadas_pasillos, cantidad_posiciones_ocupadas_pasillos);
                
                // Comprobar si todas las posiciones de pasillo están libres
                posicion_valida = true;
                for (int j = 0; j < *cantidad_posiciones_ocupadas_pasillos; j++) {
                    if (es_posicion_ocupada(posiciones_ocupadas_pasillos[j], posiciones_ocupadas, *cantidad_posiciones_ocupadas)) {
                        posicion_valida = false;
                        break;
                    }
                }
            }

            intentos++;
            if (intentos > (MAX_FILAS * MAX_COLUMNAS)) return;
        } while (!posicion_valida);

        // Si la posición es válida, ocuparla
        posiciones_ocupadas[*cantidad_posiciones_ocupadas] = juego->mesas[i].posicion[0];
        (*cantidad_posiciones_ocupadas)++;

        // Ocupar también las posiciones de pasillo
        for (int j = 0; j < *cantidad_posiciones_ocupadas_pasillos; j++) {
            posiciones_ocupadas[*cantidad_posiciones_ocupadas] = posiciones_ocupadas_pasillos[j];
            (*cantidad_posiciones_ocupadas)++;
        }

        juego->cantidad_mesas++;
    }
}











// PRE: 
// POST: 
void posiciones_restantes_mesa_grupal(coordenada_t posicion_guia, coordenada_t posiciones[]){
    posiciones[0] = posicion_guia;

    posiciones[1].fil = posicion_guia.fil; // Derecha
    posiciones[1].col = posicion_guia.col + 1;

    posiciones[2].fil = posicion_guia.fil + 1; // Abajo
    posiciones[2].col = posicion_guia.col;

    posiciones[3].fil = posicion_guia.fil + 1; // Abajo Derecha
    posiciones[3].col = posicion_guia.col + 1;
}

// PRE: 
// POST: 
bool es_posible_asignar_posiciones_restantes(juego_t *juego, coordenada_t posicion_guia, coordenada_t posiciones_ocupadas[], int* cantidad_posiciones_ocupadas) {
    coordenada_t posiciones[CANTIDAD_LUGARES_MESA_GRUPAL];
    posiciones_restantes_mesa_grupal(posicion_guia, posiciones);

    for (int i = 0; i < CANTIDAD_LUGARES_MESA_GRUPAL; i++) {
        if (es_posicion_ocupada(posiciones[i], posiciones_ocupadas, *cantidad_posiciones_ocupadas)) {
            return false;
        }
    }

    return true;
}

// PRE: 
// POST: 
void asignar_posiciones_grupales(juego_t *juego, coordenada_t posicion_guia, coordenada_t posiciones_ocupadas[], int* cantidad_posiciones_ocupadas){
    coordenada_t posiciones[CANTIDAD_LUGARES_MESA_GRUPAL];
    posiciones_restantes_mesa_grupal(posicion_guia, posiciones);

    juego->mesas[juego->cantidad_mesas].cantidad_lugares = CANTIDAD_LUGARES_MESA_GRUPAL; //REVISAR

    for (int j = 0; j < CANTIDAD_LUGARES_MESA_GRUPAL; j++) {
        juego->mesas[juego->cantidad_mesas].posicion[j] = posiciones[j]; //REVISAR
        posiciones_ocupadas[*cantidad_posiciones_ocupadas] = posiciones[j];
        (*cantidad_posiciones_ocupadas)++;
    }
}

/*
// PRE: 
// POST: 
void pasillos_mesa_grupal(coordenada_t mesa, coordenada_t posiciones_ocupadas_pasillos[], int* cantidad_posiciones_ocupadas_pasillos) {
    *cantidad_posiciones_ocupadas_pasillos = 0;

    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (i != 0 || j != 0) { 
                coordenada_t pasillo;
                pasillo.fil = mesa.fil + i;
                pasillo.col = mesa.col + j;

                if (!es_posicion_ocupada(pasillo, posiciones_ocupadas_pasillos, *cantidad_posiciones_ocupadas_pasillos)) {
                    posiciones_ocupadas_pasillos[*cantidad_posiciones_ocupadas_pasillos] = pasillo;
                    (*cantidad_posiciones_ocupadas_pasillos)++;
                }
            }
        }
    }

    coordenada_t posiciones_restantes[CANTIDAD_LUGARES_MESA_GRUPAL];
    posiciones_restantes_mesa_grupal(mesa, posiciones_restantes);

    for (int i = 0; i < *cantidad_posiciones_ocupadas_pasillos; i++) {
        bool es_restante = false;
        for (int j = 0; j < CANTIDAD_LUGARES_MESA_GRUPAL; j++) {
            if (posiciones_ocupadas_pasillos[i].fil == posiciones_restantes[j].fil && posiciones_ocupadas_pasillos[i].col == posiciones_restantes[j].col) {
                es_restante = true;
            }
        }
        if (es_restante) {
            for (int k = i; k < *cantidad_posiciones_ocupadas_pasillos - 1; k++) {
                posiciones_ocupadas_pasillos[k] = posiciones_ocupadas_pasillos[k + 1];
            }
            (*cantidad_posiciones_ocupadas_pasillos)--;
        } else i++;
    }
}

// PRE: 
// POST: Inicializa todas las mesas grupales en una posicion aleatoria, si la posicion ya esta ocupada le asigna 
//       nuevamente otra aleatoria.
void inicializar_mesas_grupales(juego_t *juego, coordenada_t posiciones_ocupadas[], int* cantidad_posiciones_ocupadas, coordenada_t posiciones_ocupadas_pasillos[], int* cantidad_posiciones_ocupadas_pasillos) {
    for (int i = 0; i < MAX_MESAS_GRUPALES; i++) {
        coordenada_t posicion_guia;
        bool posicion_valida = false;
        int intentos = 0;

        do {
            posicion_guia.fil = rand() % (MAX_FILAS - 1);
            posicion_guia.col = rand() % (MAX_COLUMNAS - 1);

            if (!es_posicion_ocupada(posicion_guia, posiciones_ocupadas, *cantidad_posiciones_ocupadas)) {
                *cantidad_posiciones_ocupadas_pasillos = 0;
                pasillos_mesa_grupal(posicion_guia, posiciones_ocupadas_pasillos, cantidad_posiciones_ocupadas_pasillos);

                bool pasillos_validos = true;
                for (int j = 0; j < *cantidad_posiciones_ocupadas_pasillos; j++) {
                    if (es_posicion_ocupada(posiciones_ocupadas_pasillos[j], posiciones_ocupadas, *cantidad_posiciones_ocupadas)) {
                        pasillos_validos = false;
                        break;
                    }
                }

                if (pasillos_validos) {
                    posicion_valida = true;
                }
            }

            intentos++;
            if (intentos > ((MAX_FILAS * MAX_COLUMNAS) - (MAX_FILAS + MAX_COLUMNAS))) return;
        } while (!posicion_valida);

        asignar_posiciones_grupales(juego, posicion_guia, posiciones_ocupadas, cantidad_posiciones_ocupadas);

        juego->cantidad_mesas++;
    }
}
*/

void pasillos_mesa_grupal(coordenada_t mesa, coordenada_t posiciones_ocupadas_pasillos[], int* cantidad_posiciones_ocupadas_pasillos) {
    *cantidad_posiciones_ocupadas_pasillos = 0; // Resetear el contador

    // Definir posiciones de pasillo: todas las posiciones alrededor de la mesa grupal
    coordenada_t posibles_pasillos[8] = {
        {mesa.fil - 1, mesa.col - 1}, // Arriba Izquierda
        {mesa.fil - 1, mesa.col},     // Arriba
        {mesa.fil - 1, mesa.col + 1}, // Arriba Derecha
        {mesa.fil, mesa.col - 1},     // Izquierda
        {mesa.fil, mesa.col + 1},     // Derecha
        {mesa.fil + 1, mesa.col - 1}, // Abajo Izquierda
        {mesa.fil + 1, mesa.col},     // Abajo
        {mesa.fil + 1, mesa.col + 1}  // Abajo Derecha
    };

    // Verificar si esas posiciones están ocupadas y agregarlas al vector de pasillos
    for (int i = 0; i < 8; i++) {
        if (!es_posicion_ocupada(posibles_pasillos[i], posiciones_ocupadas_pasillos, *cantidad_posiciones_ocupadas_pasillos)) {
            posiciones_ocupadas_pasillos[*cantidad_posiciones_ocupadas_pasillos] = posibles_pasillos[i];
            (*cantidad_posiciones_ocupadas_pasillos)++;
        }
    }
}

// PRE: 
// POST: Inicializa todas las mesas grupales en una posición aleatoria, si la posición ya está ocupada le asigna nuevamente otra aleatoria.
void inicializar_mesas_grupales(juego_t *juego, coordenada_t posiciones_ocupadas[], int* cantidad_posiciones_ocupadas, coordenada_t posiciones_ocupadas_pasillos[], int* cantidad_posiciones_ocupadas_pasillos) {
    for (int i = 0; i < MAX_MESAS_GRUPALES; i++) {
        coordenada_t posicion_guia;
        bool posicion_valida = false;
        int intentos = 0;

        do {
            posicion_guia.fil = rand() % (MAX_FILAS - 1);
            posicion_guia.col = rand() % (MAX_COLUMNAS - 1);

            // Comprobar si la posición de la mesa está ocupada
            if (!es_posicion_ocupada(posicion_guia, posiciones_ocupadas, *cantidad_posiciones_ocupadas)) {
                pasillos_mesa_grupal(posicion_guia, posiciones_ocupadas_pasillos, cantidad_posiciones_ocupadas_pasillos);

                // Comprobar si todas las posiciones de pasillo están libres
                posicion_valida = true;
                for (int j = 0; j < *cantidad_posiciones_ocupadas_pasillos; j++) {
                    if (es_posicion_ocupada(posiciones_ocupadas_pasillos[j], posiciones_ocupadas, *cantidad_posiciones_ocupadas)) {
                        posicion_valida = false;
                        break;
                    }
                }
            }

            intentos++;
            if (intentos > ((MAX_FILAS * MAX_COLUMNAS) - (MAX_FILAS + MAX_COLUMNAS))) return;
        } while (!posicion_valida);

        asignar_posiciones_grupales(juego, posicion_guia, posiciones_ocupadas, cantidad_posiciones_ocupadas);

        // Ocupar también las posiciones de pasillo
        for (int j = 0; j < *cantidad_posiciones_ocupadas_pasillos; j++) {
            posiciones_ocupadas[*cantidad_posiciones_ocupadas] = posiciones_ocupadas_pasillos[j];
            (*cantidad_posiciones_ocupadas)++;
        }

        juego->cantidad_mesas++;
    }
}











// PRE: 
// POST: Inicializa al personaje en una posicion aleatoria, si la posicion ya esta ocupada le asigna
//       nuevamente otra aleatoria.
void inicializar_linguini(juego_t *juego, coordenada_t posiciones_ocupadas[], int* cantidad_posiciones_ocupadas) {
    juego->mozo.tiene_mopa = false;

    int intentos = 0;
    do {
        juego->mozo.posicion.fil = rand() % MAX_FILAS;
        juego->mozo.posicion.col = rand() % MAX_COLUMNAS;
        intentos++;
        if (intentos > (MAX_FILAS * MAX_COLUMNAS)) return;
    } while (es_posicion_ocupada(juego->mozo.posicion, posiciones_ocupadas, *cantidad_posiciones_ocupadas));

    posiciones_ocupadas[*cantidad_posiciones_ocupadas] = juego->mozo.posicion;
    (*cantidad_posiciones_ocupadas)++;
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
        if (intentos > (MAX_FILAS * MAX_COLUMNAS)) return;
    } while (es_posicion_ocupada(juego->cocina.posicion, posiciones_ocupadas, *cantidad_posiciones_ocupadas));

    posiciones_ocupadas[*cantidad_posiciones_ocupadas] = juego->cocina.posicion;
    (*cantidad_posiciones_ocupadas)++;
}

// PRE: 
// POST: 
void inicializar_herramienta(juego_t *juego, char tipo_herramienta, coordenada_t posiciones_ocupadas[], int *cantidad_posiciones_ocupadas) {
    coordenada_t posicion;
    int intentos = 0;

    do {
        posicion.fil = rand() % MAX_FILAS;
        posicion.col = rand() % MAX_COLUMNAS;
        intentos++;
        if (intentos > (MAX_FILAS * MAX_COLUMNAS)) return; 
    } while (es_posicion_ocupada(posicion, posiciones_ocupadas, *cantidad_posiciones_ocupadas));

    juego->herramientas[juego->cantidad_herramientas].tipo = tipo_herramienta;
    juego->herramientas[juego->cantidad_herramientas].posicion = posicion;
    juego->cantidad_herramientas++;

    posiciones_ocupadas[*cantidad_posiciones_ocupadas] = posicion;
    (*cantidad_posiciones_ocupadas)++;
}

// PRE: 
// POST: 
void inicializar_mopa(juego_t *juego, coordenada_t posiciones_ocupadas[], int *cantidad_posiciones_ocupadas) {
    inicializar_herramienta(juego, MOPA, posiciones_ocupadas, cantidad_posiciones_ocupadas);
}

// PRE: 
// POST: 
void inicializar_monedas(juego_t *juego, coordenada_t posiciones_ocupadas[], int *cantidad_posiciones_ocupadas) {
    for (int i = 0; i < CANTIDAD_MONEDAS; i++) {
        inicializar_herramienta(juego, MONEDA, posiciones_ocupadas, cantidad_posiciones_ocupadas);
    }
}

// PRE: 
// POST: 
void inicializar_patines(juego_t *juego, coordenada_t posiciones_ocupadas[], int *cantidad_posiciones_ocupadas) {
    for (int i = 0; i < CANTIDAD_PATINES; i++) {
        inicializar_herramienta(juego, PATINES, posiciones_ocupadas, cantidad_posiciones_ocupadas);
    }
}

// PRE: 
// POST: 
void inicializar_obstaculo(juego_t *juego, char tipo_obstaculo, coordenada_t posiciones_ocupadas[], int *cantidad_posiciones_ocupadas) {
    coordenada_t posicion;
    int intentos = 0;

    do {
        posicion.fil = rand() % MAX_FILAS;
        posicion.col = rand() % MAX_COLUMNAS;
        intentos++;
        if (intentos > (MAX_FILAS * MAX_COLUMNAS)) return; 
    } while (es_posicion_ocupada(posicion, posiciones_ocupadas, *cantidad_posiciones_ocupadas));

    juego->obstaculos[juego->cantidad_obstaculos].tipo = tipo_obstaculo;
    juego->obstaculos[juego->cantidad_obstaculos].posicion = posicion;
    juego->cantidad_obstaculos++;

    posiciones_ocupadas[*cantidad_posiciones_ocupadas] = posicion;
    (*cantidad_posiciones_ocupadas)++;
}

// PRE: 
// POST: 
void inicializar_charcos(juego_t *juego, coordenada_t posiciones_ocupadas[], int *cantidad_posiciones_ocupadas) {
    for (int i = 0; i < CANTIDAD_CHARCOS; i++) {
        inicializar_obstaculo(juego, CHARCO, posiciones_ocupadas, cantidad_posiciones_ocupadas);
    }
}

// PRE: 
// POST: 
void inicializar_cucarachas(juego_t *juego, coordenada_t posiciones_ocupadas[], int *cantidad_posiciones_ocupadas) {
    for (int i = 0; i < CANTIDAD_CUCARACHAS; i++) {
        inicializar_obstaculo(juego, CUCARACHA, posiciones_ocupadas, cantidad_posiciones_ocupadas);
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
bool es_posible_manejar_mopa(juego_t *juego, coordenada_t posiciones_ocupadas[], int *cantidad_posiciones_ocupadas) {
    if (juego->mozo.posicion.fil == juego->herramientas[0].posicion.fil && juego->mozo.posicion.col == juego->herramientas[0].posicion.col) {
        coordenada_t posicion_mopa = juego->mozo.posicion;
        if (juego->mozo.tiene_mopa == false) {
            juego->mozo.tiene_mopa = true;
            for (int i = 0; i < *cantidad_posiciones_ocupadas; i++) {
                if (posiciones_ocupadas[i].fil == posicion_mopa.fil && posiciones_ocupadas[i].col == posicion_mopa.col) {
                    for (int j = i; j < *cantidad_posiciones_ocupadas - 1; j++) {
                        posiciones_ocupadas[j] = posiciones_ocupadas[j + 1];
                    }

                    (*cantidad_posiciones_ocupadas)--;
                }
            }
        } else if (!es_posicion_ocupada(posicion_mopa, posiciones_ocupadas, *cantidad_posiciones_ocupadas)) {
            juego->mozo.tiene_mopa = false;
            posiciones_ocupadas[*cantidad_posiciones_ocupadas] = posicion_mopa;
            (*cantidad_posiciones_ocupadas)++;
        }
        return true;
    }
    return false;
}

// PRE: 
// POST: 
bool hay_mesa(juego_t *juego, int fila, int col){
    for (int i = 0; i < juego->cantidad_mesas; i++) {
        for (int j = 0; j < juego->mesas[i].cantidad_lugares; j++) {
            if (fila == juego->mesas[i].posicion[j].fil && col == juego->mesas[i].posicion[j].col) {
                return true;
            }
        }
    }
    return false;
}

// PRE: 
// POST: 
void realizar_movimiento(juego_t *juego, char accion){
    int nueva_fil = juego->mozo.posicion.fil;
    int nueva_col = juego->mozo.posicion.col;

    switch (accion) {
        case ARRIBA:
            if (nueva_fil > 0) nueva_fil--;
        break;
        case ABAJO:
            if (nueva_fil < MAX_FILAS - 1) nueva_fil++;
        break;
        case DERECHA:
            if (nueva_col < MAX_COLUMNAS - 1) nueva_col++;
        break;
        case IZQUIERDA:
            if (nueva_col > 0) nueva_col--;
        break;
        //case MOPA:
            //es_posible_manejar_mopa(juego, posiciones_ocupadas, cantidad_posiciones_ocupadas);
        //break;
    }

    if ((nueva_fil != juego->mozo.posicion.fil || nueva_col != juego->mozo.posicion.col) && !hay_mesa(juego, nueva_fil, nueva_col)) {
        juego->mozo.posicion.fil = nueva_fil;
        juego->mozo.posicion.col = nueva_col;
        juego->movimientos++;
    }
}

// PRE: -
// POST: Inicializará el juego, cargando toda la información inicial de Linguini, las mesas, las herramientas y los obstáculos.
void inicializar_juego(juego_t *juego) {
    coordenada_t posiciones_ocupadas[(MAX_FILAS * MAX_COLUMNAS) / 2];
    int cantidad_posiciones_ocupadas = 0;
    coordenada_t posiciones_ocupadas_pasillos[(MAX_MESAS_INDIVIDUALES * 8) + (MAX_MESAS_GRUPALES * 12)];
    int cantidad_posiciones_ocupadas_pasillos = 0;
    
    inicializar_mesas_individuales(juego, posiciones_ocupadas, &cantidad_posiciones_ocupadas, posiciones_ocupadas_pasillos, &cantidad_posiciones_ocupadas_pasillos);
    inicializar_mesas_grupales(juego, posiciones_ocupadas, &cantidad_posiciones_ocupadas, posiciones_ocupadas_pasillos, &cantidad_posiciones_ocupadas_pasillos);
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

    realizar_movimiento(juego, accion);
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

// PRE: El juego debe estar inicializado previamente con `inicializar_juego`.
// POST: Imprime el juego por pantalla.
void mostrar_juego(juego_t juego) {
    char accion = ' ';
    while (estado_juego(juego) == 0){
        system("clear");
        inicializar_terreno(juego);

        if (juego.mozo.tiene_mopa){
            printf("Tenés la mopa.\n");
        } else if (!juego.mozo.tiene_mopa){
            for (int i = 0; i < juego.cantidad_herramientas; i++){
                if (juego.herramientas[i].tipo == MOPA){
                    if (juego.mozo.posicion.fil == juego.herramientas[i].posicion.fil && juego.mozo.posicion.col == juego.herramientas[i].posicion.col){
                        printf("Estás sobre la mopa. ¡Podés agarrarla!.\n");
                    } else printf("No tenés la mopa.\n");
                } 
            }
        }

        printf("Realizo %i/%i movimientos.\n", juego.movimientos, MAX_MOVIMIENTOS);
        printf("Objetivo de monedas %i/%i.\n", juego.dinero, OBJETIVO_DINERO);
        printf("Ingresa un movimiento (W/S/A/D) o interactúa con la mopa (O):\n");
        scanf(" %c", &accion);
        realizar_jugada(&juego, accion);
        
        int estado = estado_juego(juego);
        if (estado == 1){
            printf("¡Ganaste!");
        } else if (estado == -1){
            printf("Perdiste");
        }
    } 
}