/*Hércules se está enfrentando a Medusa, a quien no puede mirar a los ojos ya que sino se convertiría en piedra. Phil se dio cuenta de que el comportamiento de las serpientes de la cabeza de Medusa son un buen indicio para saber cuándo es conveniente atacar. Si el comportamiento de las serpientes se puede representar como números, y cada serpiente supone una posición en la matriz de serpientes, se pide:

Implementar una función que sume los comportamientos de cada una de las serpientes, y devuelva true si la cantidad total sumada es menor a 0, o false en caso contrario.

Ejemplo:
Si se recibe la matriz de 3x4:
 5  4 -2  1
-4  5  2  2
-2 -5  3  7
Como el total suma 16, se debería devolver false.*/

#include <stdio.h>
#include <stdbool.h>
#define MAX_FILAS 5
#define MAX_COLUMNAS 5

int const ATACAR = 0;

bool conviene_atacar(int serpientes[MAX_FILAS][MAX_COLUMNAS], int tope_fila, int tope_columna) {
    int suma_comportamientos = 0;
    for (int i = 0; i < tope_fila; i++) {
        for (int j = 0; j < tope_columna; j++) {
            suma_comportamientos += serpientes[i][j];
        }
    }
    return suma_comportamientos < ATACAR;
}