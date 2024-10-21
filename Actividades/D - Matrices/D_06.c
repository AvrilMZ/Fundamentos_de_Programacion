/*Hades, Dios del inframundo, tiene la ambición de conquistar el monte Olimpo donde viven los Dioses de la tierra. Para llevar a cabo su plan, decide liberar a un grupo de titanes. Como Hércules se encuentra ocupado peleando con un Cíclope, Zeus y el resto de los Dioses se preparan en formación para enfrentar a los titanes.

Si la formación de Dioses es representada como una matriz, y en cada posición hay un Dios que ataca a distancia (“D”), cuerpo a cuerpo (“C”), o no hay Dios (“-”), se pide:
Implementar una función que, dada la cantidad y tipo de Dioses necesarios para vencer a los titanes, devuelva true si estos serán vencidos, o false en caso contrario. Además, se debe actualizar la matriz de formación debiendo quedar la posición en la que se encuentran dichos Dioses vacía.

Tener en cuenta:
Si los Dioses no son suficientes, la matriz debe quedar como está dada originalmente.
Si los Dioses son suficientes la matriz se vacía recorriendo de arriba a bajo y de izquierda a derecha.

Ejemplo:
Se quieren 4 Dioses que peleen a distancia, y la matriz recibida es:
C D C -
- C D -
D D - D
La cantidad de Dioses que peleen a distancia es suficiente por lo que se deberá devolver true, y la matriz deberá quedar:
C - C -
- C - -
- - - D*/

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