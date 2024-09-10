#include <stdio.h>

const char* IZQUIERDA = "Por la izquierda!";
const char* DERECHA = "Por la derecha!";

int main(){
	char cifrado;
	scanf(" %c", &cifrado);

    if (cifrado == 'I'){
        printf("%s\n", IZQUIERDA);
    } else if (cifrado == 'D'){
        printf("%s \n", DERECHA);
    } else printf("%s", "Atlantis! \n");

	return 0;
}