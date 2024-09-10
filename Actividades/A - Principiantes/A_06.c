#include <stdio.h>

const char ENERO = 'E';
const char FEBRERO = 'F';
const char MONTAÑA = 'M';
const char PLAYA = 'P';

int main(){
	char epoca = '.';
	char paisaje = '.';
	scanf(" %c", &epoca);
	scanf(" %c", &paisaje);
	
    if ((epoca == ENERO && paisaje == MONTAÑA) || (epoca == FEBRERO && paisaje == PLAYA)){
        printf("%s", "Dale \n");
    } else printf("%s", "Chip \n");

	return 0;
}