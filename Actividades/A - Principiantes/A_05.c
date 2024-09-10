#include <stdio.h>

int main(){
	int cantidad_jumba;
	int cantidad_jacques;
	scanf("%i", &cantidad_jumba);
	scanf("%i", &cantidad_jacques);
	
    int total = cantidad_jacques + cantidad_jumba;
    if ((total != 10) && (total < 10)){
        printf("%s", "Maldito hamster incompetente \n");
    } else printf("%s", "Te capturaremos 626!!! \n");

	return 0;
}