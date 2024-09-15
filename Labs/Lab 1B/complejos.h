#ifndef COMPLEJOS_H
#define COMPLEJOS_H

typedef struct complejo{
    int parte_real;
    int parte_imaginaria;
} complejo_t;

void suma_complejos(complejo_t complejo1, complejo_t complejo2);
void resta_complejos(complejo_t complejo1, complejo_t complejo2);
void parte_real(complejo_t complejo);
void parte_imaginaria(complejo_t complejo);

#endif