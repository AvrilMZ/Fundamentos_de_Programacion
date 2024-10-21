/*Maggie, Grace, y la Sra. Calloway están necesitando $750 para saldar la deuda que Pearl Gesner, la dueña de la granja, tiene con el banco, y así evitar que la granja sea rematada. Es por esto que por el último mes han estado ahorrando dinero día por día, anotando lo que juntan en un vector. Se pide:

Implementar una función que dado un vector de ahorros y su tope, devuelva true si son capaces de saldar la deuda con el banco, o false en caso contrario.*/

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