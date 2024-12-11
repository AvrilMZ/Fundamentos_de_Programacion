/*Lilo y Stitch llevan registro de todos los experimentos extraviados del Dr. Jumba que encuentran, y para hacerlo los tienen en un vector donde a cada experimento lo representan con un id que es un entero.
Últimamente están encontrando muchos experimentos nuevos y se les complica un poco estar agregándolos a mano a este vector, por lo que nos pidieron ayuda para que creemos un algoritmo que lo haga por ellos. Pero como nosotros nos dormimos en esas clases te lo pedimos a vos.

Implementar una función que dado un vector, su tope y un id agregue al nuevo experimento al vector.
Además si no es posible agregarlo porque el vector ya está al máximo de su capacidad se pide que devuelva false y en caso contrario que devuelva true.*/

#include <stdbool.h>
#define MAX_EXPERIMENTOS 10

bool registrar_experimento(int experimentos[MAX_EXPERIMENTOS], int* tope_experimentos, int id_experimento) {
	for (int i = 0; i < MAX_EXPERIMENTOS; i++){
		if (i >= *tope_experimentos){
			experimentos[i] = id_experimento;
			(*tope_experimentos)++;
			return true;
		}
	}
	return false;
}