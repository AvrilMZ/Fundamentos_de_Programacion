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
#define POSICIONES_PASILLO 8
#define MAX_MESAS_GRUPALES 4
#define CANTIDAD_LUGARES_MESA_GRUPAL 4

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

// PRE: -
// POST: Devuelve una posicion aleatoria.
coordenada_t posicion_aleatoria() {
    coordenada_t posicion;
    posicion.fil = rand() % MAX_FILAS;
    posicion.col = rand() % MAX_COLUMNAS;
    return posicion;
}

// PRE: -
// POST: Devuelve una posicion aleatoria evitando la ultima fila y columna.
coordenada_t posicion_aleatoria_mesa_grupal() {
    coordenada_t posicion;
    posicion.fil = rand() % (MAX_FILAS - 1);
    posicion.col = rand() % (MAX_COLUMNAS - 1);
    return posicion;
}

// PRE: -
// POST: Devuelve una posicion fuera del rango.
coordenada_t asignar_posicion_vacia() {
    coordenada_t posicion;
    posicion.fil = -(rand() % MAX_FILAS);
    posicion.col = -(rand() % MAX_COLUMNAS);
    return posicion;
}

// PRE: -
// POST: Devuelve true si las posiciones son iguales, de lo contrario devuelve false.
bool son_posiciones_iguales(coordenada_t coordenada, coordenada_t coordenada_a_comparar) {
    if (coordenada.fil == coordenada_a_comparar.fil && coordenada.col == coordenada_a_comparar.col) {
        return true;
    } else return false;
}

// PRE: 'juego' debe estar correctamente inicializado.
// POST: Devuelve true si hay una mesa en la posición especificada, de lo contrario devuelve false.
bool hay_mesa(juego_t juego, coordenada_t posicion) {
    for (int i = 0; i < juego.cantidad_mesas; i++) {
        for (int j = 0; j < juego.mesas[i].cantidad_lugares; j++) {
            if (son_posiciones_iguales(juego.mesas[i].posicion[j], posicion)) {
                return true;
            }
        }
    }
    return false;
}

// PRE: 'juego' debe estar correctamente inicializado.
// POST: Devuelve true si la posicion no fue previamente asignada, de lo contrario devuelve false.
bool es_posicion_vacia(juego_t juego, coordenada_t posicion) {
    if (hay_mesa(juego, posicion)) return false;

    for (int i = 0; i < juego.cantidad_herramientas; i++) {
        if (son_posiciones_iguales(juego.herramientas[i].posicion, posicion)) return false;
    }

    for (int i = 0; i < juego.cantidad_obstaculos; i++) {
        if (son_posiciones_iguales(juego.obstaculos[i].posicion, posicion)) return false;
    }

    if (son_posiciones_iguales(juego.mozo.posicion, posicion)) return false;

    if (son_posiciones_iguales(juego.cocina.posicion, posicion)) return false;

    return true;
}

// PRE: 'juego' debe estar correctamente inicializado.
// POST: Devuelve true si la posicion no fue previamente asignada (excluyendo a Linguini), de lo contrario devuelve false.
bool es_posicion_vacia_excepto_linguini(juego_t juego, coordenada_t posicion) {
    if (hay_mesa(juego, posicion)) return false;

    for (int i = 0; i < juego.cantidad_herramientas; i++) {
        if (son_posiciones_iguales(juego.herramientas[i].posicion, posicion)) return false;
    }

    for (int i = 0; i < juego.cantidad_obstaculos; i++) {
        if (son_posiciones_iguales(juego.obstaculos[i].posicion, posicion)) return false;
    }

    if (son_posiciones_iguales(juego.cocina.posicion, posicion)) return false;

    return true;
}

// PRE: 'juego' debe estar correctamente inicializado e 'indice_mesa' debe estar dentro del rango de mesas posibles.
// POST: Se asignan las posiciones de los pasillos alrededor de la mesa, chequeando que cada nueva posición no esté ocupada.
bool pasillos_libres(juego_t juego, int indice_mesa) {
    coordenada_t pasillo[POSICIONES_PASILLO];
    coordenada_t mesa_guia = juego.mesas[indice_mesa].posicion[0];
    
    pasillo[0].fil = mesa_guia.fil - 1; // Arriba Izquierda
    pasillo[0].col = mesa_guia.col - 1;

    pasillo[1].fil = mesa_guia.fil - 1; // Arriba
    pasillo[1].col = mesa_guia.col;

    pasillo[2].fil = mesa_guia.fil - 1; // Arriba Derecha
    pasillo[2].col = mesa_guia.col + 1;

    pasillo[3].fil = mesa_guia.fil; // Izquierda
    pasillo[3].col = mesa_guia.col - 1;

    pasillo[4].fil = mesa_guia.fil; // Derecha
    pasillo[4].col = mesa_guia.col + 1;

    pasillo[5].fil = mesa_guia.fil + 1; // Abajo Izquierda
    pasillo[5].col = mesa_guia.col - 1;

    pasillo[6].fil = mesa_guia.fil + 1; // Abajo
    pasillo[6].col = mesa_guia.col;

    pasillo[7].fil = mesa_guia.fil + 1; // Abajo Derecha
    pasillo[7].col = mesa_guia.col + 1;

    for (int i = 0; i < POSICIONES_PASILLO; i++) {
        if (hay_mesa(juego, pasillo[i])) return false;
    }

    return true;
}

// PRE: 'juego' debe estar correctamente inicializado.
// POST: Inicializa todas las mesas individuales en una posición aleatoria, si la posición ya está ocupada le asigna nuevamente otra aleatoria.
void inicializar_mesa_individual(juego_t *juego) {
    for (int i = 0; i < MAX_MESAS_INDIVIDUALES; i++) {
        juego->mesas[i].cantidad_lugares = 1;
        juego->mesas[i].cantidad_comensales = 0;
        juego->mesas[i].paciencia = 0;
        juego->mesas[i].pedido_tomado = false;
        int intentos = 0;

        do {
            juego->mesas[i].posicion[0] = posicion_aleatoria();
            intentos++;
            if (intentos >= (MAX_FILAS * MAX_COLUMNAS)) return;
        } while (!es_posicion_vacia(*juego, juego->mesas[i].posicion[0]) || !pasillos_libres(*juego, i));

        juego->cantidad_mesas++;
    }
}

// PRE: -
// POST: Asigna las coordenadas de las posiciones restantes de una mesa grupal a partir de 'posicion_guia' en un vector.
void posiciones_restantes_mesa_grupal(coordenada_t posicion_guia, coordenada_t posiciones[]) {
    posiciones[0] = posicion_guia;

    posiciones[1].fil = posicion_guia.fil; // Derecha
    posiciones[1].col = posicion_guia.col + 1;

    posiciones[2].fil = posicion_guia.fil + 1; // Abajo
    posiciones[2].col = posicion_guia.col;

    posiciones[3].fil = posicion_guia.fil + 1; // Abajo Derecha
    posiciones[3].col = posicion_guia.col + 1;
}

// PRE: 'juego' debe estar correctamente inicializado e 'indice_mesa' debe estar dentro del rango de mesas posibles.
// POST: Asigna las posiciones de la mesa grupal basándose en 'posicion_guia'.
bool asignar_posiciones_grupales(juego_t *juego, coordenada_t posicion_guia, int indice_mesa) {
    coordenada_t posiciones[CANTIDAD_LUGARES_MESA_GRUPAL];
    posiciones_restantes_mesa_grupal(posicion_guia, posiciones);
    bool posiciones_asignadas = true;

    for (int i = 0; i < CANTIDAD_LUGARES_MESA_GRUPAL; i++) {
        if (!es_posicion_vacia(*juego, posiciones[i])) {
            return posiciones_asignadas = false;
        }
    }

    if (posiciones_asignadas) {
        for (int i = 0; i < CANTIDAD_LUGARES_MESA_GRUPAL; i++) {
            juego->mesas[indice_mesa].posicion[i] = posiciones[i];
        }
    }

    return posiciones_asignadas;
}

// PRE: 'juego' debe estar correctamente inicializado.
// POST: Inicializa todas las mesas grupales en una posición aleatoria, si la posición ya está ocupada le asigna nuevamente otra aleatoria.
void inicializar_mesa_grupal(juego_t *juego) {
    for (int i = MAX_MESAS_INDIVIDUALES; i < MAX_MESAS_GRUPALES + MAX_MESAS_INDIVIDUALES; i++) {
        juego->mesas[i].cantidad_lugares = CANTIDAD_LUGARES_MESA_GRUPAL;
        juego->mesas[i].cantidad_comensales = 0;
        juego->mesas[i].paciencia = 0;
        juego->mesas[i].pedido_tomado = false;
        coordenada_t posicion_guia;
        int intentos = 0;

        do {
            posicion_guia = posicion_aleatoria_mesa_grupal();
            intentos++;
            if (intentos >= ((MAX_FILAS * MAX_COLUMNAS) - (MAX_FILAS + MAX_COLUMNAS))) return;
        } while (!pasillos_libres(*juego, i) || !asignar_posiciones_grupales(juego, posicion_guia, i));

        juego->cantidad_mesas++;
    }
}

// PRE: 'juego' debe estar correctamente inicializado.
// POST: Inicializa al personaje en una posicion aleatoria, si la posicion ya esta ocupada le asigna nuevamente otra aleatoria.
void inicializar_linguini(juego_t *juego) {
    juego->mozo.tiene_mopa = false;

    int intentos = 0;
    do {
        juego->mozo.posicion = posicion_aleatoria();
        intentos++;
        if (intentos > (MAX_FILAS * MAX_COLUMNAS)) return;
    } while (!es_posicion_vacia(*juego, juego->mozo.posicion));
}

// PRE: 'juego' debe estar correctamente inicializado.
// POST: Inicializa a la cocina en una posicion aleatoria, si la posicion ya esta ocupada le asigna nuevamente otra aleatoria.
void inicializar_cocina(juego_t *juego) {
    int intentos = 0;
    do {
        juego->cocina.posicion = posicion_aleatoria();
        intentos++;
        if (intentos > (MAX_FILAS * MAX_COLUMNAS)) return;
    } while (!es_posicion_vacia(*juego, juego->cocina.posicion));
}

// PRE: 'juego' debe estar correctamente inicializado y 'tipo_herramienta' debe ser un char valido para una herramienta.
// POST: Inicializa una herramienta en una posicion aleatoria, si la posicion ya esta ocupada le asigna nuevamente otra aleatoria.
void inicializar_herramienta(juego_t *juego, char tipo_herramienta) {
    coordenada_t posicion;
    int intentos = 0;

    do {
        posicion = posicion_aleatoria();
        intentos++;
        if (intentos > (MAX_FILAS * MAX_COLUMNAS)) return; 
    } while (!es_posicion_vacia(*juego, posicion));

    juego->herramientas[juego->cantidad_herramientas].tipo = tipo_herramienta;
    juego->herramientas[juego->cantidad_herramientas].posicion = posicion;
    juego->cantidad_herramientas++;
}

// PRE: 'juego' debe estar correctamente inicializado.
// POST: Inicializa la mopa en una posicion aleatoria, si la posicion ya esta ocupada le asigna nuevamente otra aleatoria.
void inicializar_mopa(juego_t *juego) {
    inicializar_herramienta(juego, MOPA);
}

// PRE: 'juego' debe estar correctamente inicializado.
// POST: Inicializa las monedas en posiciones aleatorias, si la posicion ya esta ocupada le asigna nuevamente otra aleatoria.
void inicializar_monedas(juego_t *juego) {
    for (int i = 0; i < CANTIDAD_MONEDAS; i++) {
        inicializar_herramienta(juego, MONEDA);
    }
}

// PRE: 'juego' debe estar correctamente inicializado.
// POST: Inicializa los patines en posiciones aleatorias, si la posicion ya esta ocupada le asigna nuevamente otra aleatoria.
void inicializar_patines(juego_t *juego) {
    for (int i = 0; i < CANTIDAD_PATINES; i++) {
        inicializar_herramienta(juego, PATINES);
    }
}

// PRE: 'juego' debe estar correctamente inicializado y 'tipo_obstaculo' debe ser un char valido para una herramienta.
// POST: Inicializa un obstáculo en una posicion aleatoria, si la posicion ya esta ocupada le asigna nuevamente otra aleatoria.
void inicializar_obstaculo(juego_t *juego, char tipo_obstaculo) {
    coordenada_t posicion;
    int intentos = 0;

    do {
        posicion = posicion_aleatoria();
        intentos++;
        if (intentos > (MAX_FILAS * MAX_COLUMNAS)) return; 
    } while (!es_posicion_vacia(*juego, posicion));

    juego->obstaculos[juego->cantidad_obstaculos].tipo = tipo_obstaculo;
    juego->obstaculos[juego->cantidad_obstaculos].posicion = posicion;
    juego->cantidad_obstaculos++;
}

// PRE: 'juego' debe estar correctamente inicializado.
// POST: Inicializa los charcos en posiciones aleatorias, si la posicion ya esta ocupada le asigna nuevamente otra aleatoria.
void inicializar_charcos(juego_t *juego) {
    for (int i = 0; i < CANTIDAD_CHARCOS; i++) {
        inicializar_obstaculo(juego, CHARCO);
    }
}

// PRE: 'juego' debe estar correctamente inicializado.
// POST: Inicializa las cucarachas en posiciones aleatorias, si la posicion ya esta ocupada le asigna nuevamente otra aleatoria.
void inicializar_cucarachas(juego_t *juego) {
    for (int i = 0; i < CANTIDAD_CUCARACHAS; i++) {
        inicializar_obstaculo(juego, CUCARACHA);
    }
}

// PRE: 'juego' debe estar correctamente inicializado.
// POST: Devuelve el carácter correspondiente a la herramienta encontrada en la posición dada.
char buscar_herramienta(juego_t juego, coordenada_t posicion) {
    for (int i = 0; i < juego.cantidad_herramientas; i++) {
        if (son_posiciones_iguales(juego.herramientas[i].posicion, posicion)) {
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

// PRE: 'juego' debe estar correctamente inicializado.
// POST: Devuelve el carácter correspondiente a el obstáculo encontrado en la posición dada.
char buscar_obstaculo(juego_t juego, coordenada_t posicion) {
    for (int i = 0; i < juego.cantidad_obstaculos; i++) {
        if (son_posiciones_iguales(juego.obstaculos[i].posicion, posicion)) {
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

// PRE: 'juego' debe estar correctamente inicializado.
// POST: Devuelve el carácter correspondiente al contenido en la posición.
char obtener_contenido_posicion(juego_t juego, coordenada_t posicion) {
    if (hay_mesa(juego, posicion)) return MESA;

    if (son_posiciones_iguales(juego.mozo.posicion, posicion)) {
        return LINGUINI;
    }

    if (son_posiciones_iguales(juego.cocina.posicion, posicion)) {
        return COCINA;
    }
    
    char herramienta = buscar_herramienta(juego, posicion);
    if (herramienta != VACIO) {
        return herramienta;
    }

    char obstaculo = buscar_obstaculo(juego, posicion);
    if (obstaculo != VACIO) {
        return obstaculo;
    }

    return VACIO;
}

// PRE: 'juego' debe estar correctamente inicializado.
// POST: Imprime cómo se visualizará el terreno de juego, mostrando el contenido de cada posición.
void inicializar_terreno(juego_t juego) {
    coordenada_t posicion;
    for (int i = 0; i < MAX_FILAS; i++) {
        posicion.fil = i;
        for (int j = 0; j < MAX_COLUMNAS; j++) {
            char contenido_posicion = VACIO;
            posicion.col = j;
            contenido_posicion = obtener_contenido_posicion(juego, posicion);
            printf("| %c  ", contenido_posicion);
        }
        printf("|\n");
    }
}

// PRE: 'juego' debe estar correctamente inicializado.
// POST: Si el mozo se encuentra en la posición de la mopa y no la tiene, la agarra y se elimina la posición. 
//       Si el mozo tiene la mopa y la posición no está ocupada, deja la mopa.
void utilizar_mopa(juego_t *juego) {
    coordenada_t posicion_mopa = juego->herramientas[0].posicion;
    if (son_posiciones_iguales(juego->mozo.posicion, posicion_mopa)) {
        if (!juego->mozo.tiene_mopa) {
            juego->mozo.tiene_mopa = true;
            juego->herramientas[0].posicion = asignar_posicion_vacia();
        }
    } else if (juego->mozo.tiene_mopa) {
        if (es_posicion_vacia_excepto_linguini(*juego, juego->mozo.posicion)) {
            juego->mozo.tiene_mopa = false;
            juego->herramientas[0].posicion = juego->mozo.posicion;
        }
    }
}

// PRE: 'juego' debe estar correctamente inicializado y la acción debe ser válida.
// POST: Actualiza la posición del mozo si en la nueva posición no hay una mesa y posibilita la interaccion con la mopa.
void realizar_movimiento(juego_t *juego, char accion) {
    coordenada_t nueva_posicion = juego->mozo.posicion;

    switch (accion) {
        case ARRIBA:
            if (nueva_posicion.fil > 0) nueva_posicion.fil--;
            break;
        case ABAJO:
            if (nueva_posicion.fil < MAX_FILAS - 1) nueva_posicion.fil++;
            break;
        case DERECHA:
            if (nueva_posicion.col < MAX_COLUMNAS - 1) nueva_posicion.col++;
            break;
        case IZQUIERDA:
            if (nueva_posicion.col > 0) nueva_posicion.col--;
            break;
        case MOPA:
            utilizar_mopa(juego);
            return;
    }

    if (!son_posiciones_iguales(nueva_posicion, juego->mozo.posicion) && !hay_mesa(*juego, nueva_posicion)) {
        juego->mozo.posicion = nueva_posicion;
        juego->movimientos++;
    }
}

// PRE: -
// POST: Inicializará el juego, cargando toda la información inicial de Linguini, las mesas, las herramientas y los obstáculos.
void inicializar_juego(juego_t *juego) {
    juego->cantidad_mesas = 0;
    juego->cantidad_herramientas = 0;
    juego->cantidad_obstaculos = 0;
    juego->movimientos = 0;
    juego->dinero = 0;
    juego->mozo.cantidad_bandeja = 0;
    juego->mozo.cantidad_patines = 0;

    inicializar_mesa_individual(juego);
    inicializar_mesa_grupal(juego);
    inicializar_cocina(juego);
    inicializar_linguini(juego);
    inicializar_mopa(juego);
    inicializar_monedas(juego);
    inicializar_patines(juego);
    inicializar_charcos(juego);
    inicializar_cucarachas(juego);
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