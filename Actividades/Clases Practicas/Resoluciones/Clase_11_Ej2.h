#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct mascota {
    char animal;
    int edad;
} mascota_t;

struct vector_din;
typedef vector_din vector_din_t;

/* POST: - Crea un vector dinámico de mascotas. Devuelve un puntero a un vector vacío.
         - Al terminar de usarlo este vector debe ser destruido con vec_destruir().
         - Devuelve NULL si no se pudo crear el vector.*/
vector_din_t* vec_crear();

/* PRE: 'vec' fue creado usando 'vec_crear()'.
   POST: Dedinuye el vector.*/
void vec_destruir(vector_din_t* vec);

/* PRE: 'vec' fue creado usando 'vec_crear()'.
   POST: - Agrega una mascota al final del vector.
         - Devuelve true si se pudo agregar, false en caso contrario.*/
bool vec_guardar(vector_din_t* vec, mascota_t mascota);

/* PRE: 'vec' fue creado usando 'vec_crear()'.
   POST: - Devuelve un puntero elemento en la posición 'pos' del vector.
         - Si 'pos' es inválida, devuelve NULL.
         - Una posición es inválida si es mayor o igual al largo del vector.*/
mascota_t* vec_obtener(vector_din_t* vec, size_t pos);

/* PRE: 'vec' fue creado usando 'vec_crear()'.
   POST: Devuelve la cantidad de elementos en el vector.*/
size_t vec_largo(vector_din_t* vec);

/* PRE: 'vec' fue creado usando 'vec_crear()'.
   POST: Imprime los elementos del vector en orden.*/
void vec_imprimir(vector_din_t* vec);

/* PRE: 'vec' fue creado usando 'vec_crear()'.
   POST: - Elimina el elemento del vector en la posición deseada 'pos' reduciendo su largo.
         - Todos los elementos a la derecha de 'pos' se desplazan una posición a la izquierda.
         - Si 'pos' es inválida, no hace nada.*/
void vec_eliminar(vector_din_t* vec, size_t pos);