#include <stdio.h>
#define MAX_AHORROS 256

const char JUSTIN = 'J';
const char ALEX = 'A';
const char MAX = 'M';
const char NINGUNO = 'N';

char ganador_ahorrista(int ahorros[MAX_AHORROS], int tope_ahorros) {
    int ahorros_justin = 0;
    int ahorros_alex = 0;
    int ahorros_max = 0;

    if (tope_ahorros == 0){
        return NINGUNO;
    }

    for (int i = 0; i < tope_ahorros; i++){
        int ahorro_dia = ahorros[i];

        if ((i + 1) % 2 == 0){
            if (ahorro_dia > ahorros_alex){
                ahorros_alex = ahorro_dia;
            }
        } else if (((i + 1) % 2 != 0) && ((i + 1) % 5 == 0)){
            if (ahorro_dia > ahorros_justin){
                ahorros_justin = ahorro_dia;
            }
        } else {
            if (ahorro_dia > ahorros_max){
                ahorros_max = ahorro_dia;
            }
        }
    }

    if (ahorros_alex > ahorros_justin && ahorros_alex > ahorros_max){
        return ALEX;
    } else if (ahorros_justin > ahorros_alex && ahorros_justin > ahorros_max){
        return JUSTIN;
    } else if (ahorros_max > ahorros_alex && ahorros_max > ahorros_justin){
        return MAX;
    } else return NINGUNO;
}