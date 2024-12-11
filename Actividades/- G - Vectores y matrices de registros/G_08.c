/*Experimentando con la fotocopiadora clonadora de la Cabaña del Misterio, Dipper descubrió que puede darle a sus clones características un tanto distintas a las suyas. Él ve esto como una oportunidad de poder alterarlos lo suficiente como para que no se intenten revelar, por lo que nos pide ayuda con su experimento. Él ya ingresó la cantidad de clones que necesita en la impresora y solo falta copiar los datos del Dipper original en estos, pero vamos a darle a cada uno un nivel de paciencia diferente, para poder ver con cual son más cooperativos.

Realizar una función que dada una matriz de clones, sus respectivos topes y la información del Dipper original, rellene toda la matriz con la información del original. Solo se pide cambiar la paciencia, la cual debe ser calculada como ‘fila * columna’ para cada clon.

Notas:
La matriz puede NO ser cuadrada.
Cada clon o Dipper tiene los siguientes datos:
    Imaginación (entero).
    Paciencia (entero).
    Conocimiento (entero).
    Es clon (booleano).
Tener en cuenta que el Dipper que se pasa por parámetro es el original, por lo tanto su booleano de si es clon va a estar en false, pero todos los de la matriz son clones, por lo que su booleano debe estar en true.*/

#include <stdio.h>
#include <stdbool.h>
#define MAX_FILAS 50
#define MAX_COLUMNAS 50

typedef struct dipper {
    int imaginacion;
    int paciencia;
    int conocimiento;
    bool es_clon;
} dipper_t;

void inicializar_clones(dipper_t clones[MAX_FILAS][MAX_COLUMNAS], int tope_filas, int tope_columnas, dipper_t original){
    for (int i = 0; i < tope_filas; i++) {
        for (int j = 0; j < tope_columnas; j++) {
            clones[i][j] = original;
            clones[i][j].es_clon = true;
            clones[i][j].paciencia = i * j;
        }
    }
}