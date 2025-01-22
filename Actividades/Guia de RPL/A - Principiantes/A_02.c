/*El señor Bigotes está medio frustrado porque su último experimento, un control remoto para controlar a Brandy es un fracaso.
Este suceso está haciendo que, cada vez que se toca la cabeza, se le caigan 78 pelos.

Crear un programa que, dadas las veces que el señor Bigotes se tocó la cabeza, imprima por pantalla cuántos pelos perdió.*/

#include <stdio.h>
const int PELOS = 78;

int main(){
	int veces = -1;

	printf("Cuantas veces el señor Bigotes se toco la cabeza? (Ingrese un valor mayor a 0) \n");
	scanf("%i", &veces);

	int pelos_perdidos = veces * PELOS;
	printf("El señor Bigotes perdio %i pelos \n", pelos_perdidos);

	return 0;
}