#ifndef PILA_H
#define PILA_H

#include <stdbool.h>

typedef struct {
    int *datos;
    int tope;
    int capacidad;
} pila_t;

// PRE: 'capacidad_inicial' debe ser mayor a cero.
// POST: Crea una pila vacía con una 'capacidad inicial'.
pila_t *create(int capacidad_inicial);

// PRE: 'pila' debe estar inicializada correctamente.
// POST: Devuelve true si la pila está vacía, false en caso contrario.
bool is_empty(pila_t *pila);

// PRE: 'pila' debe estar inicializada correctamente.
// POST: Agrega un elemento a la pila, redimensionando si es necesario.
bool push(pila_t *pila, int valor);

// PRE: 'pila' debe estar inicializada correctamente y no vacía.
// POST: Elimina el elemento en el tope de la pila y lo guarda en 'valor'.
bool pop(pila_t *pila, int *valor);

// PRE: 'pila' debe estar inicializada correctamente y no vacia.
// POST: Devuelve el valor en el tope sin desapilarlo.
int top(pila_t *pila);

// PRE: 'pila' debe estar inicializada correctamente.
// POST: Libera la memoria de la pila.
void destroy(pila_t *pila);

#endif