#include <stdbool.h>

#define MAX_NOMBRE 50
const int POCION_FUERTE = 5;

typedef struct pocion{
    char nombre[MAX_NOMBRE];
    int potencia;
    bool de_rapida_accion;
} pocion_t;

//PRE: 'pociones' no debe estar vacio y debe tener al menos 1 pocion fuerte, y 'tope_pociones' debe ser mayor estricto que cero.
//POST: Devuelve el promedio de la potencia de las pociones fuertes.
int promedio_pociones_fuertes(pocion_t pociones[], int tope_posciones) {
    int contador_pociones_fuertes = 0;
    int contador_potencia_pociones = 0;

    for (int i = 0; i < tope_posciones; i++) {
        if (pociones[i].potencia > POCION_FUERTE && pociones[i].de_rapida_accion == true) {
            contador_pociones_fuertes++;
            contador_potencia_pociones += pociones[i].potencia;
        }
    }

    return contador_potencia_pociones / contador_pociones_fuertes;
}