/*Jane le está enseñando frases en Español a Tarzán pero a él todavía le cuesta bastante pronunciar.
Para hacer esto más divertido, decidieron implementar una función que puntúe la pronunciación de Tarzán:

Una función que dado lo que dijo Jane y lo que dijo Tarzán, devuelva:
    5 si Tarzán repitió exactamente lo que dijo Jane
    2 si Tarzán se equivocó pero al menos la longitud de la frase fue correcta
    0 si Tarzán dijo cualquier cosa*/

#include <string.h>
#define MAX_FRASE 40

const int EXACTAMENTE = 5;
const int SE_EQUIVOCO = 2;
const int CUALQUIER_COSA = 0;

int puntos_frase(char frase_jane[MAX_FRASE], char frase_tarzan[MAX_FRASE]) {
	if (strcmp(frase_jane, frase_tarzan) == 0) return EXACTAMENTE;
    else if (strlen(frase_jane) == strlen(frase_tarzan)) return SE_EQUIVOCO;
    else return CUALQUIER_COSA;
}