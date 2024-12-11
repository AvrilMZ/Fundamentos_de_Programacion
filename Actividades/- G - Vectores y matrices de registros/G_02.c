/*Mabel y Dipper están planeando la fiesta de cumpleaños sorpresa del tío Stan, y por eso compraron muchos snacks, pero para que su tío no se dé cuenta, los escondieron en un baúl en el bosque cerca de la Cabaña del Misterio. Sin embargo Gideon, como enemigo jurado de la familia Pines, al enterarse de esto encontró el baúl e intercambió algunos snacks por snacks vencidos. Sin embargo fue visto por Soos, quien alertó a los mellizos, quienes ahora tienen que averiguar cuántos snacks están echados a perder para comprar nuevos y reemplazarlos.

Implementar una función que dado un vector de alimentos, junto con su tope, cuente aquellos que se hayan echado a perder y devuelva la cantidad total de estos.

Notas:
Los alimentos están representados por un registro el cual contiene la siguiente información:
    Nombre (string).
    Venció (booleano).
    Puntos mal olor (int).
Se considera que un alimento está echado a perder si venció y tiene más (estricto) de 3 puntos en mal olor.*/

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
    int alimentos_viejos = 0;
    for (int i = 0; i < tope; i++) {
        if (alimentos[i].vencio == true && alimentos[i].puntos_mal_olor > 3) alimentos_viejos++;
    }
    return alimentos_viejos;
}