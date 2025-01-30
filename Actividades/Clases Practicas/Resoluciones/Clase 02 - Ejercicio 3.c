#include <stdio.h>
#include <stdbool.h>

const int PRECIO_CHUPETIN = 100;
const int PRECIO_CARAMELO = 30;
const int PRECIO_CHICLE = 50;
const int PRECIO_BOLSA_ROSA = 40;
const int PRECIO_BOLSA_CELESTE = 50;
const int PRECIO_BOLSA_VERDE = 20;
const char ROSA = 'R';
const char CELESTE = 'C';
const char VERDE = 'V';

/* PRE: 'cantidad_chupetines', 'cantidad_caramelos' y 'cantidad_chicles' deben estar previamente inicializados.
   POST: Actualiza los valores 'cantidad_chupetines', 'cantidad_caramelos' y 'cantidad_chicles' por los ingresados por el usuario.*/
void pregunta_cantidad_golosina(int* cantidad_chupetines, int* cantidad_caramelos, int* cantidad_chicles) {
    printf("¿Cuantos chupetines queres?\n");
    scanf("%i", cantidad_chupetines);
    printf("¿Cuantos caramelos queres?\n");
    scanf("%i", cantidad_caramelos);
    printf("¿Cuantos chicles queres?\n");
    scanf("%i", cantidad_chicles);
}

/* PRE: -
   POST: Devuelve true si 'color' es valido, de lo contrario, devuelve false.*/
bool es_color_bolsita_valido(char color) {
    return (color == ROSA || color == CELESTE || color == VERDE);
}

/* PRE: 'color' debe estar previamente inicalizado con una opción invalida.
   POST: Actualiza 'color' por el char ingresado por el usuario, en caso de ser valido.*/
void pregunta_color_bolsita(char* color) {
    while (!es_color_bolsita_valido(*color)) {
        printf("¿Qué color de bolsita queres? (Ingrese %c, %c ó %c)\n", ROSA, CELESTE, VERDE);
        scanf(" %c", color);
    }
}

/* PRE: -
   POST: Devuelve la suma de los costos totales entre las golosinas y la bolsita.*/
int costo_invitado(char color_bolsita, int cantidad_chupetines, int cantidad_caramelos, int cantidad_chicles){
    int chupetines = cantidad_chupetines * PRECIO_CHUPETIN;
    int caramelos = cantidad_caramelos * PRECIO_CARAMELO;
    int chicles = cantidad_chicles * PRECIO_CHICLE;

    int precio_bolsa = -1;
    if (color_bolsita == ROSA) precio_bolsa = PRECIO_BOLSA_ROSA;
    else if (color_bolsita == CELESTE) precio_bolsa = PRECIO_BOLSA_CELESTE;
    else precio_bolsa = PRECIO_BOLSA_VERDE;

    return (chupetines + caramelos + chicles + precio_bolsa);
}

int main() {
    int cantidad_chupetines = -1;
    int cantidad_caramelos = -1;
    int cantidad_chicles = -1;
    int total_invitado = -1;
    char color_bolsa = ' ';

    pregunta_cantidad_golosina(&cantidad_chupetines, &cantidad_caramelos, &cantidad_chicles);
    pregunta_color_bolsita(&color_bolsa);
    total_invitado = costo_invitado(color_bolsa, cantidad_chupetines, cantidad_caramelos, cantidad_chicles);
    
    printf("El total del invitado es $%i\n", total_invitado);

    return 0;
}