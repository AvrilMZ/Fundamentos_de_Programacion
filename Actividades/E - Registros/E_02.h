#include <stdio.h>
#include "solucion.h"

const int PRECIO_CHOCOLATE = 50;
const int PRECIO_CARAMELOS = 10;
const int PRECIO_GASEOSA = 70;
const int PRECIO_PELOTA = 120;

typedef struct lista_compras {
	int cantidad_chocolates;
	int cantidad_caramelos;
	int cantidad_gaseosas;
	int cantidad_pelotas_playa;
	int precio_total;
} lista_compras_t;

void calcular_precio_total(lista_compras_t* lista_compras){
    lista_compras->precio_total = 0;
    
    lista_compras->precio_total += lista_compras->cantidad_chocolates * PRECIO_CHOCOLATE;
    lista_compras->precio_total += lista_compras->cantidad_caramelos * PRECIO_CARAMELOS;
    lista_compras->precio_total += lista_compras->cantidad_gaseosas * PRECIO_GASEOSA;
    lista_compras->precio_total += lista_compras->cantidad_pelotas_playa * PRECIO_PELOTA;
}