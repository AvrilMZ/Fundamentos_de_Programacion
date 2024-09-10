#include <stdio.h>

int main(){
    int cachorros = -1;
    printf("Cuantos cachorros quieren comer? (Ingresar un valor entre 0 y 101) \n");
	scanf("%i", &cachorros);

    int bolsas = cachorros / 10;
    if ((bolsas % 2) != 0){
        bolsas += 1;
        printf("Cantidad de Bolsas: %i \n", bolsas);
    } else if (cachorros < 10){
        bolsas = 1;
        printf("Cantidad de Bolsas: %i \n", bolsas);
    } 
    else printf("Cantidad de Bolsas: %i \n", bolsas);

	return 0;
}