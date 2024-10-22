/*Mabel y sus amigas Candy y Grenda son super admiradoras de la banda de chicos Sev'ral Timez y de vez en cuando se divierten dedicándoles cartas de amor a los diferentes miembros de esta, las cuales guardan.

Dado un vector de registros correspondientes a cartas de amor, determinar el índice de cuál es la que tiene mayor cantidad de palabras románticas.
En caso de empate, devolver la primera encontrada (La más cercana al indice 0)*/

#include <stdio.h>
#include <stdbool.h>
#define MAX_CARTAS 50

typedef struct carta{
	int id;
	int cantidad_palabras_de_amor;
	bool esta_arrugada;
} carta_t;

int indice_carta_mas_palabras_de_amor(carta_t cartas[MAX_CARTAS], int tope){
	int carta_mas_palabras = 0;
	int maximo_palabras_actual = 0;
	for (int i = 0; i < tope; i++) {
		if (cartas[i].cantidad_palabras_de_amor > maximo_palabras_actual) {
			maximo_palabras_actual = cartas[i].cantidad_palabras_de_amor;
			carta_mas_palabras = i;
		}
	}
	return carta_mas_palabras;
}