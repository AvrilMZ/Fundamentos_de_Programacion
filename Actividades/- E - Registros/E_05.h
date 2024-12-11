/*En el camino a la clase “Sustos y programación I”, las pancitas de Mike Wazouski y Sullivan empezaron a gruñir. Ahora deberán decidir a dónde comprar comida para llevar. Para ello deberán considerar si un restaurante es lo suficientemente rápido. Dado el registro ‘restaurante_t’ que contiene al registro ‘empleados_t’ calcular la velocidad de preparación teniendo en cuenta:
Si los empleados tienen un delay mayor (estricto) a 5 minutos, se considerará lento.
Si los empleados están de franco, se considerará muy lento.
Si el restaurante está cerrado, se considerará muy lento.
Si el restaurante no es de comida rápida, se considerará lento.
En cualquier otro caso, se considerará rápido.

Implementar una función que teniendo en cuenta las reglas detallas arriba, calcule la velocidad del restaurante y devuelva, según corresponda, un caracter: (L)ento, (M)uy lento o (R)ápido.

Aclaración:
Si un restaurante es lento y muy lento se lo considerará muy lento.*/

#include "solucion.h"

const int DELAY_MAYOR = 5;
const char MUY_LENTO = 'M';
const char LENTO = 'L';
const char RAPIDO = 'R';

typedef struct empleados {
	int delay_en_entregar;
	bool estan_de_franco;
} empleados_t;

typedef struct restaurante{
	empleados_t empleados;
	bool cerrado;
	bool es_de_comida_rapida;
} restaurante_t;

char velocidad_del_restaurante(restaurante_t restaurante) {
	if (restaurante.empleados.estan_de_franco == true || restaurante.cerrado == true) return MUY_LENTO;
    else if (restaurante.empleados.delay_en_entregar > DELAY_MAYOR || restaurante.es_de_comida_rapida == false) return LENTO;
    else return RAPIDO;
}