#include <stdio.h>
#define MAXIMOS_DIAS 7

const int DOMINGO = 0;
const int LUNES = 1;
const int MARTES = 2;
const int MIERCOLES = 3;
const int JUEVES = 4;
const int VIERNES = 5;
const int SABADO = 6;

int dia_record(int usados[MAXIMOS_DIAS], int tope){
    int dia_ganador = -1;
    for (int i = 0; i < tope; i++){
        if (usados[i] >= usados[dia_ganador]){
            dia_ganador = i;
        }
    }
    return dia_ganador;
}