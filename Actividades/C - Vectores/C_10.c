/*En la guardería SunnySide, los juguetes tienen una lista con la cantidad de juguetes con los que jugaron lo largo de los días.
Los juguetes tiene ganas de nombrar un día como el "Dia del juego", pero quieren que el día que sea elegido sea muy especial y tenga un significado. Por lo que no tuvieron mejor idea que elegir el día con mayor juguetes agarrados para poder conmemorarlo.

Un día es considerado día record si la cantidad de juguetes con los que jugaron en un día es mayor o igual a cualquiera de los dias anteriores.
Teniendo un vector que represente los días en números de una semana (0=domingo,1=lunes,2=martes…), y cada posición represente la cantidad total de adopciones concretadas en ese día:
Implementar una función que devuelva cuál es el día record de juego.

Aclaraciones:
-En caso de empate entre dos días, se considerará el día más cercano a la fecha como el día ganador.

Ejemplo:
Si se recibe el vector [54,12,23,8,30,60,44], la mayor cantidad de juguetes usado es 60, por lo que el día record sería el 5 (viernes)*/

#include <stdio.h>
#define MAXIMOS_DIAS 7

const int DOMINGO = 0;
const int LUNES = 1;
const int MARTES = 2;
const int MIERCOLES = 3;
const int JUEVES = 4;
const int VIERNES = 5;
const int SABADO = 6;

int dia_record(int usados[MAXIMOS_DIAS], int tope){
    int dia_ganador = -1;
    for (int i = 0; i < tope; i++){
        if (usados[i] >= usados[dia_ganador]){
            dia_ganador = i;
        }
    }
    return dia_ganador;
}