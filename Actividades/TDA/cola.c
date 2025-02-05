#include "cola.h"
#include <stdlib.h>

// PRE: 'capacidad' debe ser mayor a cero.
// POST: Crea una cola vacía con una 'capacidad' inicial.
cola_t *create(int capacidad) {
    if (capacidad <= 0) return NULL;

    cola_t *cola = malloc(sizeof(cola_t));
    if (!cola) return NULL;

    cola->datos = malloc(capacidad * sizeof(int));
    if (!cola->datos) {
        free(cola);
        return NULL;
    }

    cola->frente = 0;
    cola->final = 0;
    cola->capacidad = capacidad;
    cola->cantidad = 0;

    return cola;
}

// PRE: 'cola' debe estar inicializada correctamente.
// POST: Devuelve true si la cola está vacía, false en caso contrario.
bool is_empty(cola_t *cola) {
    return cola->cantidad == 0;
}

// PRE: 'cola' debe estar inicializada correctamente.
// POST: Encola un elemento si hay espacio.
bool enqueue(cola_t *cola, int valor) {
    if (cola->cantidad == cola->capacidad) return false;

    cola->datos[cola->final] = valor;
    cola->final = (cola->final + 1) % cola->capacidad;
    cola->cantidad++;
    return true;
}

// PRE: 'cola' debe estar inicializada correctamente y no vacía.
// POST: Desencola un elemento y lo guarda en 'valor'.
bool dequeue(cola_t *cola, int *valor) {
    if (is_empty(cola)) return false;

    *valor = cola->datos[cola->frente];
    cola->frente = (cola->frente + 1) % cola->capacidad;
    cola->cantidad--;
    return true;
}

// PRE: 'cola' debe estar inicializada correctamente y no vacía.
// POST: Devuelve el primer elemento sin desencolarlo.
int first(cola_t *cola) {
    if (is_empty(cola)) return -1;
    return cola->datos[cola->frente];
}

// PRE: 'cola' debe estar inicializada correctamente.
// POST: Destruye la cola y libera su memoria.
void destroy(cola_t *cola) {
    free(cola->datos);
    free(cola);
}