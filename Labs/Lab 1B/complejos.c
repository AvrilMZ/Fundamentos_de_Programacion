#include <stdio.h>
#include "complejos.h"

//PRE: -
//POST: Imprime la suma de los dos números complejos.
void suma_complejos(complejo_t complejo1, complejo_t complejo2){
    int suma_real = complejo1.parte_real + complejo2.parte_real;
    int suma_imaginaria = complejo1.parte_imaginaria + complejo2.parte_imaginaria;
    printf("Suma: %i + %ii\n", suma_real, suma_imaginaria);
}

//PRE: -
//POST: Imprime la resta de los dos números complejos.
void resta_complejos(complejo_t complejo1, complejo_t complejo2){
    int resta_real = complejo1.parte_real - complejo2.parte_real;
    int resta_imaginaria = complejo1.parte_imaginaria - complejo2.parte_imaginaria;
    printf("Resta: %i + %ii\n", resta_real, resta_imaginaria);
}

//PRE: -
//POST: Imprime la parte real del número complejo.
void parte_real(complejo_t complejo){
    printf("Parte Real: %i\n", complejo.parte_real);
}

//PRE: -
//POST: Imprime la parte imaginaria del número complejo.
void parte_imaginaria(complejo_t complejo){
    printf("Parte Imaginaria: %ii\n", complejo.parte_imaginaria);
}