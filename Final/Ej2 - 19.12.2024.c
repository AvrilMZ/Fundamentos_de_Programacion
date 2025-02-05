#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define MAX_FILAS 10
#define MAX_COLUMNAS 10
#define MAX_LUGARES 20
const char* CASA = "casa";
const int MAX_PORTALES = 20;

typedef struct portal {
    int col_siguiente;
    int fila_siguiente;
    bool es_seguro;
    char nombre_lugar[MAX_LUGARES];
} portal_t;

// PRE: 'fila' y 'columna' deben ser cero inicialmente y 'portales' debe estar inicializado.
// POST: Devuelve true si en una cantidad de 'MAX_PORTALES' encontraron recursivamente una posicion de 'portales' cuyo 'nombre_lugar' sea igual a 'CASA', de lo contrario devuelve false.
bool pudieron_volver(portal_t portales[MAX_FILAS][MAX_COLUMNAS], int fila, int columna, int* nro_portal, bool* encontraron_casa) {
    if (*nro_portal == MAX_PORTALES && !(*encontraron_casa)) return false;
    else if (*encontraron_casa) return true;

    if (fila == 0 && columna == 0) {
        *nro_portal = 1;
        *encontraron_casa = false;
    }
    if (strcmp(portales[fila][columna].nombre_lugar, CASA) == 0) *encontraron_casa = true;

    return pudieron_volver(portales, portales[fila][columna].fila_siguiente, portales[fila][columna].col_siguiente, (*nro_portal) + 1, encontraron_casa);
}

/*
----- PARTE TEÓRICA -----
1- ¿Cuáles son los elementos de una función recursiva?
2- ¿Qué diferencias hay a la hora de trabajar con un vector o con un archivo?

1- Los elementos de una función recursiva son: 
    - Condición corte: Establece al inicio de la funcion los objetivos para el cual la funcion deba devolver un valor y no seguir iterando recursivamente.
    - Procesamiento: Se aclaran los cambios que se deben hacer en las variables en cada pasada.
    - Llamada recursiva: Se llama a la propia funcion pasandole por paramentro valores distintos a los ingresados anteriormente.
2- Difrencias:
    Archivo: - Posibilidad de que datos perduren en el tiempo.
             - Riesgo de que queden abiertos consumiendo recursos.
             - Eficiente para una gran cantidad de datos.
    Vector: - Mayor facilidad de iterar entre sus elementos.
            - En caso de ser dinamico, no hay desperdicio de memoria.
*/