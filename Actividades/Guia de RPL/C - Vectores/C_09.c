/*A Goofy, los domingos a la mañana, le gusta salir a andar en bici por un cordón montañoso y recorrer diversos destinos. Cada destino, estará identificado en un vector según su altura.

Goofy decidió clasificar sus destinos según si él lo considera un pico, o no. Esta clasificación estará dada por dos características:
-No es ni el primero ni el ultimo destino.
-La altura del mismo es estrictamente mayor al anterior y estrictamente mayor al siguiente

Implementar una función que devuelva la cantidad de picos por la que pasará Goofy, a partir de un vector de destinos disponibles.

Ejemplo:
Si se recibe el vector [5, 4, 5, 4, 6, 7, 3, 4, 3, 5], la cantidad de picos será 3.*/

#include <stdio.h>
#define MAXIMOS_DESTINOS 100

int cantidad_de_picos(int alturas[MAXIMOS_DESTINOS], int tope){
    int picos = 0;
    for (int i = 1; i < tope - 1; i++){
        if (alturas[i] > alturas[i - 1] && alturas[i] > alturas[i + 1]){
                picos++;
        }
    }
    return picos;
}