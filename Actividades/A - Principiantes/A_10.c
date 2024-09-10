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