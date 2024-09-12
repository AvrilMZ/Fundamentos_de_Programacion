#include <stdbool.h>
#define MAX_EXPERIMENTOS 10

//Clave para verificar si el vector esta lleno o tiene celdas vacias:
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