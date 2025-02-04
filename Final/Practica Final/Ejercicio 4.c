#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define MAX_COLOR 15
#define MAX_TRAJES 20
const char *ROJO = "ROJO";

typedef struct supertraje
{
    int antiguedad;
    char color[MAX_COLOR];
    bool es_ganador;
} supertraje_t;

// PRE: 'indice' debe estar inicializado en cero y 'tope_trajes' inicializado correctamente.
// POST: Devuelve el indice del vector 'supertrajes' cuya antiguedad sea la menor y 'color' sea 'ROJO'.
int posicion_traje_nuevo(supertraje_t supertrajes[MAX_TRAJES], int tope_trajes, int *antiguedad_record, int *indice_record, int indice)
{
    if (indice == 0)
    {
        *antiguedad_record = supertrajes[indice].antiguedad;
        *indice_record = 0;
    }
    if (indice == tope_trajes)
        return *indice_record;

    if (strcmp(supertrajes[indice].color, ROJO) == 0 && supertrajes[indice].antiguedad < *antiguedad_record)
    {
        *antiguedad_record = supertrajes[indice].antiguedad;
        *indice_record = indice;
    }

    return posicion_traje_nuevo(supertrajes, tope_trajes, antiguedad_record, indice_record, indice + 1);
}

int main()
{
    return 0;
}

/*
----- PARTE TEÓRICA -----
1- ¿Qué elementos debe tener una función recursiva?
2- ¿Qué tipo de dato es el campo color del struct supertraje? ¿Qué particularidad tieneese tipo de dato?

1- Una función recursiva se caracteriza por estar dividida en tres partes:
    - Condición corte: especifica el momento en que la función deja de llamarse a sí misma y se devuelve un valor, deteniendo así la recursión;
    - Procesamiento: realiza una operación sobre los datos, modificándolos de manera que permita alcanzar eventualmente la condición de corte;
    - Llamada recursiva: invoca la misma función, pasando como parámetros los valores necesarios para seguir con el procesamiento y acercarse a la condición de corte.
2- El campo 'color' es de tipo string, que representa una secuencia de caracteres. La particularidad de este tipo de dato es que termina con un carácter especial '\0', el cual indica el fin de la cadena.
*/