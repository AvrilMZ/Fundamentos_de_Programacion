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