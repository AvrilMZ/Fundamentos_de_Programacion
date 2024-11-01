#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "restaurant.h"

#define ROJO_NEGRITA "\e[1;31m"
#define VERDE_NEGRITA "\e[1;32m"
#define AMARILLO_NEGRITA "\e[1;33m"
#define AZUL_NEGRITA "\e[1;34m"
#define VIOLETA_NEGRITA "\e[1;35m"
#define CELESTE_NEGRITA "\e[1;36m"
#define BLANCO_NEGRITA "\e[1;37m"
#define NORMAL "\e[0m"

#define ARRIBA 'W'
#define ABAJO 'S'
#define DERECHA 'D'
#define IZQUIERDA 'A'
#define MOPA 'O'
#define TOMAR_PEDIDO 'T'
#define USAR_PATINES 'P'
#define CHARCO 'H'
#define MONEDA 'M'
#define PATINES 'P'
#define CUCARACHA 'U'
#define MILANESA_NAPOLITANA 'M'
#define HAMBURGUESA 'H'
#define PARRILLA 'P'
#define RATATOUILLE 'R'
#define INDICE_MILANESA_NAPOLITANA 1
#define INDICE_HAMBURGUESA 2
#define INDICE_PARRILLA 3
#define INDICE_RATATOUILLE 4
#define MAX_MESAS_INDIVIDUALES 6
#define MAX_MESAS_GRUPALES 4
#define CANTIDAD_LUGARES_MESA_GRUPAL 4
#define POSICIONES_PASILLO 8

const char LINGUINI = 'L';
const char MESA = 'T';
const char MESA_OCUPADA = 'X';
const char COCINA = 'C';
const char VACIO = ' ';
const char* ERROR_RESERVAR_MEMORIA = "Hubo un error al reservar memoria.";

const int APARICION_COMENSALES = 15;
const int APARICION_CUCARACHAS = 25;
const int CANTIDAD_LUGARES_MESA_INDIVIDUAL = 1;
const int CANTIDAD_MOPAS = 1;
const int CANTIDAD_CHARCOS = 5;
const int CANTIDAD_MONEDAS = 8;
const int CANTIDAD_PATINES = 5;
const int OBJETIVO_DINERO = 150000;
const int MAX_MOVIMIENTOS = 200;
const int MAX_OPCIONES_MENU = 4;
const int VALOR_MONEDA = 1000;
const int VALOR_MESA_INDIVIDUAL = 5000;
const int VALOR_MESA_GRUPAL = 20000;
const int PACIENCIA_MINIMA_INICIAL = 100;
const int PACIENCIA_MAXIMA_INICIAL = 200;
const int PREPARACION_MILANESA_NAPOLITANA = 30;
const int PREPARACION_HAMBURGUESA = 15;
const int PREPARACION_PARRILLA = 20;
const int PREPARACION_RATATOUILLE = 25;
const int DISMINUCION_PACIENCIA_CUCARACHA = 2;
const int DISTANCIA_MESA_CUCARACHA = 2;
const int DISTANCIA_MESA_MOZO = 1;

// POST: Devuelve una posición aleatoria dentro del rango del terreno.
coordenada_t posicion_aleatoria() {
    coordenada_t posicion;
    posicion.fil = rand() % MAX_FILAS;
    posicion.col = rand() % MAX_COLUMNAS;
    return posicion;
}

// POST: Devuelve un valor aleatorio de comensales, entre 1 y 'MAX_MESAS_GRUPALES'.
int cantidad_aleatoria_comensales() {
    return (rand() % CANTIDAD_LUGARES_MESA_GRUPAL) + 1;
}

// POST: Devuelve un valor aleatorio de paciencia, entre 'PACIENCIA_MAXIMA_INICIAL' y 'PACIENCIA_MAXIMA_INICIAL'.
int cantidad_aleatoria_paciencia() {
    return (rand() % (PACIENCIA_MAXIMA_INICIAL - PACIENCIA_MINIMA_INICIAL + 1)) + PACIENCIA_MINIMA_INICIAL;
}

// POST: Devuelve un char aleatorio que representa una opción de pedido.
char pedido_aleatorio() {
    int numero_plato = (rand() % MAX_OPCIONES_MENU) + 1;

    switch (numero_plato) {
        case INDICE_MILANESA_NAPOLITANA:
            return MILANESA_NAPOLITANA;
        case INDICE_HAMBURGUESA:
            return HAMBURGUESA;
        case INDICE_PARRILLA:
            return PARRILLA;
        case INDICE_RATATOUILLE:
            return RATATOUILLE;
        default:
            return '\0';
    }
}

// POST: Devuelve true si las posiciones son iguales, de lo contrario devuelve false.
bool son_posiciones_iguales(coordenada_t coordenada, coordenada_t coordenada_a_comparar) {
    return (coordenada.fil == coordenada_a_comparar.fil && coordenada.col == coordenada_a_comparar.col);
}

//POST: Devuelve la distancia manhattan entre dos puntos dados.
int distancia_manhattan(coordenada_t punto1, coordenada_t punto2) {
    return abs(punto1.col - punto2.col) + abs(punto1.fil - punto2.fil);
}

/* PRE: - 'vector' no debe estar vacio;
        - 'tope' debe ser mayor estricto a cero;
        - 'indice_a_eliminar' debe ser mayor a cero y menor o igual a 'tope' menos uno.
   POST: Elimina el objeto en la posición 'indice_a_eliminar' de 'vector' mantieniendo el orden.*/
void eliminar_objeto(objeto_t vector[], int *tope, int indice_a_eliminar) {
    for (int i = indice_a_eliminar; i < *tope - 1; i++) {
        vector[i] = vector[i + 1];
    }
    (*tope)--;
}

/* PRE: - 'vector' no debe estar vacio;
        - 'tope' debe ser mayor estricto a cero;
        - 'indice_a_eliminar' debe ser mayor a cero y menor o igual a 'tope' menos uno.
   POST: Elimina el pedido en la posición 'indice_a_eliminar' de 'vector' mantieniendo el orden.*/
void eliminar_pedido(pedido_t vector[], int *tope, int indice_a_eliminar) {
    for (int i = indice_a_eliminar; i < *tope - 1; i++) {
        vector[i] = vector[i + 1];
    }
    (*tope)--;
}

/* PRE: - 'mesas' no debe estar vacio;
        - 'tope_mesas' debe ser mayor estricto a cero y menor o igual a 'MAX_MESAS';
        - 'posicion' debe estar dentro del rango del terreno de juego.
   POST: Devuelve true si hay una mesa en la posición especificada, de lo contrario devuelve false.*/
bool hay_mesa(mesa_t mesas[MAX_MESAS], int tope_mesas, coordenada_t posicion) {
    bool mesa_en_posicion = false;
    for (int i = 0; i < tope_mesas; i++) {
        for (int j = 0; j < mesas[i].cantidad_lugares; j++) {
            if (son_posiciones_iguales(mesas[i].posicion[j], posicion)) mesa_en_posicion = true;
        }
    }
    return mesa_en_posicion;
}

/* PRE: - Los topes dentro de 'juego' de 'mesas', 'herramientas' y 'obstaculos' deben estar correctamente inicializados;
        - 'posicion' debe estar dentro del rango del terreno de juego.
   POST: Devuelve true si la posicion no fue previamente asignada, de lo contrario devuelve false.*/
bool es_posicion_vacia(juego_t juego, coordenada_t posicion) {
    bool posicion_ocupada = false;

    if (hay_mesa(juego.mesas, juego.cantidad_mesas, posicion)) posicion_ocupada = true;

    if (son_posiciones_iguales(juego.cocina.posicion, posicion)) posicion_ocupada = true;

    if (son_posiciones_iguales(juego.mozo.posicion, posicion)) posicion_ocupada = true;

    for (int i = 0; i < juego.cantidad_herramientas; i++) {
        if (son_posiciones_iguales(juego.herramientas[i].posicion, posicion)) posicion_ocupada = true;
    }

    for (int i = 0; i < juego.cantidad_obstaculos; i++) {
        if (son_posiciones_iguales(juego.obstaculos[i].posicion, posicion)) posicion_ocupada = true;
    }

    return !posicion_ocupada;
}

/* PRE: - Los topes dentro de 'juego' de 'mesas', 'herramientas' y 'obstaculos' deben estar correctamente inicializados;
        - 'posicion' debe estar dentro del rango del terreno de juego.
   POST: Devuelve true si la posicion no fue previamente asignada (excluyendo a Linguini), de lo contrario devuelve false.*/
bool es_posicion_vacia_excepto_linguini(juego_t juego, coordenada_t posicion) {
    bool posicion_ocupada = false;

    if (hay_mesa(juego.mesas, juego.cantidad_mesas, posicion)) posicion_ocupada = true;

    if (son_posiciones_iguales(juego.cocina.posicion, posicion)) posicion_ocupada = true;

    for (int i = 0; i < juego.cantidad_herramientas; i++) {
        if (son_posiciones_iguales(juego.herramientas[i].posicion, posicion)) posicion_ocupada = true;
    }

    for (int i = 0; i < juego.cantidad_obstaculos; i++) {
        if (son_posiciones_iguales(juego.obstaculos[i].posicion, posicion)) posicion_ocupada = true;
    }

    return !posicion_ocupada;
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

    bool pasillos_ocupados = false;
    for (int i = 0; i < POSICIONES_PASILLO; i++) {
        bool posicion_valida = (pasillo[i].fil >= 0 && pasillo[i].fil < MAX_FILAS && pasillo[i].col >= 0 && pasillo[i].col < MAX_COLUMNAS);
        if (posicion_valida && hay_mesa(mesas, tope_mesas, pasillo[i])) pasillos_ocupados = true;
    }

    return !pasillos_ocupados;
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

    bool posiciones_ocupadas = false;
    for (int i = 0; i < CANTIDAD_LUGARES_MESA_GRUPAL; i++) {
        if (!es_posicion_vacia(*juego, posiciones[i])) posiciones_ocupadas = true;
    }

    for (int i = 0; i < CANTIDAD_LUGARES_MESA_GRUPAL; i++) {
        if (!pasillos_libres(juego->mesas, juego->cantidad_mesas, posiciones[i])) posiciones_ocupadas = true;
    }

    if (!posiciones_ocupadas) {
        for (int i = 0; i < CANTIDAD_LUGARES_MESA_GRUPAL; i++) juego->mesas[indice_mesa].posicion[i] = posiciones[i];
        juego->mesas[indice_mesa].cantidad_lugares = CANTIDAD_LUGARES_MESA_GRUPAL;
    }

    return !posiciones_ocupadas;
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

/* PRE: - 'mesas' no debe estar vacio;
        - 'tope_mesas' debe ser mayor estricto a cero y menor o igual a 'MAX_MESAS';
   POST: Asigna cada 'APARICION_COMENSALES' movimientos una cantidad aleatoria de comensales, entre 1 y 'CANTIDAD_LUGARES_MESA_GRUPAL', a la primer mesa vacia disponible.*/
void distribuir_comensales(mesa_t mesas[MAX_MESAS], int tope_mesas, int movimientos) {
    if (movimientos % APARICION_COMENSALES == 0 && movimientos > 0) {
        int comensales_sin_asiento = cantidad_aleatoria_comensales();
        bool lugares_asignados = false;

        for (int i = 0; i < tope_mesas && !lugares_asignados; i++) {
            if (mesas[i].cantidad_lugares >= comensales_sin_asiento && mesas[i].cantidad_comensales == 0) {
                mesas[i].cantidad_comensales = comensales_sin_asiento;
                lugares_asignados = true;
            }
        }
    }
}

/* PRE: - 'mesas' no debe estar vacio;
        - 'tope_mesas' debe ser mayor estricto a cero y menor o igual a 'MAX_MESAS';
        - 'paciencia' debe estar inicializado.
   POST: Le asigna a las mesas con comensales nuevos una cantidad de paciencia aleatoria entre 'PACIENCIA_MINIMA_INICIAL' y 'PACIENCIA_MAXIMA_INICIAL'.*/
void asignar_paciencia(mesa_t mesas[MAX_MESAS], int tope_mesas) {
    for (int i = 0; i < tope_mesas; i++) {
        if (mesas[i].cantidad_comensales > 0 && mesas[i].paciencia == 0) {
            mesas[i].paciencia = cantidad_aleatoria_paciencia();
        }
    }
}

/* PRE: - 'mesas' no debe estar vacio;
        - 'tope_mesas' debe ser mayor estricto a cero y menor o igual a 'MAX_MESAS';
        - 'paciencia' debe estar inicializado;
        - 'cantidad_preparacion' y 'cantidad_listos' de 'cocina' deben estar inicializados;
        - 'cantidad_pedidos' y 'cantidad_bandeja' de 'mozo' deben estar inicializados.
   POST: Decrementa una unidad de paciencia a cada mesa, únicamente si tiene, y si llega a cero, 'cantidad_comensales' pasa a ser cero y se eliminan los pedidos relacionados.*/
void perdida_paciencia(mesa_t mesas[MAX_MESAS], int tope_mesas, cocina_t *cocina, mozo_t *mozo) {
    for (int i = 0; i < tope_mesas; i++) {
        if (mesas[i].paciencia > 0) {
            mesas[i].paciencia--;
        } else {
            mesas[i].cantidad_comensales = 0;
            for (int j = 0; j < cocina->cantidad_preparacion; j++) {
                if (cocina->platos_preparacion[j].id_mesa == i) {
                    eliminar_pedido(cocina->platos_preparacion, &cocina->cantidad_preparacion, j);
                    j--;
                }
            }
            for (int j = 0; j < cocina->cantidad_listos; j++) {
                if (cocina->platos_listos[j].id_mesa == i) {
                    eliminar_pedido(cocina->platos_listos, &cocina->cantidad_listos, j);
                    j--;
                }
            }
            for (int j = 0; j < mozo->cantidad_pedidos; j++) {
                if (mozo->pedidos[j].id_mesa == i) {
                    eliminar_pedido(mozo->pedidos, &mozo->cantidad_pedidos, j);
                    j--;
                }
            }
            for (int j = 0; j < mozo->cantidad_bandeja; j++) {
                if (mozo->bandeja[j].id_mesa == i) {
                    eliminar_pedido(mozo->bandeja, &mozo->cantidad_bandeja, j);
                    j--;
                }
            }
        }
    }
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

/* PRE: - 'posicion_linguini' debe estar inicializada y ser una coordenada válida.
        - 'mesas' no debe estar vacio;
        - 'tope_mesas' debe ser mayor estricto a cero y menor o igual a 'MAX_MESAS'.
   POST: Devuelve el inidice de mesa del vector 'mesas' cuya distancia, desde cualquier posición, con Linguini sea 'DISTANCIA_MESA_MOZO' y no este vacia. Si no encuentra ninguna devuelve -1.*/
int mesa_posible_tomar_pedido(coordenada_t posicion_linguini, mesa_t mesas[MAX_MESAS], int tope_mesas) {
    int mesa_posible_tomar_pedido = -1;
    for (int i = 0; i < tope_mesas; i++) {
        if (mesas[i].cantidad_comensales > 0 && mesas[i].pedido_tomado == false) {
            for (int j = 0; j < mesas[i].cantidad_lugares; j++) {
                if (distancia_manhattan(posicion_linguini, mesas[i].posicion[j]) == DISTANCIA_MESA_MOZO) {
                    mesa_posible_tomar_pedido = i;
                }
            }
        }
    }
    return mesa_posible_tomar_pedido;
}

/* PRE: 'cantidad_pedidos' debe estar inicializado.
   POST: Devuelve el tiempo de preparación mayor entre todos los platos del pedido.*/
int mayor_tiempo_preparacion(char platos[MAX_PEDIDOS], int cantidad_platos) {
    int tiempo_preparacion_mayor = 0;
    for (int i = 0; i < cantidad_platos; i++) {
        int tiempo_actual = 0;

        switch (platos[i]) {
            case MILANESA_NAPOLITANA:
                tiempo_actual = PREPARACION_MILANESA_NAPOLITANA;
                break;
            case HAMBURGUESA:
                tiempo_actual = PREPARACION_HAMBURGUESA;
                break;
            case PARRILLA:
                tiempo_actual = PREPARACION_PARRILLA;
                break;
            case RATATOUILLE:
                tiempo_actual = PREPARACION_RATATOUILLE;
                break;
        }

        if (tiempo_actual > tiempo_preparacion_mayor) tiempo_preparacion_mayor = tiempo_actual;
    }
    return tiempo_preparacion_mayor;
}

/* PRE: - 'posicion_linguini' debe estar inicializada y ser una coordenada válida;
        - 'cantidad_pedidos' debe estar inicializado;
        - 'mesas' no debe estar vacio;
        - 'tope_mesas' debe ser mayor estricto a cero y menor o igual a 'MAX_MESAS'.
   POST: Toma el pedido de todos los comesales de una mesa guardandolo en el vector 'pedidos', si Linguini no tiene la mopa.*/
void tomar_pedido(coordenada_t posicion_linguini, pedido_t pedidos[MAX_PEDIDOS], int *cantidad_pedidos, mesa_t mesas[MAX_MESAS], int tope_mesas, bool tiene_mopa) {
    if (tiene_mopa) return;

    int id_mesa_pedido = mesa_posible_tomar_pedido(posicion_linguini, mesas, tope_mesas);
    if (id_mesa_pedido != -1) {
        if (*cantidad_pedidos + 1 > MAX_PEDIDOS) return;

        pedidos[*cantidad_pedidos].id_mesa = id_mesa_pedido;
        pedidos[*cantidad_pedidos].cantidad_platos = 0;

        for (int i = 0; i < mesas[id_mesa_pedido].cantidad_comensales; i++) {
            pedidos[*cantidad_pedidos].platos[i] = pedido_aleatorio();
            pedidos[*cantidad_pedidos].cantidad_platos++;
        }

        mesas[id_mesa_pedido].pedido_tomado = true;
        pedidos[*cantidad_pedidos].tiempo_preparacion = mayor_tiempo_preparacion(pedidos[*cantidad_pedidos].platos, pedidos[*cantidad_pedidos].cantidad_platos);
        (*cantidad_pedidos)++;
    }
}

/* PRE: - 'posicion_linguini' debe estar inicializada y ser una coordenada válida;
        - 'cantidad_pedidos' debe estar inicializado;
        - 'mesas' no debe estar vacio;
        - 'tope_mesas' debe ser mayor estricto a cero y menor o igual a 'MAX_MESAS';
        - 'dinero' debe estar inicilizado.
   POST: Al acercarse a distancia 'DISTANCIA_MESA_MOZO' de una mesa, cuyo 'id_mesa' se encuentre en algun pedido de 'bandeja', esta se vacia y se elimina el pedido de 'bandeja' sumandole un monto a 'dinero' dependiendo de 'cantiadad_comesales' que tenia.*/
void entregar_pedido(coordenada_t posicion_linguini, pedido_t bandeja[MAX_PEDIDOS], int *cantidad_bandeja, mesa_t mesas[MAX_MESAS], int tope_mesas, bool tiene_mopa, int *dinero) {
    if (tiene_mopa) return;

    for (int i = 0; i < tope_mesas; i++) {
        for (int j = 0; j < mesas[i].cantidad_lugares; j++) {
            for (int k = 0; k < *cantidad_bandeja; k++) {
                if (distancia_manhattan(posicion_linguini, mesas[i].posicion[j]) == DISTANCIA_MESA_MOZO && bandeja[k].id_mesa == i) {
                    eliminar_pedido(bandeja, cantidad_bandeja, k);
                    k--;

                    mesas[i].cantidad_comensales = 0;
                    mesas[i].paciencia = 0;
                    mesas[i].pedido_tomado = false;

                    if (mesas[i].cantidad_lugares == CANTIDAD_LUGARES_MESA_INDIVIDUAL) *dinero += VALOR_MESA_INDIVIDUAL;
                    else if (mesas[i].cantidad_lugares > CANTIDAD_LUGARES_MESA_INDIVIDUAL) *dinero += VALOR_MESA_GRUPAL;
                }
            }
        }
    }
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

// POST: Reserva memoria dinamica para el vector 'platos_preparacion' de cocina e inicializa 'cantidad_preparacion'.
void platos_en_preparacion(pedido_t **platos_preparacion, int *cantidad_preparacion) {
    *platos_preparacion = malloc(sizeof(pedido_t) * MAX_PLATOS);
    if (*platos_preparacion == NULL) {
        printf("%s\n", ERROR_RESERVAR_MEMORIA);
        free(*platos_preparacion);
        return;
    }
    *cantidad_preparacion = 0;
}

// POST: Reserva memoria dinamica para el vector 'platos_listos' de cocina e inicializa 'cantidad_listos'.
void platos_listos(pedido_t **platos_listos, int *cantidad_listos) {
    *platos_listos = malloc(sizeof(pedido_t) * MAX_PLATOS);
    if (*platos_listos == NULL) {
        printf("%s\n", ERROR_RESERVAR_MEMORIA);
        free(*platos_listos);
        return;
    }
    *cantidad_listos = 0;

}

/* PRE: - 'posicion' en 'mozo' debe ser valida;
        - 'cantidad_pedidos' y 'cantiadad_bandeja' en 'mozo' deben estar inicializados;
        - 'cantidad_preparacion' y 'cantidad_listos' en 'cocina' deben estar inicializados.
   POST: Si la posición de 'mozo' es igual a la de 'cocina': 
            - 'mozo' le pasa los elementos de su vector 'pedidos' a 'cocina' en 'platos_preparacion', asignando el 'tiempo_preparacion';
            - 'cocina' le pasa los elementos de su vector 'platos_listos' a 'mozo' en 'bandeja'.*/
void interaccion_linguini_cocina(mozo_t *mozo, cocina_t *cocina) {
    if (!son_posiciones_iguales(mozo->posicion, cocina->posicion)) return;

    if (mozo->cantidad_pedidos > 0) {
        for (int i = 0; i < mozo->cantidad_pedidos; i++) {
            cocina->platos_preparacion[cocina->cantidad_preparacion] = mozo->pedidos[i];
            cocina->cantidad_preparacion++;
            eliminar_pedido(mozo->pedidos, &mozo->cantidad_pedidos, i);
            i--;
        }

        for (int i = 0; i < cocina->cantidad_preparacion; i++) {
            cocina->platos_preparacion[i].tiempo_preparacion = mayor_tiempo_preparacion(cocina->platos_preparacion[i].platos, cocina->platos_preparacion[i].cantidad_platos);
        }
    }

    if (cocina->cantidad_listos > 0 && mozo->cantidad_bandeja < MAX_BANDEJA - 1) {
        for (int i = 0; i < cocina->cantidad_listos; i++) {
            mozo->bandeja[mozo->cantidad_bandeja] = cocina->platos_listos[i];
            mozo->cantidad_bandeja++;
            eliminar_pedido(cocina->platos_listos, &cocina->cantidad_listos, i);
            i--;
        }
    }
}

/* PRE: 'cantidad_preparacion' y 'cantidad_listos' en 'cocina' deben estar inicializados.
   POST: Cuando el elemento de 'platos_preparacion' llega a 'tiempo_preparacion' igual cero, este se pasa al vector 'platos_listos'.*/
void preparacion_platos(cocina_t *cocina) {
    for (int i = 0; i < cocina->cantidad_preparacion; i++) {
        if (cocina->platos_preparacion[i].tiempo_preparacion > 0) {
            cocina->platos_preparacion[i].tiempo_preparacion--;
        }
        if (cocina->platos_preparacion[i].tiempo_preparacion == 0) {
            cocina->platos_listos[cocina->cantidad_listos] = cocina->platos_preparacion[i];
            cocina->cantidad_listos++;
            eliminar_pedido(cocina->platos_preparacion, &cocina->cantidad_preparacion, i);
            i--;
        }
    }
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
        - 'cantidad_obstaculo' debe ser mayor estricto a cero y menor o igual a 'MAX_OBSTACULOS'.
   POST: Inicializa la cantidad de charcos pasada en una posición aleatoria, si esta ya está ocupada le asigna nuevamente otra aleatoria.*/
void inicializar_charco(juego_t *juego, int cantidad_obstaculo) {
    coordenada_t posicion;    

    for (int i = 0; i < cantidad_obstaculo; i++) {
        int intentos = 0;
        do {
            posicion = posicion_aleatoria();
            intentos++;
            if (intentos > (MAX_FILAS * MAX_COLUMNAS)) return; 
        } while (!es_posicion_vacia(*juego, posicion));

        juego->obstaculos[juego->cantidad_obstaculos].tipo = CHARCO;
        juego->obstaculos[juego->cantidad_obstaculos].posicion = posicion;
        juego->cantidad_obstaculos++;
    }
}

/* PRE: - El tope 'cantidad_obstaculos' de 'obstaculos' dentro de 'juego' debe estar correctamente inicializado;
        - 'cantidad_obstaculo' debe ser mayor estricto a cero y menor o igual a 'MAX_OBSTACULOS'.
   POST: Inicializa una cucaracha cada 'APARICION_CUCARACHAS' movimientos en una posición aleatoria, si esta ya está ocupada le asigna nuevamente otra aleatoria.*/
void inicializar_cucaracha(juego_t *juego) {
    if (juego->movimientos % APARICION_CUCARACHAS == 0 && juego->movimientos > 0) {
        coordenada_t posicion;
        int intentos = 0;

        do {
            posicion = posicion_aleatoria();
            intentos++;
            if (intentos > (MAX_FILAS * MAX_COLUMNAS)) return; 
        } while (!es_posicion_vacia(*juego, posicion));

        juego->obstaculos[juego->cantidad_obstaculos].tipo = CUCARACHA;
        juego->obstaculos[juego->cantidad_obstaculos].posicion = posicion;
        juego->cantidad_obstaculos++;
    }
}

/* PRE: - 'obstaculos' no debe estar vacio;
        - 'tope_obstaculos' debe ser mayor estricto a cero y menor o igual a 'MAX_OBSTACULOS';
        - 'mesas' no debe estar vacio;
        - 'tope_mesas' debe ser mayor estricto a cero y menor o igual a 'MAX_MESAS';
        - 'paciencia' debe estar inicializado.
   POST: Si una cucaracha se encuentra a una distancia manhattan menor o igual a 'DISTANCIA_MESA_CUCARACHA' de una mesa, a esa se le quita un valor de 'DISMINUCION_PACIENCIA_CUCARACHA'.*/
void perdida_paciencia_cucarachas(objeto_t obstaculos[MAX_OBSTACULOS], int tope_obstaculos, mesa_t mesas[MAX_MESAS], int tope_mesas) {
    for (int i = 0; i < tope_obstaculos; i++) {
        if (obstaculos[i].tipo == CUCARACHA) {
            coordenada_t posicion_cucaracha = obstaculos[i].posicion;
            for (int j = 0; j < tope_mesas; j++) {
                for (int k = 0; k < mesas[j].cantidad_lugares; k++) {
                    if (mesas[j].cantidad_comensales > 0 && distancia_manhattan(mesas[j].posicion[k], posicion_cucaracha) <= DISTANCIA_MESA_CUCARACHA) {
                        mesas[j].paciencia -= DISMINUCION_PACIENCIA_CUCARACHA;
                    }
                }
            }
        }
    }
}

/* PRE: - 'posicion_linguini' debe estar dentro del rango del terreno de juego;
        - 'obstaculos' no debe estar vacio;
        - 'tope_obstaculos' debe ser mayor estricto a cero y menor o igual a 'MAX_OBSTACULOS';
   POST: Si Linguini pasa sobre una cucaracha, sin tener la mopa, esta se elimina de la posición.*/
void matar_cucarachas(coordenada_t posicion_linguini, objeto_t obstaculos[MAX_OBSTACULOS], int *tope_obstaculos, bool tiene_mopa) {
    if (tiene_mopa) return;
    
    for (int i = 0; i < *tope_obstaculos; i++) {
        if (obstaculos[i].tipo == CUCARACHA && son_posiciones_iguales(posicion_linguini, obstaculos[i].posicion)) {
            obstaculos[i] = obstaculos[*tope_obstaculos - 1];
            (*tope_obstaculos)--;
            i--;
        }
    }
}

/* PRE: - 'herramientas' no debe estar vacio;
        - 'tope_herramientas' debe ser mayor estricto a cero y menor o igual a 'MAX_HERRAMIENTAS';
        - 'posicion' debe estar dentro del rango del terreno de juego.
   POST: Devuelve el carácter correspondiente a la herramienta encontrada en la posición dada.*/
char buscar_herramienta(objeto_t herramientas[MAX_HERRAMIENTAS], int tope_herramientas, coordenada_t posicion) {
    char herramienta_encontrada = VACIO;
    for (int i = 0; i < tope_herramientas; i++) {
        if (son_posiciones_iguales(herramientas[i].posicion, posicion)) {
            herramienta_encontrada = herramientas[i].tipo;
        }
    }
    return herramienta_encontrada;
}

/* PRE: - 'posicion_linguini' debe estar dentro del rango del terreno de juego;
        - 'herramientas' no debe estar vacio;
        - 'tope_herramientas' debe ser mayor estricto a cero y menor o igual a 'MAX_HERRAMIENTAS';
        - 'dinero' debe estar inicializado.
   POST: Si Linguini pasa sobre una moneda, sin tener la mopa, incrementa el total de dinero recolectado, con una cantidad de 'VALOR_MONEDA', y elimina la moneda de la posición.*/
void recolectar_monedas(coordenada_t posicion_linguini, objeto_t herramientas[MAX_HERRAMIENTAS], int *tope_herramientas, int *dinero, bool tiene_mopa) {
    if (tiene_mopa) return;
    
    for (int i = 0; i < *tope_herramientas; i++) {
        if (herramientas[i].tipo == MONEDA && son_posiciones_iguales(posicion_linguini, herramientas[i].posicion)) {
            *dinero += VALOR_MONEDA;

            herramientas[i] = herramientas[*tope_herramientas - 1];
            (*tope_herramientas)--;
            i--;
        }
    }
}

/* PRE: - 'posicion_linguini' debe estar dentro del rango del terreno de juego;
        - 'cantidad_patines' debe estar inicializado;
        - 'herramientas' no debe estar vacio;
        - 'tope_herramientas' debe ser mayor estricto a cero y menor o igual a 'MAX_HERRAMIENTAS'.
   POST: Si Linguini pasa sobre unos patines, sin tener la mopa, incrementa el contador 'cantidad_patines' y elimina los patines de la posición.*/
void recolectar_patines(coordenada_t posicion_linguini, int *cantidad_patines, objeto_t herramientas[MAX_HERRAMIENTAS], int *tope_herramientas, bool tiene_mopa) {
    if (tiene_mopa) return;
    
    for (int i = 0; i < *tope_herramientas; i++) {
        if (herramientas[i].tipo == PATINES && son_posiciones_iguales(posicion_linguini, herramientas[i].posicion)) {
            (*cantidad_patines)++;

            herramientas[i] = herramientas[*tope_herramientas - 1];
            (*tope_herramientas)--;
            i--;
        }
    }
}

/* PRE: - 'obstaculos' no debe estar vacio;
        - 'tope_obstaculos' debe ser mayor estricto a cero y menor o igual a 'MAX_OBSTACULOS';
        - 'posicion' debe estar dentro del rango del terreno de juego.
   POST: Devuelve el carácter correspondiente a el obstáculo encontrado en la posición dada.*/
char buscar_obstaculo(objeto_t obstaculos[MAX_OBSTACULOS], int tope_obstaculos, coordenada_t posicion) {
    char obstaculo_encontrado = VACIO;
    for (int i = 0; i < tope_obstaculos; i++) {
        if (son_posiciones_iguales(obstaculos[i].posicion, posicion)) {
            obstaculo_encontrado = obstaculos[i].tipo;
        }
    }
    return obstaculo_encontrado;
}

/* PRE: - 'posicion_linguini' debe estar dentro del rango del terreno de juego;
        - 'obstaculos' no debe estar vacio;
        - 'tope_obstaculos' debe ser mayor estricto a cero y menor o igual a 'MAX_OBSTACULOS'.
   POST: Si Linguini tiene la mopa y pasa sobre un charco este se elimina de la posición.*/
void limpiar_charcos(coordenada_t posicion_linguini, bool tiene_mopa, objeto_t obstaculos[MAX_OBSTACULOS], int *tope_obstaculos) {
    for (int i = 0; i < *tope_obstaculos; i++) {
        if (obstaculos[i].tipo == CHARCO && son_posiciones_iguales(posicion_linguini, obstaculos[i].posicion) && tiene_mopa) {
            obstaculos[i] = obstaculos[*tope_obstaculos - 1];
            (*tope_obstaculos)--;
            i--;
        }
    }
}

/* PRE: - 'posicion_linguini' debe estar dentro del rango del terreno de juego;
        - 'tope_bandeja' debe estar inicializado;
        - 'obstaculos' no debe estar vacio;
        - 'tope_obstaculos' debe ser mayor estricto a cero y menor o igual a 'MAX_OBSTACULOS';
        - 'mesas' no debe estar vacio;
        - 'tope_mesas' debe ser mayor estricto a cero y menor o igual a 'MAX_MESAS'.
   POST: Si 'posicion_linguini' es la misma que la de un 'CHARCO' entonces el vector 'bandeja' se vacia y la mesa cuyo pedido correspondia pasa a tener 'cantiadad_comesales' cero.*/
void resbalar_charcos(coordenada_t posicion_linguini, pedido_t bandeja[MAX_BANDEJA], int *tope_bandeja, objeto_t obstaculos[MAX_OBSTACULOS], int tope_obstaculos, mesa_t mesas[MAX_MESAS], int tope_mesas) {
    for (int i = 0; i < tope_obstaculos; i++) {
        if (obstaculos[i].tipo == CHARCO && son_posiciones_iguales(obstaculos[i].posicion, posicion_linguini) && *tope_bandeja > 0) {
            for (int j = 0; j < *tope_bandeja; j++) {
                mesas[bandeja[j].id_mesa].cantidad_comensales = 0;
            }
            *tope_bandeja = 0;
        }
    }
}

/* PRE: - Los topes dentro de 'juego' de 'mesas', 'herramientas' y 'obstaculos' deben estar correctamente inicializados;
        - 'posicion' debe estar dentro del rango del terreno de juego.
   POST: Devuelve el carácter correspondiente al contenido en la posición.*/
char obtener_contenido_posicion(juego_t juego, coordenada_t posicion) {
    char contenido = VACIO;

    if (hay_mesa(juego.mesas, juego.cantidad_mesas, posicion)) {
        for (int i = 0; i < juego.cantidad_mesas; i++) {
            for (int j = 0; j < juego.mesas[i].cantidad_lugares; j++) {
                if (son_posiciones_iguales(juego.mesas[i].posicion[j], posicion)) {
                    if (j < juego.mesas[i].cantidad_comensales) contenido = MESA_OCUPADA;
                    else contenido = MESA;
                }
            }
        }
    }

    char herramienta = buscar_herramienta(juego.herramientas, juego.cantidad_herramientas, posicion);
    if (herramienta != VACIO) contenido = herramienta;

    char obstaculo = buscar_obstaculo(juego.obstaculos, juego.cantidad_obstaculos, posicion);
    if (obstaculo != VACIO) contenido = obstaculo;

    if (son_posiciones_iguales(juego.cocina.posicion, posicion)) contenido = COCINA;

    if (son_posiciones_iguales(juego.mozo.posicion, posicion)) contenido = LINGUINI;

    return contenido;
}

/* PRE: los topes dentro de 'juego' deben estar inicializados.
   POST: Imprime cómo se visualizará el terreno de juego, mostrando el contenido de cada posición.*/
void inicializar_terreno(juego_t juego) {
    coordenada_t posicion;
    for (int i = 0; i < MAX_FILAS; i++) {
        posicion.fil = i;
        for (int j = 0; j < MAX_COLUMNAS; j++) {
            char contenido_posicion = VACIO;
            posicion.col = j;
            contenido_posicion = obtener_contenido_posicion(juego, posicion);

            bool es_mesa = (contenido_posicion == MESA || contenido_posicion == MESA_OCUPADA);
            bool pedido_tomado = false;
            bool en_bandeja = false;
            int id_mesa = -1;
            int cantidad_comensales = 0;

            if (es_mesa) {
                for (int k = 0; k < juego.cantidad_mesas; k++) {
                    for (int l = 0; l < juego.mesas[k].cantidad_lugares; l++) {
                        if (son_posiciones_iguales(juego.mesas[k].posicion[l], posicion)) {
                            pedido_tomado = juego.mesas[k].pedido_tomado;
                            cantidad_comensales = juego.mesas[k].cantidad_comensales;
                            id_mesa = k;
                        }
                    }
                }
                for (int k = 0; k < juego.mozo.cantidad_bandeja; k++) {
                    if (juego.mozo.bandeja[k].id_mesa == id_mesa) en_bandeja = true;
                }
            }

            if (contenido_posicion == LINGUINI) {
                printf("| %s%c%s  ", CELESTE_NEGRITA, contenido_posicion, NORMAL);
            } else if (contenido_posicion == COCINA || contenido_posicion == MOPA) {
                printf("| %s%c%s  ", AZUL_NEGRITA, contenido_posicion, NORMAL);
            } else if (contenido_posicion == MONEDA) {
            printf("| %s%c%s  ", AMARILLO_NEGRITA, contenido_posicion, NORMAL);
            } else if (contenido_posicion == CUCARACHA) {
                printf("| %s%c%s  ", VIOLETA_NEGRITA, contenido_posicion, NORMAL);
            } else if (es_mesa && !pedido_tomado && cantidad_comensales > 0) {
                printf("| %s%c%s  ", ROJO_NEGRITA, contenido_posicion, NORMAL);
            } else if (es_mesa && en_bandeja) {
                printf("| %s%c%s  ", VERDE_NEGRITA, contenido_posicion, NORMAL);
            } else printf("| %s%c%s  ", BLANCO_NEGRITA, contenido_posicion, NORMAL);
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
    if (juego->mozo.tiene_mopa) {
        if (es_posicion_vacia_excepto_linguini(*juego, juego->mozo.posicion)) {
            juego->mozo.tiene_mopa = false;
            juego->herramientas[juego->cantidad_herramientas].posicion = juego->mozo.posicion;
            juego->herramientas[juego->cantidad_herramientas].tipo = MOPA;
            juego->cantidad_herramientas++;
        }
    } else {
        for (int i = 0; i < juego->cantidad_herramientas; i++) {
            if (juego->herramientas[i].tipo == MOPA) {
                coordenada_t posicion_mopa = juego->herramientas[i].posicion;
                if (son_posiciones_iguales(juego->mozo.posicion, posicion_mopa)) {
                    if (!juego->mozo.tiene_mopa) {
                        juego->mozo.tiene_mopa = true;
                        eliminar_objeto(juego->herramientas, &juego->cantidad_herramientas, i);
                    }
                }
            }
        }
    }
}

/* PRE: - La posición de 'mozo' en 'juego' ya debe estar inicializada;
        - La 'cantidad_patines' de 'mozo' debe ser mayor estricto que cero; 
        - El tope 'cantidad_mesas' de 'mesas' dentro de 'juego' debe estar correctamente inicializado;
        - 'patines_puestos' debe ser 'true'.
   POST: Mueve al mozo a traves de toda la fila o columna, o hasta que se encuentre con una mesa, interactuando con todos los elementos en su camino.*/
void utilizar_patines(juego_t *juego, char accion) {
    if (accion != ARRIBA && accion != ABAJO && accion != DERECHA && accion != IZQUIERDA) return;

    coordenada_t nueva_posicion = juego->mozo.posicion;
    bool continuar = true;

    while (continuar) {
        coordenada_t siguiente_posicion = nueva_posicion;
        switch (accion) {
            case ARRIBA:
                siguiente_posicion.fil--;
                break;
            case ABAJO:
                siguiente_posicion.fil++;
                break;
            case DERECHA:
                siguiente_posicion.col++;
                break;
            case IZQUIERDA:
                siguiente_posicion.col--;
                break;
        }

        if (siguiente_posicion.fil < 0 || siguiente_posicion.fil >= MAX_FILAS || siguiente_posicion.col < 0 || siguiente_posicion.col >= MAX_COLUMNAS || hay_mesa(juego->mesas, juego->cantidad_mesas, siguiente_posicion))
            continuar = false;
        else {
            nueva_posicion = siguiente_posicion;
            juego->mozo.posicion = nueva_posicion;

            matar_cucarachas(juego->mozo.posicion, juego->obstaculos, &juego->cantidad_obstaculos, juego->mozo.tiene_mopa);
            recolectar_monedas(juego->mozo.posicion, juego->herramientas, &juego->cantidad_herramientas, &juego->dinero, juego->mozo.tiene_mopa);
            recolectar_patines(juego->mozo.posicion, &juego->mozo.cantidad_patines, juego->herramientas, &juego->cantidad_herramientas, juego->mozo.tiene_mopa);
            limpiar_charcos(juego->mozo.posicion, juego->mozo.tiene_mopa, juego->obstaculos, &juego->cantidad_obstaculos);
            resbalar_charcos(juego->mozo.posicion, juego->mozo.bandeja, &juego->mozo.cantidad_bandeja, juego->obstaculos, juego->cantidad_obstaculos, juego->mesas, juego->cantidad_mesas);
            entregar_pedido(juego->mozo.posicion, juego->mozo.bandeja, &juego->mozo.cantidad_bandeja, juego->mesas, juego->cantidad_mesas, juego->mozo.tiene_mopa, &juego->dinero);
            interaccion_linguini_cocina(&juego->mozo, &juego->cocina);
        }
    }

    juego->mozo.patines_puestos = false;
    juego->mozo.cantidad_patines--;
}

/* PRE: - La posición de 'mozo' en 'juego' ya debe estar inicializada;
        - El tope 'cantidad_mesas' de 'mesas' dentro de 'juego' debe estar correctamente inicializado.
        - 'acción' debe ser válida.
   POST: - Actualiza la posición de 'mozo' si en esta no hay una mesa; 
         - Posibilita la interacción con la mopa, tomar pedidos y usar patines.*/
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
            break;
        case TOMAR_PEDIDO:
            tomar_pedido(juego->mozo.posicion, juego->mozo.pedidos, &juego->mozo.cantidad_pedidos, juego->mesas, juego->cantidad_mesas, juego->mozo.tiene_mopa);
            break;
        case USAR_PATINES:
            if (juego->mozo.cantidad_patines > 0) {
                juego->mozo.patines_puestos = true;
                char siguiente_accion = ' ';
                scanf(" %c", &siguiente_accion);
                utilizar_patines(juego, siguiente_accion);
            }
            return;
    }

    if (!son_posiciones_iguales(nueva_posicion, juego->mozo.posicion) && !hay_mesa(juego->mesas, juego->cantidad_mesas, nueva_posicion)) {
        juego->mozo.posicion = nueva_posicion;
        juego->movimientos++;
    }
}

//POST: Imprime por pantalla un mensaje de bienvenida con aclaraciones importantes.
void mensaje_intro() {
    printf("¡Bienvenido!\n\
Cosas a tener en cuenta antes de jugar:\n\
\t- El personaje de juego, Linguini, se encuentra representado con una %s%c%s;\n\
\t- Las mesas ocupadas con pedidos a tomar se visualizan como %s%c%s;\n\
\t- Las mesas cuyos pedidos están listos y ya han sido recolectados por Linguini se visualizan como %s%c%s;\n\
\t- Las monedas se visualizarán con una %s%c%s;\n\
\t- Las cucarachas se visualizarán con una %s%c%s;\n\
\t- La mopa (%s%c%s) y la cocina (%s%c%s) se visualizan en azul;\n\
\t- El resto de los elementos, charcos (%s%c%s), patines (%s%c%s) y monedas (%s%c%s), se visualizan normalmente, además de las mesas desocupadas (%s%c%s).\n\
¡Que lo disfrutes!\n\
\n\
", CELESTE_NEGRITA, LINGUINI, NORMAL, ROJO_NEGRITA, MESA_OCUPADA, NORMAL, VERDE_NEGRITA, MESA_OCUPADA, NORMAL, AMARILLO_NEGRITA, MONEDA, NORMAL, VIOLETA_NEGRITA, CUCARACHA, NORMAL, 
AZUL_NEGRITA, MOPA, NORMAL, AZUL_NEGRITA, COCINA, NORMAL, BLANCO_NEGRITA, CHARCO, NORMAL, BLANCO_NEGRITA, PATINES, NORMAL, BLANCO_NEGRITA, MONEDA, NORMAL, BLANCO_NEGRITA, MESA, NORMAL);
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

    if (juego.mozo.cantidad_patines == 0) printf("No tenés patines.\n");
    else if (juego.mozo.cantidad_patines == 1) printf("Tenés %i par de patines.\n", juego.mozo.cantidad_patines);
    else printf("Tenés %i pares de patines.\n", juego.mozo.cantidad_patines);

    printf("Pedidos tomados: %i\n", juego.mozo.cantidad_pedidos);
    printf("Pedidos listos en cocina: %i\n", juego.cocina.cantidad_listos);
    printf("Pedidos a entregar: %i\n", juego.mozo.cantidad_bandeja);
    
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
    inicializar_charco(juego, CANTIDAD_CHARCOS);
    inicializar_terreno(*juego);

    platos_en_preparacion(&juego->cocina.platos_preparacion, &juego->cocina.cantidad_preparacion);
    platos_listos(&juego->cocina.platos_listos, &juego->cocina.cantidad_listos);
}

/* PRE: - El juego debe estar inicializado previamente con `inicializar_juego`;
        - 'acción' debe ser válida.
   POST: Realizará la acción recibida por parámetro.*/
void realizar_jugada(juego_t *juego, char accion) {
    realizar_movimiento(juego, accion);

    distribuir_comensales(juego->mesas, juego->cantidad_mesas, juego->movimientos);
    asignar_paciencia(juego->mesas, juego->cantidad_mesas);
    perdida_paciencia(juego->mesas, juego->cantidad_mesas, &juego->cocina, &juego->mozo);
    entregar_pedido(juego->mozo.posicion, juego->mozo.bandeja, &juego->mozo.cantidad_bandeja, juego->mesas, juego->cantidad_mesas, juego->mozo.tiene_mopa, &juego->dinero);

    preparacion_platos(&juego->cocina);
    interaccion_linguini_cocina(&juego->mozo, &juego->cocina);

    inicializar_cucaracha(juego);
    matar_cucarachas(juego->mozo.posicion, juego->obstaculos, &juego->cantidad_obstaculos, juego->mozo.tiene_mopa);
    perdida_paciencia_cucarachas(juego->obstaculos, juego->cantidad_obstaculos,juego->mesas, juego->cantidad_mesas);
    
    recolectar_monedas(juego->mozo.posicion, juego->herramientas, &juego->cantidad_herramientas, &juego->dinero, juego->mozo.tiene_mopa);
    recolectar_patines(juego->mozo.posicion, &juego->mozo.cantidad_patines, juego->herramientas, &juego->cantidad_herramientas, juego->mozo.tiene_mopa);
    limpiar_charcos(juego->mozo.posicion, juego->mozo.tiene_mopa, juego->obstaculos, &juego->cantidad_obstaculos);
    resbalar_charcos(juego->mozo.posicion, juego->mozo.bandeja, &juego->mozo.cantidad_bandeja, juego->obstaculos, juego->cantidad_obstaculos, juego->mesas, juego->cantidad_mesas);
}

/* PRE: El juego deberá estar inicializado previamente con `inicializar_juego`
   POST: - Devuelve: 1 si es ganado, -1 si es perdido, 0 si se sigue jugando;
         - El juego se dará por ganado cuando se termina el día y se consiguieron las monedas necesarias;
         - Se dará por perdido si se termina el día y no se llegó al monto.*/
int estado_juego(juego_t juego) {
    if (juego.movimientos == MAX_MOVIMIENTOS) {
        if (juego.dinero >= OBJETIVO_DINERO) return 1;
        return -1;
    }
    return 0;
}

/* PRE: El juego debe estar inicializado previamente con `inicializar_juego`.
   POST: Imprime el juego por pantalla.*/
void mostrar_juego(juego_t juego) {
    system("clear");
    if (juego.movimientos == 0) mensaje_intro();
    inicializar_terreno(juego);
    informacion_util(juego);
}

/* PRE: Los campos 'platos_preparacion' y 'platos_listos' del campo 'cocina' del juego deben estar inicializados.
   POST: Libera la memoria dinámica reservada para el juego.*/
void destruir_juego(juego_t *juego) {
    free(juego->cocina.platos_preparacion);
    free(juego->cocina.platos_listos);

    juego->cocina.platos_preparacion = NULL;
    juego->cocina.platos_listos = NULL;
}