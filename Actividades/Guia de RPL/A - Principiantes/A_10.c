/*Nemo tiene que hacer su rito de iniciación cruzando el imponente ARO DE FUEGO, para esto, el grupo del estanque tienen que cantar “Aju Waji” la cantidad de veces pedidas para que Nemo pueda pasarlo. (https://www.youtube.com/watch?v=nupYcf4MhMg).

-Imprimir por pantalla la frase, según la cantidad de veces recibida que la dijo.*/

#include <stdio.h>

const char* CANTO = "Aju waji a jo jo jo"; 

int main(){
	int cantidad_repetidas;
	scanf("%i", &cantidad_repetidas);
	
    for (int i = 0; i < cantidad_repetidas; i++){
        printf("%s\n", CANTO);
    }

	return 0;
}