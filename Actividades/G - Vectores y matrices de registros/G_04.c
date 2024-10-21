/*Habiendo desarrollado la función para determinar la distancia entre puntos, la tripulación del capitán Garfio está cada vez más cerca de encontrar el gran tesoro de la corona inglesa.

Ahora necesitarán una función que determine dado un vector de puntos cuál es el más cercano al punto central. En caso de haber un empate, devolver el punto más débil (menor fortaleza).
Tenés a tu disposición la función distancia_entre_puntos(primero, segundo).

Aclaración: El vector de puntos siempre va a tener al menos 1 elemento.*/

#include <stdio.h>
#include "funcion.h"
#define MAX_PUNTOS 20

typedef struct punto{
	int x;
	int y;
	int fortaleza;
}punto_t;

punto_t punto_mas_cercano(punto_t centro, punto_t puntos[MAX_PUNTOS], int tope){
	
}