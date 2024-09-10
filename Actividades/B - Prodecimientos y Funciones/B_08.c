#include <stdio.h>

#define VERANO 'V'
#define OTOÑO 'O'
#define INVIERNO 'I'
#define PRIMAVERA 'P'
#define CONTENTO 'C'
#define MEH 'M'
#define TRISTE 'T'

int definir_humor_osos(char* humor_harris, char* humor_hubert, char* humor_hamish, char estacion){
    int cantidad_contentos = 0;
    
    switch (estacion) {
        case VERANO:
            *humor_hamish = TRISTE;
            *humor_harris = MEH;
            *humor_hubert = CONTENTO;
            cantidad_contentos = 1;
            break;
        case OTOÑO:
            *humor_hamish = CONTENTO;
            *humor_harris = CONTENTO;
            *humor_hubert = CONTENTO;
            cantidad_contentos = 3;
            break;
        case INVIERNO:
            *humor_hamish = CONTENTO;
            *humor_harris = MEH;
            *humor_hubert = TRISTE;
            cantidad_contentos = 1;
            break;
        case PRIMAVERA:
            *humor_hamish = MEH;
            *humor_harris = CONTENTO;
            *humor_hubert = CONTENTO;
            cantidad_contentos = 2;
            break;
    }

    return cantidad_contentos;
}