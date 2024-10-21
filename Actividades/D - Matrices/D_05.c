#define MAX_FILAS 10
#define MAX_COLUMNAS 10

const int LUGAR_VACIO = 0;

void predecir_cabeza(unsigned int hidra[MAX_FILAS][MAX_COLUMNAS], unsigned int tope_fil, unsigned int tope_col, unsigned int id, unsigned int largo, int fila){
    for (int i = 0; i < tope_fil; i++) {
        if (i == fila) {
            for (int j = 0; j < largo; j++) {
                hidra[i][j] = id;
            }
        }
    }
}