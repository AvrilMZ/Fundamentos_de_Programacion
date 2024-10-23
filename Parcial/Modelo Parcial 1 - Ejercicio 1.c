#include <string.h>
#include <stdbool.h>

#define MAX 20 //EJEMPLO
#define MAX_FIL 10 //EJEMPLO
#define MAX_COL 10 //EJEMPLO

const char* COLOR_CORRECTO = "ROJO";

typedef struct puerta {
    bool luz_prendida;
    char color[MAX];
    int grito_acumulado;
} puerta_t;

//PRE: La matriz 'puertas' no debe estar vacia y 'tope_fil' y 'tope_col' deben ser estrictamente mayores a cero.
//POST: Devuelve que columna tuvo el record de mas gritos realizados, tomando en cuenta unicamente las puertas rojas y con la luz prendida.
int sumatoria_gritos(puerta_t puertas[MAX_FIL][MAX_COL], int tope_fil, int tope_col) {
    int record_gritos = 0;
    int col_record = -1;

    for (int i = 0; i < tope_col; i++) {
        int gritos_col_actual = 0;

        for (int j = 0; j < tope_fil; j++) {
            if (puertas[i][j].luz_prendida == true && strcmp(puertas[i][j].color, COLOR_CORRECTO) == 0) {
                gritos_col_actual += puertas[i][j].grito_acumulado;
            }
        }

        if (gritos_col_actual > record_gritos) {
            record_gritos = gritos_col_actual;
            col_record = i;
        }
    }

    return col_record;
}