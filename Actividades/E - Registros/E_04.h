#include <stdio.h>
#include "solucion.h"

const int PROBABILIDAD_INICIAL = 5;
const int MENSAJE_LARGO = 50;
const int MUCHAS_RESPUESTAS = 3;

typedef struct mensaje {
    bool tiene_palabras_de_colegio;
    int cantidad_de_palabras;
    int cantidad_de_respuestas;
    bool autor_sospechoso;
} mensaje_t;

int indice_de_probabilidad_de_copia(mensaje_t mensaje){
    int probabilidad_copia = PROBABILIDAD_INICIAL;
    if (mensaje.tiene_palabras_de_colegio == true) probabilidad_copia += 2;
    else probabilidad_copia -= 2;

    if (mensaje.cantidad_de_palabras > MENSAJE_LARGO) probabilidad_copia += 2;
    else probabilidad_copia--;

    if (mensaje.cantidad_de_respuestas > 3) probabilidad_copia += 2;

    if (mensaje.autor_sospechoso == true) probabilidad_copia += 3;
    else probabilidad_copia--;

    return probabilidad_copia;
}