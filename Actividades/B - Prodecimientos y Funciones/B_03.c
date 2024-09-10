#include "solucion.h"

const char EXCELENTE = 'A';
const char BUENO = 'B';
const char MALO = 'C';
const char PESIMO = 'D';

#define AMORTIGUAMIENTO 3

int volumen_amortiguado(int volumen) {
    return (volumen / AMORTIGUAMIENTO);
}

char calcular_calidad_auriculares(int volumen) {
    int calidad = volumen_amortiguado(volumen);
    if (calidad <= 10){
        return EXCELENTE;
    }else if ((calidad > 10) && (calidad <= 40)){
        return BUENO;
    }else if ((calidad > 40) && (calidad <= 70)){
        return MALO;
    }else return PESIMO;
}