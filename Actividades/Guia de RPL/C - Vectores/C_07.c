/*En Disney hay una fuerte discusión sobre qué programa debería pasarse a la mañana, cuando los chicos despiertan para ir al colegio. Para hacerlo de una manera justa, se le dio a cada personaje un número aleatorio entre el 0 y el 100 (ambos inclusive) y los fueron anotando en un vector. Y decidieron que, el que tenga el número más chico, tendrá la suerte de salir al aire en ese horario.

Implementar una función que dado un vector con los números aleatorios, devuelva el índice del más chico.
Además, implementar una función que dado un vector donde cada posición representa un programa y el vector de números aleatorios, devuelva el programa al cual le corresponde el número más chico.

Tener en cuenta:
Los programas son representados con la inicial de su nombre, o “-” en caso de que no haya uno.
Ambos vectores pueden tener topes diferentes. En el caso de que el índice del número más chico caiga por fuera del vector de programas se debe devolver '-'.
Si el vector de programas o el de aleatorios está vació se debe devolver '-'.

Ejemplo:
Teniendo el vector de programas ['T', 'S', '-'] y el vector de números aleatorios [2, 0, 5]. El número más chico de los aleatorios es el 0 (cero) en el indice 1, por lo que la función programa_ganador debería devolver 'S'.*/

#include <stdio.h>
#define MAX_NUMEROS 100

const char PROGRAMA_SIN_NOMBRE = '-';

int numero_mas_chico(int numeros[MAX_NUMEROS], int tope_numeros) {
    if (tope_numeros == 0) return -1;

    int indice_numero_menor = 0;
    for (int i = 0; i < tope_numeros; i++){
        if (numeros[i] < numeros[indice_numero_menor]){
            indice_numero_menor = i;
        }
    }
    return indice_numero_menor;
}

char programa_ganador(char programas[MAX_NUMEROS], int tope_programas, int numeros[MAX_NUMEROS], int tope_numeros) {
    if (tope_programas == 0 || tope_numeros == 0){
        return PROGRAMA_SIN_NOMBRE;
    }
    
    int indice_numero_menor = numero_mas_chico(numeros, tope_numeros);
    if (indice_numero_menor < 0 || indice_numero_menor >= tope_programas){
        return PROGRAMA_SIN_NOMBRE;
    } else return programas[indice_numero_menor];
}