/*Roger, dueño de los 101 dálmatas, le pidió a Nanny que se encargue de comprarle alimento balanceado a los cachorros para la cena de hoy. El problema es que a Nanny se le complica sacar cuentas sobre cuántas bolsas debe comprar para que alcance para todos, por lo que le pidió ayuda a la facultad de ingeniería.

Teniendo en cuenta que cada bolsa rinde para 10 cachorros, se pide:
Crear un programa que de acuerdo a la cantidad de cachorros que querrán cenar, imprima por pantalla cuántas bolsas de alimento balanceado Nanny tendrá que comprar.*/

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