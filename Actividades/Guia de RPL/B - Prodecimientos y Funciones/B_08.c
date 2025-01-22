/*Los hermanos de Mérida (Harris, Hubert y Hamish) atraviesan varios cambios de humor a lo largo de un año según las estaciones. Según su hermana, por cada estación cada uno pasa por un humor diferente:
Primavera (P): Harris y Hubert están contentos, mientras que Hamish está meh.
Verano (V): Hamish está triste, Harris está meh y Hubert está contento.
Otoño (O): los tres hermanos están contentos (obvio, si es la mejor estación).
Invierno (I): Hamish está contento, Harris está meh y Hubert está triste.

Implementar una función que dada la estación del año modifiqué el humor de cada hermano al correspondiente, y devuelva la cantidad de hermanos que están contentos.
Tener en cuenta que cada humor está representado por un caracter:
Contento (C)
Meh (M)
Triste (T)*/

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