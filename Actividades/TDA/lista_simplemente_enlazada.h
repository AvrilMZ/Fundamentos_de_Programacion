#ifndef LISTA_SIMPLEMENTE_ENLAZADA_H
#define LISTA_SIMPLEMENTE_ENLAZADA_H

#include <stdbool.h>

typedef struct nodo {
    int dato;
    struct nodo *siguiente;
} nodo_t;

typedef struct {
    nodo_t *primero;
    int cantidad;
} lista_t;

// PRE: -
// POST: Crea una lista vacía.
lista_t *create();

// PRE: 'lista' debe estar inicializada correctamente.
// POST: Devuelve true si la lista está vacía, false en caso contrario.
bool is_empty(lista_t *lista);

// PRE: 'lista' debe estar inicializada correctamente.
// POST: Devuelve la cantidad de elementos en la lista.
int size(lista_t *lista);

// PRE: 'lista' debe estar inicializada correctamente.
// POST: Agrega un elemento al principio de la lista.
void push(lista_t *lista, int valor);

// PRE: 'lista' debe estar inicializada correctamente, posicion mayor o igual a cero y menor a su máximo.
// POST: Inserta un elemento en una posición específica.
bool insert_at(lista_t *lista, int posicion, int valor);

// PRE: 'lista' debe estar inicializada correctamente.
/* POST: - Si la lista no estaba vacía, el último elemento es eliminado y se reduce el tamaño en 1;
         - Si la lista estaba vacía, no se modifica y se devuelve -1.*/
int remove(lista_t *lista);

// PRE: 'lista' debe estar inicializada correctamente, posicion mayor o igual a cero y menor a su máximo.
// POST: Elimina un elemento en la posición específica.
bool remove_at(lista_t *lista, int posicion);

// PRE: 'lista' debe estar inicializada correctamente, posicion mayor o igual a cero y menor a su máximo.
// POST: Devuelve el valor en la posición dada.
int get_at(lista_t *lista, int posicion);

// PRE: 'lista' debe estar inicializada correctamente y no vacía.
// POST: Devuelve el último elemento de la lista.
int get_last(lista_t *lista);

// PRE: 'lista' debe estar inicializada correctamente.
// POST: Destruye la lista y libera su memoria.
void destroy(lista_t *lista);

#endif