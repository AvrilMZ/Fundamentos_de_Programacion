#include <stdio.h>
#include <stdbool.h>

const char LUNES = 'L';
const char MARTES = 'M';
const char MIERCOLES = 'X';
const char JUEVES = 'J';
const char VIERNES = 'V';
const char SABADO = 'S';
const char DOMINGO = 'D';

bool estan_trabajando(char dia) {
	if ((dia == LUNES) || (dia == MIERCOLES) || (dia == VIERNES) || (dia == DOMINGO)){
        return true;
    } else return false;
}

bool puede_atacar(char dia, int horas_que_durmio) {
    bool laburo = estan_trabajando(dia);

    if ((horas_que_durmio >= 8) && (laburo == true)){
        return true;
    } else return false;
}