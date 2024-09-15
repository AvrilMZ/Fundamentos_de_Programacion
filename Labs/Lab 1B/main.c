#include <stdio.h>
#include "complejos.h"

int main(){
    complejo_t numero_complejo1;
    complejo_t numero_complejo2;

    printf("Ingrese la parte real de su primer numero complejo:\n");
    scanf("%i", &numero_complejo1.parte_real);
    printf("Ingrese la parte imaginaria de su primer numero complejo:\n");
    scanf("%i", &numero_complejo1.parte_imaginaria);
    printf("Ingrese la parte real de su segundo numero complejo:\n");
    scanf("%i", &numero_complejo2.parte_real);
    printf("Ingrese la parte imaginaria de su segundo numero complejo:\n");
    scanf("%i", &numero_complejo2.parte_imaginaria);

    suma_complejos(numero_complejo1, numero_complejo2);
    resta_complejos(numero_complejo1, numero_complejo2);
    printf("De su primer numero complejo elegido:\n");
    parte_real(numero_complejo1);
    parte_imaginaria(numero_complejo1);
    printf("De su segundo numero complejo elegido:\n");
    parte_real(numero_complejo2);
    parte_imaginaria(numero_complejo2);

    return 0;
}