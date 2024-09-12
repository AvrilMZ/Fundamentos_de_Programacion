#include <stdio.h>
#include <stdbool.h>
#define MAX_AHORROS 31

const int DEUDA = 750;

bool se_salda_la_deuda(int ahorros[MAX_AHORROS], int tope_ahorros) {
    int plata_ahorrada = 0;
	for (int i = 0; i < tope_ahorros; i++){
        plata_ahorrada += ahorros[i];
    }

    if (plata_ahorrada >= DEUDA){
        return true;
    } else return false;
}