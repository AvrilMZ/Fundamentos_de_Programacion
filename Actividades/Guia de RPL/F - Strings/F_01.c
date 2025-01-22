/*Bonnie llegó a tener una gran familia de juguetes, tiene 53 en total, y decidió que todos tengan nombres que terminen en “lindi”.

Implementar un procedimiento que dado el nombre de un juguete le agregue “lindi” al final. Considerar que el nombre va a tener suficiente espacio para el agregado.

Ejemplo:
Si nos viene de nombre ”nao”, el resultado de llamar a nuestro procedimiento va a ser ”naolindi”`.*/

#include <string.h>
#define MAX_NOMBRE 30

const char* FINAL_JUEGUETE = "lindi";

void nombrar_juguete(char juguete[MAX_NOMBRE]) {
    strcat(juguete, FINAL_JUEGUETE);
}