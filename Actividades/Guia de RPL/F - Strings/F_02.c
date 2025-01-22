/*Esteban organizó una fiesta en el hotel en la que invitó a toda su familia. El problema es que hay mucha gente del Hotel que se quiere colar. Para evitar esto, Esteban está preguntando los nombres de los invitados cuando llegan. Si el nombre tiene más de 15 letras, entonces sabe que es un familiar suyo. Para facilitar esto, nos pidió un programa en el que el usuario ingrese un nombre y devuelva si es un verdadero familiar o no.

Implementar una función que dado un nombre devuelva true si es familiar de Esteban (Tiene más de 15 letras), o false en caso contrario.*/

#include <string.h>
#include <stdbool.h>
#define MAX_FRASE 50

const int LONGITUD_FAMILIAR = 15;

bool nombre(char frase[MAX_FRASE]) {
	size_t longitud_nombre = strlen(frase);
    return longitud_nombre > LONGITUD_FAMILIAR;
}