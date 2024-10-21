#define MAX_FILAS 4
#define MAX_COLUMNAS 5

const char ENEMIGO = 'E';
const char VACIO = '-';

void distanciar_formacion(char formacion[MAX_FILAS][MAX_COLUMNAS], int* tope_filas, int* tope_columnas) {
    for (int i = 0; i < *tope_filas; i++) {
        int posicion = 0; 
        int enemigos_count = 0; 

        for (int j = 0; j < *tope_columnas; j++) {
            if (formacion[i][j] == ENEMIGO) enemigos_count++;
        }

        int nuevo_tamano = enemigos_count + (enemigos_count - 1);
        
        if (nuevo_tamano > MAX_COLUMNAS) nuevo_tamano = MAX_COLUMNAS;

        for (int j = 0; j < *tope_columnas && posicion < nuevo_tamano; j++) {
            if (formacion[i][j] == ENEMIGO) {
                formacion[i][posicion++] = ENEMIGO;
                if (posicion < nuevo_tamano) {
                    formacion[i][posicion++] = VACIO; 
                }
            }
        }

        if (nuevo_tamano < *tope_columnas) *tope_columnas = nuevo_tamano;

        while (posicion < *tope_columnas) {
            formacion[i][posicion++] = VACIO;
        }

        if (nuevo_tamano > MAX_COLUMNAS) {
            for (int j = nuevo_tamano; j < *tope_columnas; j++) formacion[i][j] = VACIO;
        }
    }
}