#include "lista_simplemente_enlazada.h"
#include <stdlib.h>

// PRE: -
// POST: Crea una lista vacía.
lista_t *create() {
    lista_t *lista = malloc(sizeof(lista_t));
    if (!lista) return NULL;

    lista->primero = NULL;
    lista->cantidad = 0;
    return lista;
}

// PRE: 'lista' debe estar inicializada correctamente.
// POST: Devuelve true si la lista está vacía, false en caso contrario.
bool is_empty(lista_t *lista) {
    return lista->cantidad == 0;
}

// PRE: 'lista' debe estar inicializada correctamente.
// POST: Devuelve la cantidad de elementos en la lista.
int size(lista_t *lista) {
    return lista->cantidad;
}

// PRE: 'lista' debe estar inicializada correctamente.
// POST: Agrega un elemento al principio de la lista.
void push(lista_t *lista, int valor) {
    nodo_t *nuevo = malloc(sizeof(nodo_t));
    if (!nuevo) return;

    nuevo->dato = valor;
    nuevo->siguiente = lista->primero;
    lista->primero = nuevo;
    lista->cantidad++;
}

// PRE: 'lista' debe estar inicializada correctamente, posicion mayor o igual a cero y menor a su máximo.
// POST: Inserta un elemento en una posición específica.
bool insert_at(lista_t *lista, int pos, int valor) {
    if (pos < 0 || pos > lista->cantidad) return false;

    if (pos == 0) {
        push(lista, valor);
        return true;
    }

    nodo_t *actual = lista->primero;
    for (int i = 0; i < pos - 1; i++) {
        actual = actual->siguiente;
    }

    nodo_t *nuevo = malloc(sizeof(nodo_t));
    if (!nuevo) return false;

    nuevo->dato = valor;
    nuevo->siguiente = actual->siguiente;
    actual->siguiente = nuevo;
    lista->cantidad++;

    return true;
}

// PRE: 'lista' debe estar inicializada correctamente.
/* POST: - Si la lista no estaba vacía, el último elemento es eliminado y se reduce el tamaño en 1;
         - Si la lista estaba vacía, no se modifica y se devuelve -1.*/
int remove(lista_t *lista) {
    if (is_empty(lista)) return -1;

    nodo_t *actual = lista->primero;
    nodo_t *anterior = NULL;

    while (actual->siguiente) {
        anterior = actual;
        actual = actual->siguiente;
    }

    if (!anterior) lista->primero = NULL;
    else anterior->siguiente = NULL;

    free(actual);
    lista->cantidad--;
    return 0;
}

// PRE: 'lista' debe estar inicializada correctamente, posicion mayor o igual a cero y menor a su máximo.
// POST: Elimina un elemento en la posición específica.
bool remove_at(lista_t *lista, int pos) {
    if (pos < 0 || pos >= lista->cantidad) return false;

    nodo_t *actual = lista->primero, *anterior = NULL;

    for (int i = 0; i < pos; i++) {
        anterior = actual;
        actual = actual->siguiente;
    }

    if (!anterior) lista->primero = actual->siguiente;
    else anterior->siguiente = actual->siguiente;

    free(actual);
    lista->cantidad--;
    return true;
}

// PRE: 'lista' debe estar inicializada correctamente, posicion mayor o igual a cero y menor a su máximo.
// POST: Devuelve el valor en la posición dada.
int get_at(lista_t *lista, int pos) {
    if (pos < 0 || pos >= lista->cantidad) return -1;

    nodo_t *actual = lista->primero;
    for (int i = 0; i < pos; i++) {
        actual = actual->siguiente;
    }
    return actual->dato;
}

// PRE: 'lista' debe estar inicializada correctamente y no vacía.
// POST: Devuelve el último elemento de la lista.
int get_last(lista_t *lista) {
    if (is_empty(lista)) return -1;

    nodo_t *actual = lista->primero;
    while (actual->siguiente) {
        actual = actual->siguiente;
    }
    return actual->dato;
}

// PRE: 'lista' debe estar inicializada correctamente.
// POST: Destruye la lista y libera su memoria.
void destroy(lista_t *lista) {
    nodo_t *actual = lista->primero;
    while (actual) {
        nodo_t *temp = actual;
        actual = actual->siguiente;
        free(temp);
    }
    free(lista);
}