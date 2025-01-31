#include <stdio.h>
#include <stdbool.h>

#define MAX_MONEDAS 10
#define MAX_JOYAS 10
const int ANTIGUEDAD_JOYA = 5;
const char VERDE = 'V';
const char AZUL = 'A';
const char ROJO = 'R';

typedef struct joya {
    int valor;
    int antiguedad;
    char color;
} joya_t;

typedef struct moneda {
    int valor;
    bool de_oro;
} moneda_t;

typedef struct tesoro {
    moneda_t monedas[MAX_MONEDAS];
    int tope_monedas;
    joya_t joyas[MAX_JOYAS];
    int tope_joyas;
    bool desenterrado;
} tesoro_t;

int cotizacion(tesoro_t tesoro) {
    int valor_total = 0;
    for (int i = 0; i < tesoro.tope_monedas; i++) {
        if (tesoro.monedas[i].de_oro) {
            valor_total += tesoro.monedas[i].valor * 2;
        } else valor_total += tesoro.monedas[i].valor;
    }
    for (int i = 0; i < tesoro.tope_joyas; i++) {
        if (tesoro.joyas[i].antiguedad < ANTIGUEDAD_JOYA && tesoro.joyas[i].color == AZUL) {
            valor_total += tesoro.joyas[i].valor / 2;
        } else valor_total += tesoro.joyas[i].valor;
    }
    return valor_total;
}

void guardar_monedas(tesoro_t* tesoro, moneda_t moneda) {
    if (tesoro->tope_monedas < MAX_MONEDAS) {
        tesoro->monedas[tesoro->tope_monedas] = moneda;
        tesoro->tope_monedas++;
    } else printf("No se pueden agregar más monedas, el tesoro está lleno.\n");
}

int main() {
    return 0;
}