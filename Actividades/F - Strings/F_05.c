/*Mr. Increible quiere infiltrarse en la computadora de Sindrome para revisar sus planes, pero se dió cuenta que hay una nueva prueba antes de poder acceder. Esta prueba consiste en escuchar un código, descifrar qué es lo que dice, y dar una respuesta correcta. Mr. Increible, inmediatamente notó que la frase está dicha de derecha a izquierda, pero le cuesta mucho darla vuelta para poder identificar qué es lo que dice.

Implementar un procedimiento que invierta la frase escuchada para ayudar a Mr. Increible

Ejemplo:
Si se escucha la frase “odavirp oirotarobaL”, debe quedar “Laboratorio privado”*/

#include <string.h>
#define MAX_FRASE 40

void intercambiar_frase(char frase[MAX_FRASE]) {
	char frase_intercambiada[MAX_FRASE];
    size_t tope_frase = strlen(frase);

    for (size_t i = 0; i < tope_frase; i++) {
        frase_intercambiada[i] = frase[(tope_frase - 1) - i];
    }

    frase_intercambiada[tope_frase] = '\0';
    strcpy(frase, frase_intercambiada);
}