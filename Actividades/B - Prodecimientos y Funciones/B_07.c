/*Baloo y Bagheera están apostando parte de sus reservas favoritas de frutas en adivinar cuántas frutas recolectará Mowgli en el día. El que gana se lleva 10 frutas del que pierde, y si hay empate las reservas de ambos están a salvo.

Implementar una función que dadas las reservas de Baloo, las de Bagheera y la cantidad de frutas que trajo Mowgli en el día modifique ambas reservas según corresponda. Tener en cuenta que:
Si Mowgli trajo más de 10 frutas, Baloo le da 10 frutas a Bagheera.
Si Mowgli trajo menos de 10 frutas, Bagheera le da 10 frutas a Baloo.
Si trajo exactamente 10 frutas, entonces no pasa nada.*/

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