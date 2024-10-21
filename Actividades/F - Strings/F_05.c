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