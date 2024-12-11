/*El capitán Garfio es un gran coleccionista de Garfios; se dice que es el más grande de los 7 mares. Asaltando barcos obtuvo la ubicación de un gran tesoro perteneciente a la corona inglesa, el cual contiene uno de los más valiosos garfios perteneciente al pirata más grande de la historia (después de él, claro).
Sin embargo, al no recibir un mapa, no sabe con exactitud la ubicación del tesoro, por lo que este le asignó la tarea a su tripulación de encontrarlo.
Se sabe que existe un punto aproximado en el cual se puede encontrar el tesoro.

Implementar una función que con la ayuda del registro punto_t, determine la distancia dos puntos pertenecientes al barco y el tesoro, y la devuelva.

Aclaración:
La distancia se calcula como distancia manhattan, que es la suma de las distancias en ambos sentidos:
|x1 - x2| + |y1 - y2|

Ejemplo:
Dado el primer punto como (x,y) = (1,3) y el segundo punto como (x,y) = (2,6), la distancia entre estos dos puntos nos da:
|1 - 2| + |3 - 6| = 4
Por lo tanto, nuestra función devolvera 4.*/

#include <stdlib.h>
#include "solucion.h"

typedef struct punto {
	int x;
	int y;
} punto_t;

int distancia_entre_puntos(punto_t primer_punto, punto_t segundo_punto) {
	return abs(primer_punto.x - segundo_punto.x) + abs(primer_punto.y - segundo_punto.y);
}