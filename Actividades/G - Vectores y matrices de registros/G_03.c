/*Buscando una poción para envenenar a Kuzco, Kronk tiró al piso el estante con todos los frascos. Algunos se abrieron y derramaron parte del líquido. Para que Yzma no se enoje, Kronk decidió rellenarlos.
Como solo encontró una jarra con la etiqueta "Llama" solo puede rellenar frascos con la misma etiqueta. Además debe asegurarse de contar cuántos mililitros de líquido usó para llenar los frascos para así preparar más. Cada frasco tiene capacidad de 85 ml.

Implementar una función que dado un vector de frascos: rellene a los que tienen la etiqueta "Llama" (esto es setear el campo contenido al máximo) y devuelva la cantidad de mililitros usados.

Notas:
Los frascos están representados por un registro que contiene los siguientes datos:
    Etiqueta (string).
    Contenido (int).*/

#include <stdio.h>
#include <stdbool.h>
#define MAX_ALIMENTOS 400
#define MAX_NOMBRE 144

typedef struct alimento {
    char nombre[MAX_NOMBRE];
    bool vencio;
    int puntos_mal_olor;
} alimento_t;

int cantidad_alimentos_echados_a_perder(alimento_t alimentos[MAX_ALIMENTOS], int tope){
    
}