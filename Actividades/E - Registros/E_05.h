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