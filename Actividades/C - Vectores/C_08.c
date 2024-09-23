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