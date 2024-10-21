#include <stdlib.h>
#include "solucion.h"

typedef struct punto {
	int x;
	int y;
} punto_t;

int distancia_entre_puntos(punto_t primer_punto, punto_t segundo_punto) {
	return abs(primer_punto.x - segundo_punto.x) + abs(primer_punto.y - segundo_punto.y);
}