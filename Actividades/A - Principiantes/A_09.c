#include <stdio.h>

const char* DIALOGO = "GO-RI-LA";
const char EXCLAMACION = '!';

int main(){
	int veces_repetidas = -1;
	scanf("%i", &veces_repetidas);
	
	veces_repetidas *= 2;

	for (int i = 1; i <= veces_repetidas; i++){
		printf("%s", DIALOGO);

		if (i > 1){
			for (int j = 1; j <= (i - 1); j++) {
				printf("%c", EXCLAMACION);
			}
		}

		printf("\n");
	}
	
	return 0;
}