#include <string.h>
#define MAX_RECETA 250

void copiar_receta(char receta_lilo[MAX_RECETA], char recetario_stitch[MAX_RECETA]) {
	strcpy(recetario_stitch, receta_lilo);
}