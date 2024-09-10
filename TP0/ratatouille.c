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
bool comidas_validas(char comida) {
	if ((comida == MILANESA_NAPOLITANA) || (comida == HAMBURGUESA) || (comida == PARRILLA) || (comida == RATATOUILLE)){
        return true;
    } else return false;
}

//PRE: -
//POST: La función devuelve true si el carácter representa una bebida válida, de lo contrario devuelve false.
bool bebidas_validas(char bebida) {
	if ((bebida == AGUA) || (bebida == GASEOSA) || (bebida == JUGO)){
        return true;
    } else return false;
}

//PRE: -
//POST: Devuelve el costo base total según la cantidad de comensales proporcionada.
int calculo_base(){
    int cantidad_comensales = -1;
    printf("Cuántos comensales van a ser? (Ingrese un valor entre 1 y %i)\n", MAXIMO_COMENSALES);
    scanf("%i", &cantidad_comensales);

    while (cantidad_comensales < 1 || cantidad_comensales > MAXIMO_COMENSALES){
        printf("La cantidad ingresada no está dentro de nuestro rango. ¿Cuántos comensales van a ser? (Ingrese un valor entre 1 y %i)\n", MAXIMO_COMENSALES);
        scanf("%i", &cantidad_comensales);
    }
    
    int total_base = cantidad_comensales * PRECIO_BASE;
    return total_base;
}

//PRE: "cantidad_comensales" debe ser un valor positivo.
//POST: Devuelve el costo total de la comida según la opción elegida y la cantidad de comensales.
int calculo_comida(int cantidad_comensales){
    char comida_elegida = 'Z';
    printf("¿Qué desean comer? (Ingrese M, H, P ó R)\n");
    scanf(" %c", &comida_elegida);
    
    while (comidas_validas(comida_elegida) == false){
        printf("El carácter ingresado no está en nuestro menú. ¿Qué desean comer? (Ingrese M, H, P ó R)\n");
        scanf(" %c", &comida_elegida);
    }

    int total_comida = 0;
    switch (comida_elegida){
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

//PRE: "cantidad_comensales" debe ser un valor positivo.
//POST: Devuelve el costo total de la bebida según la opción elegida y la cantidad de comensales.
int calculo_bebida(int cantidad_comensales){
    char bebida_elegida = 'Z';
    printf("¿Qué desean beber? (Ingrese A, G, ó J)\n");
    scanf(" %c", &bebida_elegida);

    while (bebidas_validas(bebida_elegida) == false){
        printf("El carácter ingresado no está en nuestro menú. ¿Qué desean beber? (Ingrese A, G, ó J)\n");
        scanf(" %c", &bebida_elegida);
    }

    int total_bebida = 0;
    switch (bebida_elegida){
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

//PRE: "total_base", "total_comida" y "total_bebida" deben ser valores positivos.
//POST: Devuelve el monto total de la propina, calculado como un porcentaje específico del total final.
int calculo_propina(int total_base, int total_comida, int total_bebida){
    int total_final = total_base + total_comida + total_bebida;
    int total_propina = (total_final * PORCENTAJE_PROPINA) / 100;
    return total_propina;
}

//PRE: -
//POST: Imprime el costo total de la cuenta, incluyendo un detallado de los gastos y la propina.
void calculo_total(int total_base, int total_comida, int total_bebida, int total_propina){
    int precio_final = total_base + total_comida + total_bebida + total_propina;
    printf("Con los platos ($%i), las bebidas solicitadas ($%i) y la propina incluida de un %i%c ($%i) el total de su cuenta es: -$%i-.",
    total_base + total_comida, total_bebida, PORCENTAJE_PROPINA, '%', total_propina, precio_final);
}



int main(){
    int base = calculo_base();
    int cantidad_comensales = base / PRECIO_BASE;
    int comida = calculo_comida(cantidad_comensales);
    int bebida = calculo_bebida(cantidad_comensales);
    int propina = calculo_propina(base, comida, bebida);
    calculo_total(base, comida, bebida, propina);

    return 0;
}