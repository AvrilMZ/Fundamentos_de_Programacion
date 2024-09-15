#include <stdio.h>
#include <math.h>
#include "vectores.h"

//PRE: -
//POST: Devuelve el vector resultante de la suma entre los 2 vectores ingresados.
vector_t sumar_vectores(vector_t vector1, vector_t vector2){
    vector_t suma;
    suma.valor_x = vector1.valor_x + vector2.valor_x;
    suma.valor_y = vector1.valor_y + vector2.valor_y;
    return suma;
}

//PRE: -
//POST: Devuelve el vector resultante de la resta entre los 2 vectores ingresados.
vector_t restar_vectores(vector_t vector1, vector_t vector2){
    vector_t resta;
    resta.valor_x = vector1.valor_x - vector2.valor_x;
    resta.valor_y = vector1.valor_y - vector2.valor_y;
    return resta;
}

//PRE: -
//POST: Devuelve el modulo de un vector ingresado.
int modulo_vector(vector_t vector){
    double x_elevado = pow(vector.valor_x, 2);
    double y_elevado = pow(vector.valor_y, 2);
    int modulo = (int)sqrt(x_elevado + y_elevado);
    return modulo;
}

//PRE: -
//POST: Devuelve el producto escalar de 2 vectores ingresados.
int producto_escalar(vector_t vector1, vector_t vector2){
    int producto = (vector1.valor_x * vector2.valor_x) + (vector1.valor_y * vector2.valor_y);
    return producto;
}