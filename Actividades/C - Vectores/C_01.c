#include <stdio.h>
#include "solucion.h"

const char ANTIDOTO = 'A';

int posicion_antidoto(char pociones[MAX_POCIONES], int tope_pociones) {
	for (int i = 0; i < tope_pociones; i++){
		if (pociones[i] == ANTIDOTO){
			return i;
		}
	}
	return -1;
}