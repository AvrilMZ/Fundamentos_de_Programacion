#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "Clase_05_Ej2.h"

const char* ELECTRONICO = "ELECTRONICO";
const char* PELUCHE = "PELUCHE";
const char* PLASTICO = "PLASTICO";
const int ANIO_ACTUAL = 2024;
const int ANTIGUEDAD_PARA_VENDER = 10;

/* PRE: 'nuevo_juguete' debe ser un juguete inicializado. 'inventario' está correctamente inicializado.
   POST: Se va a agregar el juguete al baúl que tenga menos juguetes y se muestra un mensaje con la etiqueta del baúl al que fue agregado. Si el 'inventario' está lleno, no se agrega el juguete y se muestra un mensaje indicando que no hay espacio.*/
void agregar_juguete(inventario_t* inventario, juguete_t nuevo_juguete) {
    int contador_baules_llenos = 0;
    int baul_menos_juguetes = -1;
    int record_menor_juguetes = inventario->baules[0].tope_juguetes;

    for (int i = 0; i < inventario->tope_baules; i++) {
        if (inventario->baules[i].tope_juguetes == MAX_JUGUETES) {
            contador_baules_llenos++;
        } else if (inventario->baules[i].tope_juguetes < record_menor_juguetes) {
            record_menor_juguetes = inventario->baules[i].tope_juguetes;
            baul_menos_juguetes = i;
        }
    }

    if (contador_baules_llenos == inventario->tope_baules) printf("No hay mas espacio en los baules\n");
    else {
        inventario->baules[baul_menos_juguetes].juguetes[inventario->baules[baul_menos_juguetes].tope_juguetes] = nuevo_juguete;
        inventario->baules[baul_menos_juguetes].tope_juguetes++;
        printf("Se añadio un juguete al baúl de indice %i\n", baul_menos_juguetes);
    }

}

/* PRE: 'inventario' debe estar inicializado y los tipos de los juguetes deben ser “Electrónico", "Peluche", o "Plástico"
   POST: Se cuentan y muestran la cantidad de cada tipo de peluche por pantalla.*/
void contar_juguetes_por_tipo(inventario_t inventario) {
    int contador_electronico = 0;
    int contador_peluche = 0;
    int contador_plastico = 0;

    for (int i = 0; i < inventario.tope_baules; i++) {
        for (int j = 0; j < inventario.baules[i].tope_juguetes; j++) {
            if (strcmp(inventario.baules[i].juguetes[j].tipo, ELECTRONICO) == 0) contador_electronico++;
            else if (strcmp(inventario.baules[i].juguetes[j].tipo, PELUCHE) == 0) contador_peluche++;
            else if (strcmp(inventario.baules[i].juguetes[j].tipo, PLASTICO) == 0) contador_plastico++;
        }
    }

    printf("Hay %i juguetes electronicos, %i juguetes de peluche y %i juguetes de plastico.\n", contador_electronico, contador_peluche, contador_plastico);
}

/* PRE: 'inventario' debe estar correctamente inicializado.
   POST: Crea un nuevo baúl vacío para guardar juguetes con la etiqueta que recibe.*/
void agregar_baul(inventario_t* inventario, char etiqueta[MAX_NOMBRE]) {
    if (inventario->tope_baules < MAX_BAULES) {
        strcpy(inventario->baules[inventario->tope_baules].etiqueta, etiqueta);
        inventario->baules[inventario->tope_baules].tope_juguetes = 0;
        inventario->tope_baules++;
    } else printf("Se alcanzó el máximo de baules.\n");
}

/* PRE: 'inventario' debe estar correctamente inicializado, así como también el vector de 'juguetes_a_vender' vacío con su tope inicializado correctamente.
   POST: Guarda en el vector de juguetes aquellos que pueden ser vendidos, se tiene en cuenta que se quieren vender los que no son peluches y los que tienen más de 10 años de antigüedad.*/
void calcular_valor_total(inventario_t inventario, juguete_t jueguetes_a_vender[MAX_JUGUETES], int* tope_juguetes_a_vender) {
    for (int i = 0; i < inventario.tope_baules; i++) {
        for (int j = 0; j < inventario.baules[i].tope_juguetes; j++) {
            if (ANIO_ACTUAL - inventario.baules[i].juguetes[j].anio_comprado > ANTIGUEDAD_PARA_VENDER && strcmp(inventario.baules[i].juguetes[j].tipo, PELUCHE) != 0) {
                jueguetes_a_vender[*tope_juguetes_a_vender] = inventario.baules[i].juguetes[j];
                (*tope_juguetes_a_vender)++;
            }
        }
    }
}

int main() {
    return 0;
}