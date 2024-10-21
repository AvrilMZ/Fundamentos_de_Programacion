#include <stdbool.h>
#define MAX_FILAS 5
#define MAX_COLUMNAS 5

const char DISTANCIA = 'D';
const char CUERPO = 'C';
const char NO_DIOS = '-';

bool son_titanes_vencidos(char formacion[MAX_FILAS][MAX_COLUMNAS], int tope_filas, int tope_columnas, int cantidad_dioses, char tipo_dios) {
    int contador_dioses = 0;

    for (int i = 0; i < tope_filas; i++) {
        for (int j = 0; j < tope_columnas; j++) {
            if (formacion[i][j] == tipo_dios) contador_dioses++;
        }
    }

    if (contador_dioses >= cantidad_dioses) {
        int reemplazados = 0;
        for (int i = 0; i < tope_filas && reemplazados < cantidad_dioses; i++) {
            for (int j = 0; j < tope_columnas && reemplazados < cantidad_dioses; j++) {
                if (formacion[i][j] == tipo_dios) {
                    formacion[i][j] = NO_DIOS;
                    reemplazados++;
                }
            }
        }
    } else return false;

    return true;
}