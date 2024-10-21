#include <string.h>
#define MAX_NOMBRE 30

const char* FINAL_JUEGUETE = "lindi";

void nombrar_juguete(char juguete[MAX_NOMBRE]) {
    strcat(juguete, FINAL_JUEGUETE);
}