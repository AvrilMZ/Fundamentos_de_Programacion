/*Para desgracia de Mowgli, tras ser capturado por los monos y llevado al templo de la selva, Shere Kan logró encontrarlo. Mowgli deberá hacer todo lo posible para escapar del tigre, moviéndose constantemente y cambiando de escondite. Sin embargo, debe tener en cuenta que Shere Kan es mucho más rápido que él, por lo tanto debe mantenerse alejado todo lo que pueda y evitar ser atrapado.

Implementar una función que dada una matriz que representa el templo de la selva, y la posición siguiente de Mowgli, realice el movimiento y devuelva true si es conveniente, en caso contrario debe devolver false y no realizará el movimiento.
El movimiento no se puede hacer si la posición está ocupada por Shere Kan o queda por fuera de los límites de la matriz.

A tener en cuenta:
La matriz puede no ser cuadrada y tiene sus respectivos topes.
Un movimiento es conveniente si la nueva posición se encuentra a distancia 1 o más de Shere Kan (incluyendo las diagonales)
La matriz es de caracteres donde en cada posición puede haber:
Shere Kan(S).
Mowgli(M).
Vacío (-).

Ejemplo:
Teniendo una matriz de 5x3:
-M-
---
S--
Y teniendo como nueva posición:
fila = 3
columna = 0
No se debe mover a Mowgli, quedando la matriz sin modificar, y se debe devolver false.
Si la nueva posición fuera:
fila = 4
columna = 1
Se debe mover a Mowgli quedando la matriz modificada, y se debe devolver ‘true’*/

#include <stdbool.h>
#define MAX_FILAS 30
#define MAX_COLUMNAS 25

const char SHERE = 'S';
const char MOWGLI = 'M';
const char VACIO = 'V';

bool escapar(char templo[MAX_FILAS][MAX_COLUMNAS], int tope_filas, int tope_columnas, int nueva_fila, int nueva_columna) {
    if (nueva_fila < 0 || nueva_fila >= tope_filas || nueva_columna < 0 || nueva_columna >= tope_columnas) return false;

    if (templo[nueva_fila][nueva_columna] == SHERE || (nueva_fila == -1 && nueva_columna == -1)) return false;

    for (int i = 0; i < tope_filas; i++) {
        for (int j = 0; j < tope_columnas; j++) {
            if (templo[i][j] == SHERE) {
                int diferencia_fila = nueva_fila - i;
                int diferencia_columna = nueva_columna - j;
                if (diferencia_fila * diferencia_fila + diferencia_columna * diferencia_columna < 4) return false;
            }
        }
    }

    for (int i = 0; i < tope_filas; i++) {
        for (int j = 0; j < tope_columnas; j++) {
            if (templo[i][j] == MOWGLI) templo[i][j] = VACIO;
        }
    }
    
    templo[nueva_fila][nueva_columna] = MOWGLI;

    return true;
}