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