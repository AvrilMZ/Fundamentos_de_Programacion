/*Llegó un nuevo juguete llamado Kiki a la casa de Andy. Kiki solo sabe hablar kikiakanoko y como Woody quiere acercarse a él para formar una amistad, decide aprender a hablarlo.
Luego de escucharlo hablar por unas horas se dio cuenta de algo:
Después de cada vocal, se agrega la letra "k" y se repite la vocal.

Implementar un procedimiento que traduzca una frase a kikiakanoko.

Ejemplo:
"Eres un juguete"
"Ekerekes ukun jukugukueketeke"*/

#include <string.h>
#define MAX_FRASE 50

const char* VOCALES = "aeiouAEIOU";

void traducir_frase(char frase_woody[MAX_FRASE]) {
	size_t tope_frase = strlen(frase_woody);
    char traduccion[MAX_FRASE * 3];
    int j = 0;

    for (size_t i = 0; i < tope_frase; i++) {
        for (size_t k = 0; VOCALES[k] != '\0'; k++) {
            if (frase_woody[i] == VOCALES[k]) {
                traduccion[j++] = frase_woody[i];
                traduccion[j++] = 'k';
                traduccion[j++] = frase_woody[i];
            } else traduccion[j++] = frase_woody[i];
        }
    }

    traduccion[j] = '\0';
    strcpy(frase_woody, traduccion);
}