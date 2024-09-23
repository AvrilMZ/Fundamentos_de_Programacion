#include <stdio.h>
#define MAX_NUMEROS 100

const char PROGRAMA_SIN_NOMBRE = '-';

int numero_mas_chico(int numeros[MAX_NUMEROS], int tope_numeros) {
    if (tope_numeros == 0) return -1;

    int indice_numero_menor = 0;
    for (int i = 0; i < tope_numeros; i++){
        if (numeros[i] < numeros[indice_numero_menor]){
            indice_numero_menor = i;
        }
    }
    return indice_numero_menor;
}

char programa_ganador(char programas[MAX_NUMEROS], int tope_programas, int numeros[MAX_NUMEROS], int tope_numeros) {
    if (tope_programas == 0 || tope_numeros == 0){
        return PROGRAMA_SIN_NOMBRE;
    }
    
    int indice_numero_menor = numero_mas_chico(numeros, tope_numeros);
    if (indice_numero_menor < 0 || indice_numero_menor >= tope_programas){
        return PROGRAMA_SIN_NOMBRE;
    } else return programas[indice_numero_menor];
}