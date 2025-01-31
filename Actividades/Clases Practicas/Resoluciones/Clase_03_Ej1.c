#include <stdio.h>
#include <stdbool.h>

#define MAX_REGALOS 10
const int MAX_NENES = 10;
const char SI = 'S';

/* PRE: 'tope' debe estar previamente inicializado.
   POST: Imprime por pantalla todos los elementos de un vector.*/
void imprimir_vector(int vector[], int tope) {
    for (int i = 0; i < tope; i++) {
        if (i == tope - 1) printf("%i.\n", vector[i]);
        else printf("%i, ", vector[i]);
    }
}

/* PRE: -
   POST: Devuelve true si 'cantidad' esta entre 1 y 'MAX_NENES', de lo contrario, devuelve false.*/
bool es_cantidad_aceptable_nenes(int cantidad) {
    return (cantidad <= MAX_NENES && cantidad > 0);
}

/* PRE: -
   POST: Actualiza 'cantidad' por el valor ingresado por el usuario, si es que este esta en el rango permitido.*/
void consultar_cantidad_nenes(int* cantidad) {
    bool cantidad_aceptable = false;
    while (!es_cantidad_aceptable_nenes(*cantidad)) {
        printf("¿Cuantos niños perdidos hay?\n");
        scanf("%i", cantidad);
    }
}

/* PRE: 'tope' debe estar previamente inicializado.
   POST: Itera por el arreglo 'medidas' registrando cada valor ingresado por el usuario.*/
void medidas_cuellos(int medidas[MAX_REGALOS], int* tope) {
    consultar_cantidad_nenes(tope);
    for (int i = 0; i < (*tope); i++) {
        printf("¿Cuál es la medidad del cuello del niño número %i?\n", i);
        scanf("%i", &medidas[i]);
    }
    printf("El arreglo de medidas quedó: ");
    imprimir_vector(medidas, *tope);
}

/* PRE: 'tope' debe estar previamente inicializado y 'posicion' debe ser válida.
   POST: Elimina el elemento en el indice 'posicion' del arreglo 'vector'.*/
void eliminar_elemento(int vector[], int* tope, int posicion) {
    for (int i = posicion; i < *tope - 1; i++) {
        vector[i] = vector[i + 1];
    }
    (*tope)--;
}

/* PRE: 'tope' debe estar previamente inicializado.
   POST: Consulta al usuario si desea eliminar un elemento del arreglo, en caso de ser afirmativo le pregunta la posición y lo elimina.*/
void consultar_eliminar_elemento(int vector[], int* tope) {
    int posicion_a_eliminar = -1;
    char respuesta = 'S';
    while (respuesta == SI) {
        printf("¿Desea eliminar un elemento del arreglo? (Ingrese 'S' en caso afirmativo)\n");
        scanf(" %c", &respuesta);

        if (respuesta == SI) {
            printf("¿Qué posición quiere eliminar? (La primera posición del arreglo es cero)\n");
            scanf("%i", &posicion_a_eliminar);

            if (posicion_a_eliminar >= 0 && posicion_a_eliminar < *tope) {
                eliminar_elemento(vector, tope, posicion_a_eliminar);
                printf("El arreglo de medidas quedó: ");
                imprimir_vector(vector, *tope);
            } else {
                printf("Error: posición inválida. Debe estar entre 0 y %i.\n", *tope - 1);
            }
        }
    }
}

int main() {
    int medidas[MAX_REGALOS];
    int cantidad_nenes = -1;

    consultar_cantidad_nenes(&cantidad_nenes);
    medidas_cuellos(medidas, &cantidad_nenes);
    consultar_eliminar_elemento(medidas, &cantidad_nenes);

    printf("Sus medidas finales son: ");
    imprimir_vector(medidas, cantidad_nenes);

    return 0;
}