#include <stdio.h>
#include <stdbool.h>
#define MAX_ALIMENTOS 400
#define MAX_NOMBRE 144

typedef struct alimento {
    char nombre[MAX_NOMBRE];
    bool vencio;
    int puntos_mal_olor;
} alimento_t;

int cantidad_alimentos_echados_a_perder(alimento_t alimentos[MAX_ALIMENTOS], int tope){
    
}