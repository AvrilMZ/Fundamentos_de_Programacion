/*Como era de esperarse, la incontrolada fuerza de Hércules causó que algunas mancuernas salieran volando al bosque cercano, perdiéndose para siempre. Como a Phil le gusta mantener su almacén de equipamiento listo y preparado para el próximo héroe que toque su puerta, necesita reponer las mancuernas perdidas lo antes posible, por lo que se pide:

Implementar una función que recorra el bosque (ahora representado por mancuernas “M” y pasto “P”) y devuelva la cantidad de mancuernas perdidas.*/

#include <stdio.h>
#define MAX_FILAS 5
#define MAX_COLUMNAS 5

const char MANCUERNAS = 'M';
const char PASTO = 'P';

int mancuernas_perdidas(char bosque[MAX_FILAS][MAX_COLUMNAS]){
    int cantidad_mancuernas = 0;
    for (int i = 0; i < MAX_FILAS; i++) {
        for (int j = 0; j < MAX_COLUMNAS; j++) {
            if (bosque[i][j] == MANCUERNAS) cantidad_mancuernas++;
        }
    }
    return cantidad_mancuernas;
}