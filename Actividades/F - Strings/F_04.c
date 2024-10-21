/*Lilo y Stitch se inscribieron a un curso de cocina en la que en la etapa final, cada uno tiene que cocinar lo que quiera, siempre y cuando se luzcan y demuestren todo lo que fueron aprendiendo a lo largo del curso. Pero como Stich es muy distraído, no anotó ninguna receta, por lo que no se le ocurre que puede cocinar. Su única salvación, es copiar la receta que tiene Lilo en la mesa de al lado.

Implementar un procedimiento que copie la receta de Lilo en el recetario de Stitch.*/

#include <string.h>
#define MAX_RECETA 250

void copiar_receta(char receta_lilo[MAX_RECETA], char recetario_stitch[MAX_RECETA]) {
	strcpy(recetario_stitch, receta_lilo);
}