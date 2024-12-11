/*Milo Thatch y la expedición se perdieron en un sistema de cuevas mientras encontraban la entrada a la legendaria Atlantis. Afortunadamente, Milo posee anotaciones en su cuaderno que indican el camino a seguir, pero se encuentran cifradas. Haciendo uso de su experiencia como cartógrafo y lingüista, Milo tendrá que guiar a la expedición hacia Atlantis.

Crear un programa que dado un caracter que representa cifrado del cuaderno de Milo, imprima por pantalla qué camino deben tomar.
Se espera entonces que:
Si recibe una I (izquierda) se imprima: “Por la izquierda!”.
Si recibe una D (derecha) se imprima: “Por la derecha!”.
Si recibe otra letra, es porque encontraron Atlantis y debe imprimirse: “Atlantis!”.*/

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