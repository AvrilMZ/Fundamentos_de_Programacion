#include <string.h>
#include <stdbool.h>
#define MAX_PALABRA 50
#define MAX_DIAS 7
#define MAX_MESES 12

const char* DIAS_SEMANA[MAX_DIAS] = {"lunes", "martes", "miercoles", "jueves", "viernes", "sabado", "domingo"};
const char* MESES[MAX_MESES] = {"enero", "febrero", "marzo", "abril", "mayo", "junio", "julio", "agosto", "septiembre", "octubre", "noviembre", "diciembre"};
const char* SUFIJO_DIAS = "ardo";
const char* SUFIJO_MESES = "duki";

void cambiar_palabra(char palabra[MAX_PALABRA]) {
	int es_dia = 0;

    for (int i = 0; i < MAX_DIAS; i++) {
        if (strcmp(palabra, DIAS_SEMANA[i]) == 0) {
            es_dia = 1;
            if (strlen(palabra) <= 6) strcat(palabra, SUFIJO_DIAS);
            else {
                char letras[3] = {palabra[0], palabra[1], '\0'};
                strcat(palabra, letras);
            }
        }
    }

    if (!es_dia) {
        for (int i = 0; i < MAX_MESES; i++) {
            if (strcmp(palabra, MESES[i]) == 0) {
                if (strlen(palabra) <= 5) strcat(palabra, SUFIJO_MESES);
                else {
                    size_t len = strlen(palabra);
                    strncat(palabra, palabra + (len - 2), 2);
                }
            }
        }
    }
}