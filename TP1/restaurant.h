#ifndef __RESTAURANT_H__
#define __RESTAURANT_H__

#include <stdbool.h>

#define MAX_COMENSALES 4
#define MAX_POSICION 9
#define MAX_DESCRIPCION 50
#define MAX_PLATOS 10
#define MAX_PEDIDOS 10
#define MAX_BANDEJA 10
#define MAX_HERRAMIENTAS 20
#define MAX_OBSTACULOS 20
#define MAX_MESAS 20

#define MAX_FILAS 20
#define MAX_COLUMNAS 20

typedef struct coordenada {
    int fil;
    int col;
} coordenada_t;

typedef struct pedido {
    int id_mesa;
    char platos[MAX_PLATOS];
    int cantidad_platos;
    int tiempo_preparacion;
} pedido_t;

typedef struct cocina {
    coordenada_t posicion;
} cocina_t;

typedef struct mozo {
    coordenada_t posicion;
    int cantidad_patines;
    pedido_t pedidos[MAX_PEDIDOS];
    int cantidad_pedidos;
    pedido_t bandeja[MAX_BANDEJA];
    int cantidad_bandeja;
    bool tiene_mopa;
    bool patines_puestos;
} mozo_t;

typedef struct mesa {
    coordenada_t posicion[MAX_POSICION];
    int cantidad_lugares;
    int cantidad_comensales;
    int paciencia;
    bool pedido_tomado;
} mesa_t;

typedef struct objeto {
    char tipo;
    coordenada_t posicion;
} objeto_t;

typedef struct juego {
    cocina_t cocina;
    mozo_t mozo;
    mesa_t mesas[MAX_MESAS];
    int cantidad_mesas;
    objeto_t herramientas[MAX_HERRAMIENTAS];
    int cantidad_herramientas;
    objeto_t obstaculos[MAX_OBSTACULOS];
    int cantidad_obstaculos;
    int movimientos;
    int dinero;
} juego_t;

// POST: Inicializará el juego, cargando toda la información inicial de Linguini, las mesas, las herramientas y los obstáculos.
void inicializar_juego(juego_t *juego);

/* PRE: - El juego debe estar inicializado previamente con `inicializar_juego`;
        - 'acción' debe ser válida.
   POST: Realizará la acción recibida por parámetro.*/
void realizar_jugada(juego_t *juego, char accion);

/* PRE: El juego debe estar inicializado previamente con `inicializar_juego`.
   POST: Imprime el juego por pantalla.*/
void mostrar_juego(juego_t juego);

/* PRE: El juego deberá estar inicializado previamente con `inicializar_juego`
   POST: - Devuelve: 1 si es ganado, -1 si es perdido, 0 si se sigue jugando;
         - El juego se dará por ganado cuando se termina el día y se consiguieron las monedas necesarias;
         - Se dará por perdido si se termina el día y no se llegó al monto.*/
int estado_juego(juego_t juego);

#endif /* __RESTAURANT_H__ */