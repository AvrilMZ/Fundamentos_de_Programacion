/*Buscando una poción para envenenar a Kuzco, Kronk tiró al piso el estante con todos los frascos. Algunos se abrieron y derramaron parte del líquido. Para que Yzma no se enoje, Kronk decidió rellenarlos.
Como solo encontró una jarra con la etiqueta "Llama" solo puede rellenar frascos con la misma etiqueta. Además debe asegurarse de contar cuántos mililitros de líquido usó para llenar los frascos para así preparar más. Cada frasco tiene capacidad de 85 ml.

Implementar una función que dado un vector de frascos: rellene a los que tienen la etiqueta "Llama" (esto es setear el campo contenido al máximo) y devuelva la cantidad de mililitros usados.

Notas:
Los frascos están representados por un registro que contiene los siguientes datos:
    Etiqueta (string).
    Contenido (int).*/

#include <stdio.h>
#include <string.h>
#define MAX_FRASCOS 200
#define MAX_ETIQUETA 144

const int CAPACIDAD_FRASCOS = 85;
const char* ETIQUETA_A_LLENAR = "Llama";

typedef struct frasco {
    char etiqueta[MAX_ETIQUETA];
    int contenido;
} frasco_t;

int rellenar_frascos(frasco_t frascos[MAX_FRASCOS], int tope){
    int cantiadad_liquido_usado = 0;
    for (int i = 0; i < tope; i++) {
        if (strcmp(frascos[i].etiqueta, ETIQUETA_A_LLENAR) == 0) {
            if (frascos[i].contenido < CAPACIDAD_FRASCOS) {
                int espacio_disponible = CAPACIDAD_FRASCOS - frascos[i].contenido;
                frascos[i].contenido += espacio_disponible;
                cantiadad_liquido_usado += espacio_disponible; 
            }
        }
    }
    return cantiadad_liquido_usado;
}