#include <stdio.h>
#include <stdbool.h>

const int NOTA_MINIMA = 1;
const int NOTA_MINIMA_APROBADA = 4;
const int NOTA_MAXIMA = 10;
const char ENCANTO = 'E';
const char BIEN = 'B';
const char ODIO = 'O';
const char NO_HECHA = 'N';

/* PRE: -
   POST: Devuelve true si 'nota' esta entre 'NOTA_MAXIMA' y 'NOTA_MINIMA' inclusive, de lo contrario, devuelve false.*/
bool es_nota_valida(int nota) {
    return (nota <= NOTA_MAXIMA && nota >= NOTA_MINIMA);
}

/* PRE: -
   POST: Devuelve true si 'opinion' es alguna de las opciones validas, de lo contrario, devuelve false.*/
bool es_opinion_valida(char opinion) {
    return (opinion == ENCANTO || opinion == BIEN || opinion == ODIO || opinion == NO_HECHA);
}

/* PRE: -
   POST: Devuelve true si 'nota' esta entre 'NOTA_MAXIMA' y 'NOTA_MINIMA_APROBADA' inclusive, de lo contrario, devuelve false.*/
bool es_nota_aprobada(int nota) {
    return (nota <= NOTA_MAXIMA && nota >= NOTA_MINIMA_APROBADA);
}

/* PRE: 'nota' debe estar inicializado en un valor fuera del rango válido.
   POST: Actualiza el valor de 'nota', de ser válido, por el ingresado por el usuario.*/
void preguntar_nota_fisica(int* nota) {
    while (!es_nota_valida(*nota)) {
        printf("¿Qué nota obtuvo en fisica? (Debe ser una nota entre %i y %i)\n", NOTA_MINIMA, NOTA_MAXIMA);
        scanf("%i", nota);
    }
}

/* PRE: 'opinion' debe estar inicializado en un valor fuera del rango válido.
   POST: Actualiza el valor de 'opinion', de ser válido, por el ingresado por el usuario.*/
void preguntar_opinion_fisica(char* opinion) {
    while (!es_opinion_valida(*opinion)) {
        printf("¿Qué opinion tiene de fisica? (Ingrese '%c', '%c', '%c' ó '%c')\n", ENCANTO, BIEN, ODIO, NO_HECHA);
        scanf(" %c", opinion);
    }
}

/* PRE: -
   POST: Devuelve true si 'nota' es aprobada y si 'opinion' es 'ENCANTO' o 'BIEN', de lo contrario, devuelve false.*/
bool esta_colaborador_contento(int nota, char opinion) {
    return (es_nota_aprobada(nota) && (opinion == ENCANTO || opinion == BIEN));
}

int main() {
    int nota_fisica = -1;
    char opinion_fisica = ' ';
    preguntar_nota_fisica(&nota_fisica);
    preguntar_opinion_fisica(&opinion_fisica);
    if (esta_colaborador_contento(nota_fisica, opinion_fisica)) printf("¡Al colaborador le gusta la idea!\n");
    else printf("Al colaborador no le gusta la idea :(\n");

    return 0;
}