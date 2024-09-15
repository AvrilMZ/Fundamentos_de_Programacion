#include <stdio.h>
#include "vectores.h"

int main (){
    vector_t primer_vector;
    vector_t segundo_vector;

    printf("Elija la cordenada X de su primer vector:\n");
    scanf("%i", &primer_vector.valor_x);
    printf("Elija la cordenada Y de su primer vector:\n");
    scanf("%i", &primer_vector.valor_y);
    printf("Elija la cordenada X de su segundo vector:\n");
    scanf("%i", &segundo_vector.valor_x);
    printf("Elija la cordenada Y de su segundo vector:\n");
    scanf("%i", &segundo_vector.valor_y);

    vector_t suma = sumar_vectores(primer_vector, segundo_vector);
    vector_t resta = restar_vectores(primer_vector, segundo_vector);
    int modulo_vec1 = modulo_vector(primer_vector);
    int modulo_vec2 = modulo_vector(segundo_vector);
    int producto = producto_escalar(primer_vector, segundo_vector);

    printf("Las operaciones entre los vectores dados son:\n");
    printf("Suma: (%i; %i)\n", suma.valor_x, suma.valor_y);
    printf("Resta: (%i; %i)\n", resta.valor_x, resta.valor_y);
    printf("Producto escalar: %i\n", producto);
    printf("Modulo del vector 1: %i\n", modulo_vec1);
    printf("Modulo del vector 2: %i\n", modulo_vec2);

    return 0;
}