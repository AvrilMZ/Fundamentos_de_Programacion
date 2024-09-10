#include <stdio.h>

const char FRENTE = 'F';
const char REVERSO = 'R';
const char VACIO = 'V';

void corregir_posicion_papel_higienico(char* posicion) {
    if (*posicion == REVERSO){
        *posicion = FRENTE; /*Hay q cambiar el valor por referencia*/
    }
}
