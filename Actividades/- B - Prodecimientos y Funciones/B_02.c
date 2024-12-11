/*En el país de Nunca jamás, todos saben que los niños no pueden convertirse en adultos. Es por esto que Peter Pan y todos sus amigos nunca terminaron de crecer, sin embargo, pareciera que Nunca Jamás comenzó a perder su magia y los chicos comenzaron a crecer. Para poder distinguir esto, se someten a los chicos a una simple prueba: se le pide que diga el primer número que le viene a la mente. Como todo el mundo sabe, los chicos solo saben contar del 1 al 10 (inclusive), por lo que si su número cae por fuera de este rango, significa que empezó a crecer.

Implementar la función 'es_adulto' la cual dado un número entero devuelva 'true' si este es igual/menor a cero o mayor a 10, y devuelva 'false' en caso contrario.*/

#include <stdio.h>
#include <stdbool.h>

bool es_adulto(int num) {
    if ((num > 0) && (num <= 10)){
        return false;
    } else return true;
}
