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
#define CANTIDAD_LUGARES_MESA_GRUPAL 4
#define POSICIONES_PASILLO 8

const char LINGUINI = 'L';
const char MESA = 'T';
const char COCINA = 'C';
const char VACIO = ' ';

const int CANTIDAD_LUGARES_MESA_INDIVIDUAL = 1;
const int CANTIDAD_MOPAS = 1;
const int CANTIDAD_CHARCOS = 5;
const int CANTIDAD_MONEDAS = 8;
const int CANTIDAD_PATINES = 5;
const int CANTIDAD_CUCARACHAS = 0;
const int OBJETIVO_DINERO = 150000;
const int MAX_MOVIMIENTOS = 200;

// POST: Devuelve una posición aleatoria.
coordenada_t posicion_aleatoria() {
    coordenada_t posicion;
    posicion.fil = rand() % MAX_FILAS;
    posicion.col = rand() % MAX_COLUMNAS;
    return posicion;
}

// POST: Devuelve una posición fuera del rango.
coordenada_t asignar_posicion_vacia() {
    coordenada_t posicion;
    posicion.fil = -1;
    posicion.col = -1;
    return posicion;
}

// POST: Devuelve true si las posiciones son iguales, de lo contrario devuelve false.
bool son_posiciones_iguales(coordenada_t coordenada, coordenada_t coordenada_a_comparar) {
    return (coordenada.fil == coordenada_a_comparar.fil && coordenada.col == coordenada_a_comparar.col);
}

/* PRE: - 'mesas' no debe estar vacio;
        - 'tope_mesas' debe ser mayor estricto a cero y menor o igual a 'MAX_MESAS';
        - 'posicion' debe estar dentro del rango del terreno de juego.
   POST: Devuelve true si hay una mesa en la posición especificada, de lo contrario devuelve false.*/
bool hay_mesa(mesa_t mesas[MAX_MESAS], int tope_mesas, coordenada_t posicion) {
    for (int i = 0; i < tope_mesas; i++) {
        for (int j = 0; j < mesas[i].cantidad_lugares; j++) {
            if (son_posiciones_iguales(mesas[i].posicion[j], posicion)) return true;
        }
    }
    return false;
}

/* PRE: - Los topes dentro de 'juego' de 'mesas', 'herramientas' y 'obstaculos' deben estar correctamente inicializados;
        - 'posicion' debe estar dentro del rango del terreno de juego.
   POST: Devuelve true si la posicion no fue previamente asignada, de lo contrario devuelve false.*/
bool es_posicion_vacia(juego_t juego, coordenada_t posicion) {
    if (hay_mesa(juego.mesas, juego.cantidad_mesas, posicion)) return false;

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

/* PRE: - Los topes dentro de 'juego' de 'mesas', 'herramientas' y 'obstaculos' deben estar correctamente inicializados;
        - 'posicion' debe estar dentro del rango del terreno de juego.
   POST: Devuelve true si la posicion no fue previamente asignada (excluyendo a Linguini), de lo contrario devuelve false.*/
bool es_posicion_vacia_excepto_linguini(juego_t juego, coordenada_t posicion) {
    if (hay_mesa(juego.mesas, juego.cantidad_mesas, posicion)) return false;

    for (int i = 0; i < juego.cantidad_herramientas; i++) {
        if (son_posiciones_iguales(juego.herramientas[i].posicion, posicion)) return false;
    }

    for (int i = 0; i < juego.cantidad_obstaculos; i++) {
        if (son_posiciones_iguales(juego.obstaculos[i].posicion, posicion)) return false;
    }

    if (son_posiciones_iguales(juego.cocina.posicion, posicion)) return false;

    return true;
}

/* PRE: - 'mesas' no debe estar vacio;
        - 'tope_mesas' debe ser mayor estricto a cero y menor o igual a 'MAX_MESAS';
        - 'mesa_guia' debe estar dentro del rango del terreno de juego.
   POST: Se asignan las posiciones de los pasillos alrededor de la mesa, chequeando que cada nueva posición no esté ocupada.*/
bool pasillos_libres(mesa_t mesas[MAX_MESAS], int tope_mesas, coordenada_t mesa_guia) {
    coordenada_t pasillo[POSICIONES_PASILLO];
    
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
        if (pasillo[i].fil >= 0 && pasillo[i].fil < MAX_FILAS && pasillo[i].col >= 0 && pasillo[i].col < MAX_COLUMNAS) {
            if (hay_mesa(mesas, tope_mesas, pasillo[i])) return false;
        }
    }

    return true;
}

/* PRE: El tope 'cantidad_mesas' de 'mesas' dentro de 'juego' debe estar correctamente inicializado.
   POST: Inicializa todas las mesas individuales en una posición aleatoria, si la posición ya está ocupada le asigna nuevamente otra aleatoria.*/
void inicializar_mesa_individual(juego_t *juego) {
    for (int i = 0; i < MAX_MESAS_INDIVIDUALES; i++) {
        juego->mesas[i].cantidad_lugares = 0;
        juego->mesas[i].cantidad_comensales = 0;
        juego->mesas[i].paciencia = 0;
        juego->mesas[i].pedido_tomado = false;

        int intentos = 0;
        do {
            juego->mesas[i].posicion[0] = posicion_aleatoria();
            intentos++;
            if (intentos >= (MAX_FILAS * MAX_COLUMNAS)) return;
        } while (!es_posicion_vacia(*juego, juego->mesas[i].posicion[0]) || !pasillos_libres(juego->mesas, juego->cantidad_mesas, juego->mesas[i].posicion[0]));

        juego->mesas[i].cantidad_lugares = CANTIDAD_LUGARES_MESA_INDIVIDUAL;
        juego->cantidad_mesas++;
    }
}

/* PRE: - La mesa señalada con 'indice_mesa', en 'mesas' dentro de 'juego', debe estar correctamente inicializada;
        - 'indice_mesa' debe estar dentro del rango de mesas posibles;
        - 'posicion_guia' debe estar dentro del rango del terreno de juego.
   POST: Asigna las posiciones de la mesa grupal basándose en 'posicion_guia', verificando si las posiciones estan desocupadas.*/
bool posible_posiciones_mesa_grupal(juego_t *juego, int indice_mesa, coordenada_t posicion_guia) {
    coordenada_t posiciones[CANTIDAD_LUGARES_MESA_GRUPAL];
    posiciones[0] = posicion_guia;

    posiciones[1].fil = posicion_guia.fil; // Derecha
    posiciones[1].col = posicion_guia.col + 1;

    posiciones[2].fil = posicion_guia.fil + 1; // Abajo
    posiciones[2].col = posicion_guia.col;

    posiciones[3].fil = posicion_guia.fil + 1; // Abajo Derecha
    posiciones[3].col = posicion_guia.col + 1;

    for (int i = 0; i < CANTIDAD_LUGARES_MESA_GRUPAL; i++) {
        if (!es_posicion_vacia(*juego, posiciones[i])) {
            return false;
        }
    }

    for (int i = 0; i < CANTIDAD_LUGARES_MESA_GRUPAL; i++) {
        if (!pasillos_libres(juego->mesas, juego->cantidad_mesas, posiciones[i])) {
            return false;
        }
    }

    for (int i = 0; i < CANTIDAD_LUGARES_MESA_GRUPAL; i++) {
        juego->mesas[indice_mesa].posicion[i] = posiciones[i];
    }

    juego->mesas[indice_mesa].cantidad_lugares = CANTIDAD_LUGARES_MESA_GRUPAL;

    return true;
}

/* PRE: El tope 'cantidad_mesas' de 'mesas' dentro de 'juego' debe estar correctamente inicializado.
   POST: Inicializa todas las mesas grupales en una posición aleatoria, si la posición ya está ocupada le asigna nuevamente otra aleatoria.*/
void inicializar_mesa_grupal(juego_t *juego) {
    for (int i = MAX_MESAS_INDIVIDUALES; i < (MAX_MESAS_GRUPALES + MAX_MESAS_INDIVIDUALES); i++) {
        juego->mesas[i].cantidad_lugares = 0;
        juego->mesas[i].cantidad_comensales = 0;
        juego->mesas[i].paciencia = 0;
        juego->mesas[i].pedido_tomado = false;

        coordenada_t posicion_guia;

        int intentos = 0;
        do {
            posicion_guia = posicion_aleatoria();
            intentos++;
            if (intentos >= ((MAX_FILAS * MAX_COLUMNAS) - (MAX_FILAS + MAX_COLUMNAS))) return;
        } while (posicion_guia.fil == MAX_FILAS - 1 || posicion_guia.col == MAX_COLUMNAS - 1 || !posible_posiciones_mesa_grupal(juego, i, posicion_guia));

        juego->cantidad_mesas++;
    }
}

/* PRE: El tope 'cantidad_mesas' de 'mesas' dentro de 'juego' debe estar correctamente inicializado.
   POST: Inicializa todas las mesas, ya sean individuales o grupales.*/
void inicializar_mesa(juego_t *juego) {
    inicializar_mesa_individual(juego);
    inicializar_mesa_grupal(juego);
}

// POST: Inicializa al personaje en una posición aleatoria, si esta ya está ocupada le asigna nuevamente otra aleatoria.
void inicializar_linguini(juego_t *juego) {
    juego->mozo.cantidad_patines = 0;
    juego->mozo.cantidad_pedidos = 0;
    juego->mozo.cantidad_bandeja = 0;
    juego->mozo.tiene_mopa = false;
    juego->mozo.patines_puestos = false;

    int intentos = 0;
    do {
        juego->mozo.posicion = posicion_aleatoria();
        intentos++;
        if (intentos > (MAX_FILAS * MAX_COLUMNAS)) return;
    } while (!es_posicion_vacia(*juego, juego->mozo.posicion));
}

// POST: Inicializa a la cocina en una posicion aleatoria, si esta ya está ocupada le asigna nuevamente otra aleatoria.
void inicializar_cocina(juego_t *juego) {
    int intentos = 0;
    do {
        juego->cocina.posicion = posicion_aleatoria();
        intentos++;
        if (intentos > (MAX_FILAS * MAX_COLUMNAS)) return;
    } while (!es_posicion_vacia(*juego, juego->cocina.posicion));
}

/* PRE: - El tope 'cantidad_herramientas' de 'herramientas' dentro de 'juego' debe estar correctamente inicializado;
        - 'tipo_herramienta' debe ser un char válido para una herramienta;
        - 'cantidad_herramienta' debe ser mayor estricto a cero y menor o igual a 'MAX_HERRAMIENTAS'.
   POST: Inicializa una herramienta en una posicion aleatoria, si esta ya está ocupada le asigna nuevamente otra aleatoria.*/
void inicializar_herramienta(juego_t *juego, char tipo_herramienta, int cantidad_herramienta) {
    coordenada_t posicion;

    for (int i = 0; i < cantidad_herramienta; i++) {
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
}

/* PRE: - El tope 'cantidad_obstaculos' de 'obstaculos' dentro de 'juego' debe estar correctamente inicializado;
        - 'tipo_obstaculo' debe ser un char válido para un obstáculo;
        - 'cantidad_obstaculo' debe ser mayor estricto a cero y menor o igual a 'MAX_OBSTACULOS'.
   POST: Inicializa un obstáculo en una posición aleatoria, si esta ya está ocupada le asigna nuevamente otra aleatoria.*/
void inicializar_obstaculo(juego_t *juego, char tipo_obstaculo, int cantidad_obstaculo) {
    coordenada_t posicion;    

    for (int i = 0; i < cantidad_obstaculo; i++) {
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
}

/* PRE: - 'herramientas' no debe estar vacio;
        - 'tope_herramientas' debe ser mayor estricto a cero y menor o igual a 'MAX_HERRAMIENTAS';
        - 'posicion' debe estar dentro del rango del terreno de juego.
   POST: Devuelve el carácter correspondiente a la herramienta encontrada en la posición dada.*/
char buscar_herramienta(objeto_t herramientas[MAX_HERRAMIENTAS], int tope_herramientas, coordenada_t posicion) {
    for (int i = 0; i < tope_herramientas; i++) {
        if (son_posiciones_iguales(herramientas[i].posicion, posicion)) {
            switch (herramientas[i].tipo) {
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

/* PRE: - 'obstaculos' no debe estar vacio;
        - 'tope_obstaculos' debe ser mayor estricto a cero y menor o igual a 'MAX_OBSTACULOS';
        - 'posicion' debe estar dentro del rango del terreno de juego.
   POST: Devuelve el carácter correspondiente a el obstáculo encontrado en la posición dada.*/
char buscar_obstaculo(objeto_t obstaculos[MAX_OBSTACULOS], int tope_obstaculos, coordenada_t posicion) {
    for (int i = 0; i < tope_obstaculos; i++) {
        if (son_posiciones_iguales(obstaculos[i].posicion, posicion)) {
            switch (obstaculos[i].tipo) {
                case CHARCO:
                    return CHARCO;
                case CUCARACHA:
                    return CUCARACHA;
            }
        }
    }
    return VACIO;
}

/* PRE: - Los topes dentro de 'juego' de 'mesas', 'herramientas' y 'obstaculos' deben estar correctamente inicializados;
        - 'posicion' debe estar dentro del rango del terreno de juego.
   POST: Devuelve el carácter correspondiente al contenido en la posición.*/
char obtener_contenido_posicion(juego_t juego, coordenada_t posicion) {
    if (hay_mesa(juego.mesas, juego.cantidad_mesas, posicion)) return MESA;

    if (son_posiciones_iguales(juego.mozo.posicion, posicion)) return LINGUINI;

    if (son_posiciones_iguales(juego.cocina.posicion, posicion)) return COCINA;
    
    char herramienta = buscar_herramienta(juego.herramientas, juego.cantidad_herramientas, posicion);
    if (herramienta != VACIO) return herramienta;

    char obstaculo = buscar_obstaculo(juego.obstaculos, juego.cantidad_obstaculos, posicion);
    if (obstaculo != VACIO) return obstaculo;

    return VACIO;
}

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

/* PRE: - La posición de 'mozo' en 'juego' ya debe estar inicializada;
        - La mopa se debe encontrar en la posición cero en 'herramientas' dentro de 'juego';
        - Los campos de 'mozo' en 'juego' deben estar correctamente inicializados.
   POST: - Si el mozo se encuentra en la posición de la mopa y no la tiene, la agarra y se elimina la posición;
         - Si el mozo tiene la mopa y la posición no está ocupada, deja la mopa.*/
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

/* PRE: - La posición de 'mozo' en 'juego' ya debe estar inicializada;
        - El tope 'cantidad_mesas' de 'mesas' dentro de 'juego' debe estar correctamente inicializado.
        - 'acción' debe ser válida.
   POST: Actualiza la posición de 'mozo' si en esta no hay una mesa y posibilita la interacción con la mopa.*/
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

    if (!son_posiciones_iguales(nueva_posicion, juego->mozo.posicion) && !hay_mesa(juego->mesas, juego->cantidad_mesas, nueva_posicion)) {
        juego->mozo.posicion = nueva_posicion;
        juego->movimientos++;
    }
}

/* PRE: 'juego' debe estar correctamente inicializado.
   POST: Imprime por pantalla toda la información útil al momento de jugar.*/
void informacion_util(juego_t juego) {
    if (juego.mozo.tiene_mopa) {
        printf("Tenés la mopa.\n");
    } else if (!juego.mozo.tiene_mopa) {
        for (int i = 0; i < juego.cantidad_herramientas; i++) {
            if (juego.herramientas[i].tipo == MOPA) {
                if (son_posiciones_iguales(juego.mozo.posicion, juego.herramientas[i].posicion)) {
                    printf("Estás sobre la mopa. ¡Podés agarrarla!.\n");
                } else printf("No tenés la mopa.\n");
            } 
        }
    }

    printf("Realizó %i/%i movimientos.\n", juego.movimientos, MAX_MOVIMIENTOS);
    printf("Objetivo de monedas %i/%i.\n", juego.dinero, OBJETIVO_DINERO);
}

// POST: Inicializará el juego, cargando toda la información inicial de Linguini, las mesas, las herramientas y los obstáculos.
void inicializar_juego(juego_t *juego) {
    juego->cantidad_mesas = 0;
    juego->cantidad_herramientas = 0;
    juego->cantidad_obstaculos = 0;
    juego->movimientos = 0;
    juego->dinero = 0;

    inicializar_mesa(juego);
    inicializar_cocina(juego);
    inicializar_linguini(juego);
    inicializar_herramienta(juego, MOPA, CANTIDAD_MOPAS);
    inicializar_herramienta(juego, MONEDA, CANTIDAD_MONEDAS);
    inicializar_herramienta(juego, PATINES, CANTIDAD_PATINES);
    inicializar_obstaculo(juego, CHARCO, CANTIDAD_CHARCOS);
    inicializar_obstaculo(juego, CUCARACHA, CANTIDAD_CUCARACHAS);
    inicializar_terreno(*juego);
}

/* PRE: - El juego debe estar inicializado previamente con `inicializar_juego`;
        - 'acción' debe ser válida.
   POST: Realizará la acción recibida por parámetro.*/
void realizar_jugada(juego_t *juego, char accion) {
    realizar_movimiento(juego, accion);
}

/* PRE: El juego deberá estar inicializado previamente con `inicializar_juego`
   POST: - Devuelve: 1 si es ganado, -1 si es perdido, 0 si se sigue jugando;
         - El juego se dará por ganado cuando se termina el día y se consiguieron las monedas necesarias;
         - Se dará por perdido si se termina el día y no se llegó al monto.*/
int estado_juego(juego_t juego) {
    if (juego.movimientos == MAX_MOVIMIENTOS) {
        if (juego.dinero == OBJETIVO_DINERO) return 1;
        return -1;
    }
    return 0;
}

/* PRE: El juego debe estar inicializado previamente con `inicializar_juego`.
   POST: Imprime el juego por pantalla.*/
void mostrar_juego(juego_t juego) {
    system("clear");
    inicializar_terreno(juego);
    informacion_util(juego);
}