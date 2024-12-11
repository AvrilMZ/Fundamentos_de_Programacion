/*Llegó un nuevo juguete llamado Kiki a la casa de Andy. Kiki solo sabe hablar kikiakanoko y como Woody quiere acercarse a él para formar una amistad, decide aprender a hablarlo.
Luego de escucharlo hablar por unas horas se dio cuenta de algo:
Después de cada vocal, se agrega la letra "k" y se repite la vocal.

Implementar un procedimiento que traduzca una frase a kikiakanoko.

Ejemplo:
"Eres un juguete"
"Ekerekes ukun jukugukueketeke"*/

#include <string.h>
#include <stdbool.h>
#define MAX_FRASE 50

const char* VOCALES = "aeiouAEIOU";

void traducir_frase(char frase_woody[MAX_FRASE]) {
	char resultado[MAX_FRASE * 3];
    size_t j = 0;
    size_t longitud = strlen(frase_woody);

    for (size_t i = 0; i < longitud; i++) {
        bool es_vocal = false;

        for (size_t k = 0; k < strlen(VOCALES); k++) {
            if (frase_woody[i] == VOCALES[k]) es_vocal = true;
        }
        
        if (es_vocal) {
            resultado[j++] = frase_woody[i];
            resultado[j++] = 'k';
            resultado[j++] = frase_woody[i];
        } else resultado[j++] = frase_woody[i];
        
    }
    
    resultado[j] = '\0';
    strcpy(frase_woody, resultado);
}