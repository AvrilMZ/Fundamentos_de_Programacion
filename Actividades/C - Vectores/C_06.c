/*Después de varios días de ahorros Alex, Justin y Max por fin pudieron comprar una nueva varita mágica con un diseño que a los tres les gusta mucho. El tema es que solo lograron comprar una y no se deciden en quien la usará primero. Por lo que llegaron a un acuerdo, el que haya ahorrado más plata en un día usará la varita primero.
Recordemos que tenían sus ahorros en un vector donde cada posición corresponde a un día diferente. Esto quiere decir que en la posición 0 (cero) del vector vamos a tener el día 1 (uno), luego la 2 (dos) y así.

Implementar una función que dado el vector con los ahorros devuelva quién es el ganador.
Se sabe que en los días pares ahorró solo Alex, en los impares múltiplos de 5 ahorró Justin y en el resto ahorró Max. Tene en cuenta que el ganador es el que más ahorró en un día, no en total y que cada uno se representa con un char:

-Justin (J).
-Alex (A).
-Max (M).

En el caso de que no haya ahorros, es decir, que el vector de ahorros esté vacío, se debe devolver N de nadie.*/

#include <stdio.h>
#define MAX_AHORROS 256

const char JUSTIN = 'J';
const char ALEX = 'A';
const char MAX = 'M';
const char NINGUNO = 'N';

char ganador_ahorrista(int ahorros[MAX_AHORROS], int tope_ahorros) {
    int ahorros_justin = 0;
    int ahorros_alex = 0;
    int ahorros_max = 0;

    if (tope_ahorros == 0){
        return NINGUNO;
    }

    for (int i = 0; i < tope_ahorros; i++){
        int ahorro_dia = ahorros[i];

        if ((i + 1) % 2 == 0){
            if (ahorro_dia > ahorros_alex){
                ahorros_alex = ahorro_dia;
            }
        } else if (((i + 1) % 2 != 0) && ((i + 1) % 5 == 0)){
            if (ahorro_dia > ahorros_justin){
                ahorros_justin = ahorro_dia;
            }
        } else {
            if (ahorro_dia > ahorros_max){
                ahorros_max = ahorro_dia;
            }
        }
    }

    if (ahorros_alex > ahorros_justin && ahorros_alex > ahorros_max){
        return ALEX;
    } else if (ahorros_justin > ahorros_alex && ahorros_justin > ahorros_max){
        return JUSTIN;
    } else if (ahorros_max > ahorros_alex && ahorros_max > ahorros_justin){
        return MAX;
    } else return NINGUNO;
}