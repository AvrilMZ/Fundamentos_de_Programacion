/*Bolt se dió cuenta que Penny tiene anotado en un vector la cantidad de comida que le da por día en toda la semana, y quiere alterar un poco los números, ya que se dió cuenta que los días que más hambre tiene, son los días que menos recibe.

-Implementar un procedimiento que cree un nuevo vector para reemplazar el anterior, intercambiando la cantidad de comida que recibe los lunes, por los viernes, y la cantidad de comida que recibe los domingos, por los miércoles.
Las posiciones del vector representan los días de semana comenzando por el domingo en la posición 0.

Tener en cuenta:
Las posiciones del vector representan los días de semana comenzando por el domingo en la posición 0.
Ambos vectores tienen de tope el MAX_DIAS siempre. Es decir, siempre vienen con 7 elementos, ni más ni menos.

Ejemplo:
Teniendo el vector de comidas originales [1, 4, 6, 2, 5, 1, 7] el vector de comidas intercambiadas debe quedar [2, 1, 6, 1, 5, 4, 7].*/

#define MAX_DIAS  7

const int DOMINGO = 0;
const int LUNES = 1;
const int MIERCOLES = 3;
const int VIERNES = 5;

void intercambiar_comidas(int comidas_original[MAX_DIAS], int comidas_intercambiadas[MAX_DIAS]){
    for (int i = 0; i < MAX_DIAS; i++){
        if (i == LUNES){
            comidas_intercambiadas[LUNES] = comidas_original[VIERNES];
        } else if (i == VIERNES){
            comidas_intercambiadas[VIERNES] = comidas_original[LUNES];
        } else if (i == DOMINGO){
            comidas_intercambiadas[DOMINGO] = comidas_original[MIERCOLES];
        } else if (i == MIERCOLES){
            comidas_intercambiadas[MIERCOLES] = comidas_original[DOMINGO];
        } else comidas_intercambiadas[i] = comidas_original[i];
    }
}