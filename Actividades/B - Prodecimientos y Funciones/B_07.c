#include <stdio.h>

const int PREMIO = 10;

void realizar_apuesta(int* reserva_bagheera, int* reserva_baloo, int frutas_mowgli) {
    if (*reserva_bagheera < 10){
        *reserva_baloo += *reserva_bagheera;
        *reserva_bagheera = 0;
    } else if (*reserva_baloo < 10){
        *reserva_bagheera += *reserva_baloo;
        *reserva_bagheera = 0;
    } else {
        if (frutas_mowgli > 10){
            *reserva_baloo -= PREMIO;
            *reserva_bagheera += PREMIO;
        } else if (frutas_mowgli < 10){
            *reserva_bagheera -= PREMIO;
            *reserva_baloo += PREMIO;
        }
    }
}