/*Clayton, cansado de los métodos de Jane y el profesor Porter, decide emplear un método más arcaico para hacerle entender a Tarzán que quieren ver gorilas. El método se basa en decir la palabra “gorila” y hacer que Tarzán la repita hasta que este entendiera a qué se refiere, aumentando el tono con cada repetición. El profesor Porter, sorprendido, decide contar cuántas veces se repitió este diálogo entre los dos. Por eso se pide:

Imprimir por pantalla esta discusión, sabiendo la cantidad total que contó el profesor Porter.
Ejemplos:

Si se recibe 1, debe imprimirse:
GO-RI-LA
GO-RI-LA!

Si se recibe 2, debe imprimirse:
GO-RI-LA
GO-RI-LA!
GO-RI-LA!!
GO-RI-LA!!!*/

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