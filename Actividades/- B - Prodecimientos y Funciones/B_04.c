/*Luego de observar con su espejo mágico, la reina ideó un plan para engañar a Blancanieves y darle la manzana envenenada, el cual se basa en atacar el día que todos los enanitos estén trabajando, para que así no logren descubrirla. Ella sabe que todos trabajan siempre los días lunes, miércoles, viernes y domingo.
Para este ejercicio, se pide implementar tanto la función estan_trabajando como el procedimiento imprimir_plan:

Implementar la función estan_trabajando, que según un caracter devuelva true si ese día están trabajando o false en caso contrario.
Los días están representados con los siguientes caracteres:
Lunes (L).
Martes (M).
Miércoles (X).
Jueves (J).
Viernes (V).
Sábado (S).
Domingo (D).

Implementar el procedimiento puede_atacar, el cual recibe un caracter que representa el día de la semana y las horas que descansó, devolviendo true si es que todos los enanos están trabajando ese día y descansó 8 horas o más.*/

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