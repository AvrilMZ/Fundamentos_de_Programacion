#include <stdio.h>
#include <stdbool.h>

#define MILANESA_NAPOLITANA 'M'
#define HAMBURGUESA 'H'
#define PARRILLA 'P'
#define RATATOUILLE 'R'
#define AGUA 'A'
#define GASEOSA 'G'
#define JUGO 'J'

const int PRECIO_BASE = 15500;
const int PRECIO_MILANESA_NAPOLITANA = 200;
const int PRECIO_HAMBURGUESA = 0;
const int PRECIO_PARRILLA = 3000;
const int PRECIO_RATATOUILLE = 5000;
const int PRECIO_GASEOSA = 2505;
const int PRECIO_JUGO = 2505;
const int PRECIO_AGUA = 2005;
const int MAXIMO_COMENSALES = 5;
const int PORCENTAJE_PROPINA = 10;

//PRE: -
//POST: La función devuelve true si el carácter representa una comida válida, de lo contrario devuelve false.
bool es_comida_valida(char comida) {
	return ((comida == MILANESA_NAPOLITANA) || (comida == HAMBURGUESA) || (comida == PARRILLA) || (comida == RATATOUILLE));
}

//PRE: -
//POST: La función devuelve true si el carácter representa una bebida válida, de lo contrario devuelve false.
bool es_bebida_valida(char bebida) {
	return ((bebida == AGUA) || (bebida == GASEOSA) || (bebida == JUGO));
}

//PRE: El puntero 'cantidad_comensales' debe estar previamente inicializado.
//POST: Actualiza el valor apuntado por el puntero 'cantidad_comensales' con una cantidad válida de comensales.
void eleccion_cantidad_comensales(int* cantidad_comensales) {
    printf("Cuántos comensales van a ser? (Ingrese un valor entre 1 y %i)\n", MAXIMO_COMENSALES);
    scanf("%i", cantidad_comensales);

    while (*cantidad_comensales < 1 || *cantidad_comensales > MAXIMO_COMENSALES) {
        printf("La cantidad ingresada no está dentro de nuestro rango. ¿Cuántos comensales van a ser? (Ingrese un valor entre 1 y %i)\n", MAXIMO_COMENSALES);
        scanf("%i", cantidad_comensales);
    }
}

//PRE: -
//POST: Devuelve el costo base total según la cantidad de comensales proporcionada.
int calcular_base(){
    int cantidad_comensales = -1;
    eleccion_cantidad_comensales(&cantidad_comensales);

    return cantidad_comensales * PRECIO_BASE;
}

//PRE: El puntero 'comida_electa' debe estar previamente inicializado.
//POST: Actualiza el valor apuntado por el puntero 'comida_electa' con una elección válida de comida.
void eleccion_comida(char* comida_electa) {
    printf("¿Qué desean comer? (Ingrese %c, %c, %c o %c)\n", MILANESA_NAPOLITANA, HAMBURGUESA, PARRILLA, RATATOUILLE);
    scanf(" %c", comida_electa);
    
    while (!es_comida_valida(*comida_electa)) {
        printf("El carácter ingresado no está en nuestro menú. ¿Qué desean comer? (Ingrese %c, %c, %c o %c)\n", MILANESA_NAPOLITANA, HAMBURGUESA, PARRILLA, RATATOUILLE);
        scanf(" %c", comida_electa);
    }
}

//PRE: 'cantidad_comensales' debe ser un valor positivo.
//POST: Devuelve el costo total de la comida según la opción electa y la cantidad de comensales.
int calcular_comida(int cantidad_comensales) {
    char comida_electa = ' ';
    eleccion_comida(&comida_electa);

    int total_comida = 0;
    switch (comida_electa) {
        case MILANESA_NAPOLITANA:
            total_comida += PRECIO_MILANESA_NAPOLITANA;
            break;
        case HAMBURGUESA:
            total_comida += PRECIO_HAMBURGUESA;
            break;
        case PARRILLA:
            total_comida += PRECIO_PARRILLA;
            break;
        case RATATOUILLE:
            total_comida += PRECIO_RATATOUILLE;
            break;
    }

    return total_comida * cantidad_comensales;
}

//PRE: El puntero 'bebida_electa' debe estar previamente inicializado.
//POST: Actualiza el valor apuntado por el puntero 'bebida_electa' con una elección válida de bebida.
void eleccion_bebida(char* bebida_electa) {
    printf("¿Qué desean beber? (Ingrese %c, %c, o %c)\n", AGUA, GASEOSA, JUGO);
    scanf(" %c", bebida_electa);

    while (!es_bebida_valida(*bebida_electa)) {
        printf("El carácter ingresado no está en nuestro menú. ¿Qué desean beber? (Ingrese %c, %c, o %c)\n", AGUA, GASEOSA, JUGO);
        scanf(" %c", bebida_electa);
    }
}

//PRE: 'cantidad_comensales' debe ser un valor positivo.
//POST: Devuelve el costo total de la bebida según la opción electa y la cantidad de comensales.
int calcular_bebida(int cantidad_comensales) {
    char bebida_electa = ' ';
    eleccion_bebida(&bebida_electa);

    int total_bebida = 0;
    switch (bebida_electa) {
        case AGUA:
            total_bebida += PRECIO_AGUA;
        break;

        case GASEOSA:
            total_bebida += PRECIO_GASEOSA;
        break;

        case JUGO:
            total_bebida += PRECIO_JUGO;
        break;
    }

    return total_bebida * cantidad_comensales;
}

//PRE: -
//POST: Devuelve el monto total de la propina, calculado como un porcentaje específico del total final.
int calcular_propina(int total_base, int total_comida, int total_bebida) {
    return ((total_base + total_comida + total_bebida) * PORCENTAJE_PROPINA) / 100;
}

//PRE: -
//POST: Imprime el costo total de la cuenta, incluyendo un detallado de los gastos y la propina.
void calcular_total(int total_base, int total_comida, int total_bebida, int total_propina) {
    int precio_final = total_base + total_comida + total_bebida + total_propina;
    printf("Con los platos ($%i), las bebidas solicitadas ($%i) y la propina incluida de un %i%c ($%i) el total de su cuenta es: -$%i-\n",
    total_base + total_comida, total_bebida, PORCENTAJE_PROPINA, '%', total_propina, precio_final);
}

int main() {
    int base = calcular_base();
    int cantidad_comensales = base / PRECIO_BASE;
    int comida = calcular_comida(cantidad_comensales);
    int bebida = calcular_bebida(cantidad_comensales);
    int propina = calcular_propina(base, comida, bebida);
    calcular_total(base, comida, bebida, propina);

    return 0;
}