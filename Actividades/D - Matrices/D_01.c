#include <stdio.h>
#define MAX_TERRENO 10

const char MANCUERNAS = 'M';

void inicializar_gimnasio(char gimnasio[MAX_TERRENO][MAX_TERRENO]) {
	for (int i = 0; i < MAX_TERRENO; i++){
        for (int j = 0; j < MAX_TERRENO; j++){
            gimnasio[i][j] = MANCUERNAS;
        }
    }
}