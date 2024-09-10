#include <stdio.h>

const char MIEL = 'H';
const char VACIA = 'V';

void mezclar_cajas(char* primer_caja, char* segunda_caja, char* tercera_caja) {
    if (*primer_caja == MIEL){
        *primer_caja = VACIA;
        *tercera_caja = MIEL;
    } else if (*segunda_caja == MIEL){
        *segunda_caja = VACIA;
        *primer_caja = MIEL;
    } else if (*tercera_caja == MIEL){
        *tercera_caja = VACIA;
        *segunda_caja = MIEL; 
    }
}
    