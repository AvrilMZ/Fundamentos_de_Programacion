#ifndef VECTORES_H
#define VECTORES_H

typedef struct vector{
    int valor_x;
    int valor_y;
} vector_t;

vector_t sumar_vectores(vector_t vector1, vector_t vector2);
vector_t restar_vectores(vector_t vector1, vector_t vector2);
int modulo_vector(vector_t vector);
int producto_escalar(vector_t vector1, vector_t vector2);

#endif