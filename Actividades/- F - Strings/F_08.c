/*Sully y Mike están haciendo un calendario para poder anotar sus tareas del día a día, pero les resultó aburrido escribir los días y meses de la manera tradicional. Para hacerlo más divertido, se les ocurrió transformar un poco las palabras con las siguientes reglas:

Días de semana: Si la palabra es un día de semana, y tiene hasta 6 letras (inclusive), se agrega al final el sufijo “ardo”. En cambio, si tiene más de 6 letras, se repiten las primeras dos letras.
Meses del año: Si la palabra es un mes, y tiene hasta 5 letras (inclusive), se agrega al final la palabra “duki”. En cambio, si tiene más de 5 letras, se repiten las últimas dos letras.

Implementar un procedimiento que transforme la palabra recibida, según las reglas del juego creadas por Sully y Mike.

Tener en cuenta:
Tanto los días de semana como los meses vienen en minúscula y sin caracteres especiales (como lo son tildes, ñ, etc). Se deja un listado de cómo puede venir cada uno:
Días de semana: lunes, martes, miercoles, jueves, viernes, sabado, domingo.
Meses del año: enero, febrero, marzo, abril, mayo, junio, julio, agosto, septiembre, octubre, noviembre, diciembre.

Ejemplos:
sabado, debe quedar sabadoardo.
domingo, debe quedar domingodo.
mayo, debe quedar mayoduki.
noviembre, debe quedar noviembrere.*/

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