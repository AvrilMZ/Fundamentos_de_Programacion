#include <stdio.h>

void imprimir_codigo(int edad1, int edad2, int edad3) {
    int suma = edad1 + edad2 + edad3;
    printf("%i\n", suma);
}

int main(){
    int edad_mickey;
	scanf("%i", &edad_mickey);
	int edad_goofy;
	scanf("%i", &edad_goofy);
	int edad_donald;
	scanf("%i", &edad_donald);

    imprimir_codigo(edad_mickey, edad_goofy, edad_donald);

    return 0;
}