#include <stdio.h>
#include <stdbool.h>

const char CALIDAD_EXCELENTE = 'E';
const char CALIDAD_ESTANDAR = 'N';
const char CALIDAD_BAJA = 'B';
const char SI = 'S';
const char NO = 'X';
const int PRECIO_EXCELENTE_CALIDAD = 1000;
const int PRECIO_ESTANDAR_CALIDAD = 500;
const int PRECIO_BAJA_CALIDAD = 300;
const int CANTIDAD_RUEDAS_AUTO = 4;

/* PRE: -
   POST: Devuelve un char valido, ingresado por el usuario, correspondiente a una calidad de rueda.*/
char consulta_calidad() {
    bool es_caracter_valido = false;
    char calidad_ingresada = ' ';
    while (!es_caracter_valido) {
        printf("¿De que calidad quiere sus ruedas? (Ingrese '%c', '%c' ó '%c')\n", CALIDAD_EXCELENTE, CALIDAD_ESTANDAR, CALIDAD_BAJA);
        scanf(" %c", &calidad_ingresada);
        if (calidad_ingresada == CALIDAD_EXCELENTE || calidad_ingresada == CALIDAD_ESTANDAR || calidad_ingresada == CALIDAD_BAJA) es_caracter_valido = true;
    }
    return calidad_ingresada;
}

/* PRE: -
   POST: Devuelve la cantidad de ruedas ingresada por el usuario.*/
int consulta_cantidad_ruedas() {
    int cantidad_ingresada = -1;
    printf("¿Cuantas ruedas quiere cambiar?\n");
    scanf("%i", &cantidad_ingresada);
    return cantidad_ingresada;
}

/* PRE: -
   POST: Devuelve el precio por rueda ingresado por el usuario.*/
int consulta_precio_por_rueda() {
    int precio_ingresado = -1;
    printf("¿Cuál es el valor por rueda del cambio?\n");
    scanf("%i", &precio_ingresado);
    return precio_ingresado;
}

/* PRE: 'calidad_ruedas' debe ser un char valido.
   POST: Devuelve 'CANTIDAD_RUEDAS_AUTO' por 'calidad_ruedas' pasada por parámetro.*/
int precio_cambio_auto(char calidad_ruedas) {
    if (calidad_ruedas == CALIDAD_EXCELENTE) return PRECIO_EXCELENTE_CALIDAD * CANTIDAD_RUEDAS_AUTO;
    else if (calidad_ruedas == CALIDAD_ESTANDAR) return PRECIO_ESTANDAR_CALIDAD * CANTIDAD_RUEDAS_AUTO;
    else if (calidad_ruedas == CALIDAD_BAJA) return PRECIO_BAJA_CALIDAD * CANTIDAD_RUEDAS_AUTO;
}

/* PRE: 'calidad_ruedas' debe ser un char valido.
   POST: Devuelve 'precio_por_rueda' por 'cantidad_ruedas' pasadas por parámetro.*/
int precio_cambio_personalizado(int cantidad_ruedas, int precio_por_rueda) {
    return precio_por_rueda * cantidad_ruedas;
}

/* PRE: -
   POST: Devuelve 'true' si quiere un cambio de ruedas personalizado, de lo contrario, devuelve false.*/
bool es_cambio_personalizado() {
    bool es_caracter_valido = false;
    char respuesta_ingresada = ' ';
    while (!es_caracter_valido) {
        printf("¿Quiere un cambio de ruedas personalizado? (Ingrese %c ó %c)\n", SI, NO);
        scanf(" %c", &respuesta_ingresada);
        if (respuesta_ingresada == SI || respuesta_ingresada == NO) es_caracter_valido = true;
    }
    if (respuesta_ingresada == SI) return true;
    else return false;
}

int main() {
    int precio_total = -1;
    if (es_cambio_personalizado()) {
        precio_total = precio_cambio_personalizado(consulta_cantidad_ruedas(), consulta_precio_por_rueda());
    } else {
        precio_total = precio_cambio_auto(consulta_calidad());
    }
    printf("El total de su cambio de ruedas es $%i\n", precio_total);

    return 0;
}