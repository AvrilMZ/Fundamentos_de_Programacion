#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define MAX_JUGUETES 200
#define MAX_NOMBRE 144

typedef struct jueguete{
    char nombre[MAX_NOMBRE];
    bool guardado;
} juguete_t;

void agregar_juguete(juguete_t juguetes[MAX_JUGUETES], int* tope_juguetes, char nombre[MAX_NOMBRE]){
    
}