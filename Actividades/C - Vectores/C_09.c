#include <stdio.h>
#define MAXIMOS_DESTINOS 100

int cantidad_de_picos(int alturas[MAXIMOS_DESTINOS], int tope){
    int picos = 0;
    for (int i = 1; i < tope - 1; i++){
        if (alturas[i] > alturas[i - 1] && alturas[i] > alturas[i + 1]){
                picos++;
        }
    }
    return picos;
}