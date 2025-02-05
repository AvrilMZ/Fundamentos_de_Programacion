#ifndef COLA_H
#define COLA_H

#include <stdbool.h>

typedef struct {
    int *datos;
    int frente;
    int final;
    int capacidad;
    int cantidad;
} cola_t;

// PRE: 'capacidad' debe ser mayor a cero.
// POST: Crea una cola vacía con una 'capacidad' inicial.
cola_t *create(int capacidad);

// PRE: 'cola' debe estar inicializada correctamente.
// POST: Devuelve true si la cola está vacía, false en caso contrario.
bool is_empty(cola_t *cola);

// PRE: 'cola' debe estar inicializada correctamente.
// POST: Encola un elemento si hay espacio.
bool enqueue(cola_t *cola, int valor);

// PRE: 'cola' debe estar inicializada correctamente y no vacía.
// POST: Desencola un elemento y lo guarda en 'valor'.
bool dequeue(cola_t *cola, int *valor);

// PRE: 'cola' debe estar inicializada correctamente y no vacía.
// POST: Devuelve el primer elemento sin desencolarlo.
int first(cola_t *cola);

// PRE: 'cola' debe estar inicializada correctamente.
// POST: Destruye la cola y libera su memoria.
void destroy(cola_t *cola);

#endif