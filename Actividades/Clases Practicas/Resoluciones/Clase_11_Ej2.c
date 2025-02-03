#include "Clase_11_Ej2.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct vector_din {
    size_t tope;
    mascota_t *mascotas;
};

/* POST: - Crea un vector dinámico de mascotas. Devuelve un puntero a un vector vacío.
         - Al terminar de usarlo este vector debe ser destruido con vec_destruir().
         - Devuelve NULL si no se pudo crear el vector.*/
vector_din_t* vec_crear() {
    vector_din_t* vector = malloc(sizeof(vector_din_t));
    if (vector == NULL) return NULL;

    vector->tope = 0;
    vector->mascotas = NULL;

    return vector;
}

/* PRE: 'vec' fue creado usando 'vec_crear()'.
   POST: Dedinuye el vector.*/
void vec_destruir(vector_din_t* vec) {
    if (vec == NULL) return;

    free(vec->mascotas);
    free(vec);
}

/* PRE: 'vec' fue creado usando 'vec_crear()'.
   POST: - Agrega una mascota al final del vector.
         - Devuelve true si se pudo agregar, false en caso contrario.*/
bool vec_guardar(vector_din_t* vec, mascota_t mascota) {
    if (vec == NULL) return false;

    if(vec->mascotas == NULL) {
        vec->mascotas = malloc(sizeof(mascota_t));
        if (vec->mascotas == NULL) return false;

        vec->mascotas[0] = mascota;
        vec->tope++;
    } else {
        vec->mascotas = realloc(vec->mascotas, sizeof(mascota_t) * ((vec->tope) + 1));
        if (vec->mascotas == NULL) return false;
        
        vec->mascotas[vec->tope] = mascota;
        vec->tope++;
    }
    return true;
}

/* PRE: 'vec' fue creado usando 'vec_crear()'.
   POST: - Devuelve un puntero elemento en la posición 'pos' del vector.
         - Si 'pos' es inválida, devuelve NULL.
         - Una posición es inválida si es mayor o igual al largo del vector.*/
mascota_t* vec_obtener(vector_din_t* vec, size_t pos) {
    if (vec == NULL || pos > vec->tope) return NULL;
    return &vec->mascotas[pos];
}

/* PRE: 'vec' fue creado usando 'vec_crear()'.
   POST: Devuelve la cantidad de elementos en el vector.*/
size_t vec_largo(vector_din_t* vec) {
    if (vec == NULL) return 0;
    return vec->tope;
}

/* PRE: 'vec' fue creado usando 'vec_crear()'.
   POST: Imprime los elementos del vector en orden.*/
void vec_imprimir(vector_din_t* vec) {
    if (vec == NULL || vec->mascotas == NULL) return;

    for (size_t i = 0; i < vec->tope; i++) {
        printf("%i: Es un %c con %i años de edad.\n", i, vec->mascotas[i].animal, vec->mascotas[i].edad);
    }
}

/* PRE: 'vec' fue creado usando 'vec_crear()'.
   POST: - Elimina el elemento del vector en la posición deseada 'pos' reduciendo su largo.
         - Todos los elementos a la derecha de 'pos' se desplazan una posición a la izquierda.
         - Si 'pos' es inválida, no hace nada.*/
void vec_eliminar(vector_din_t* vec, size_t pos) {
    if (vec == NULL || pos > vec->tope) return;

    for (size_t i = pos; i < vec->tope - 1; i++) {
        vec->mascotas[i] = vec->mascotas[i + 1];
    }
    vec->tope--;

    if (vec->tope == 0) {
        free(vec->mascotas);
        vec->mascotas = NULL;
    } else {
        mascota_t* nuevo = realloc(vec->mascotas, sizeof(mascota_t) * vec->tope);
        if (nuevo != NULL) vec->mascotas = nuevo;
    }
}

int main() {
    return 0;
}