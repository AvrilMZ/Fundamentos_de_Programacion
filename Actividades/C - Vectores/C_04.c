#include <stdio.h>
#include <stdbool.h>
#define MAX_RESPUESTAS 300

#define JUSTIN_SI 'J'
#define MAX_SI 'M'
#define AMBOS_SI 'S'
#define AMBOS_NO 'N'
const char LIBRA = 'L';
const char PISCIS = 'P';
const char ACUARIO = 'A';
const char CANCER = 'C';

bool tienen_mismo_signo(char respuestas[MAX_RESPUESTAS], int tope_respuestas) {
    int respuestas_positivas_justin = 0;
    int respuestas_positivas_max = 0;
    char signo_justin = 'Z';
    char signo_max = 'Z';

    for (int i = 0; i < tope_respuestas; i++){
        switch (respuestas[i]){
            case JUSTIN_SI:
                respuestas_positivas_justin += 1;
                break;
            case MAX_SI:
                respuestas_positivas_max += 1;
                break;
            case AMBOS_SI:
                respuestas_positivas_justin += 1;
                respuestas_positivas_max += 1;
                break;
            case AMBOS_NO:
                break;
        }
    }
    
    if (respuestas_positivas_justin >= 0 && respuestas_positivas_justin <= 2){
        signo_justin = LIBRA;
    } else if (respuestas_positivas_justin >= 3 && respuestas_positivas_justin <= 5){
        signo_justin = PISCIS;
    } else if (respuestas_positivas_justin >= 6 && respuestas_positivas_justin <= 8){
        signo_justin = ACUARIO;
    } else signo_justin = CANCER;

    if (respuestas_positivas_max >= 0 && respuestas_positivas_max <= 2){
        signo_max = LIBRA;
    } else if (respuestas_positivas_max >= 3 && respuestas_positivas_max <= 5){
        signo_max = PISCIS;
    } else if (respuestas_positivas_max >= 6 && respuestas_positivas_max <= 8){
        signo_max = ACUARIO;
    } else signo_max = CANCER;

    return signo_justin == signo_max;
}