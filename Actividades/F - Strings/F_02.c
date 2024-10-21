#include <string.h>
#include <stdbool.h>
#define MAX_FRASE 50

const int LONGITUD_FAMILIAR = 15;

bool nombre(char frase[MAX_FRASE]) {
	size_t longitud_nombre = strlen(frase);
    return longitud_nombre > LONGITUD_FAMILIAR;
}