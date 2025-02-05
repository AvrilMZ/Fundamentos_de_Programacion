#include "pila.h"
#include <stdlib.h>

#define CAPACIDAD_INICIAL 10

// PRE: 'capacidad_inicial' debe ser mayor a cero.
// POST: Crea una pila vacía con una 'capacidad inicial'.
pila_t *create(int capacidad_inicial) {
    if (capacidad_inicial <= 0) return NULL;

    pila_t *pila = malloc(sizeof(pila_t));
    if (!pila) return NULL;

    pila->datos = malloc(capacidad_inicial * sizeof(int));
    if (!pila->datos) {
        free(pila);
        return NULL;
    }

    pila->tope = -1;
    pila->capacidad = capacidad_inicial;
    return pila;
}

// PRE: 'pila' debe estar inicializada correctamente.
// POST: Devuelve true si la pila está vacía, false en caso contrario.
bool is_empty(pila_t *pila) {
    return pila->tope == -1;
}

// PRE: 'pila' debe estar inicializada correctamente.
// POST: Agrega un elemento a la pila, redimensionando si es necesario.
bool push(pila_t *pila, int valor) {
    if (pila->tope + 1 == pila->capacidad) {
        int nueva_capacidad = pila->capacidad * 2;
        int *nuevos_datos = realloc(pila->datos, nueva_capacidad * sizeof(int));
        if (!nuevos_datos) return false;

        pila->datos = nuevos_datos;
        pila->capacidad = nueva_capacidad;
    }

    pila->datos[++pila->tope] = valor;
    return true;
}

// PRE: 'pila' debe estar inicializada correctamente y no vacía.
// POST: Elimina el elemento en el tope de la pila y lo guarda en 'valor'.
bool pop(pila_t *pila, int *valor) {
    if (is_empty(pila)) return false;

    *valor = pila->datos[pila->tope--];
    return true;
}

// PRE: 'pila' debe estar inicializada correctamente y no vacia.
// POST: Devuelve el valor en el tope sin desapilarlo.
int top(pila_t *pila) {
    if (is_empty(pila)) return -1;
    return pila->datos[pila->tope];
}

// PRE: 'pila' debe estar inicializada correctamente.
// POST: Libera la memoria de la pila.
void destroy(pila_t *pila) {
    free(pila->datos);
    free(pila);
}
