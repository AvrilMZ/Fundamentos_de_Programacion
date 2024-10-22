/*Bonnie ama jugar, y como consecuencia, ama los juguetes. Tanto que cada día que pasa su grupo de amigos inanimados crece más y más. Tanto que su mamá pierde la cuenta, y es muy importante que pueda mantener la cuenta de estos amigos para así cuando tienen que irse de viaje, no se olvide de guardar ninguno en la valija. Ya pasó una vez y no se quiere arriesgar nuevamente.

Implementar un procedimiento que dado un vector de juguetes, junto con su tope, y los datos de un nuevo juguete, sume a este último al final del vector.

Notas:
Los juguetes están representados por un registro que contiene los siguientes datos:
    Nombre (string).
    Guardado (booleano).
Los nuevos juguetes siempre están guardados, ya que son los primeros que agarra Bonnie. Como consecuencia, no es necesario que te pasen este dato en la función, deberías inicializarlo vos.
Recordar que el nuevo juguete se agrega al final del vector.

Ejemplo:
Teniendo un vector con un elemento (tope = 1), y pasando el nombre “Woody”, al finalizar de ejecutar nuestra función el vector debe haber quedado con dos elementos (tope = 2) y en su última posición tener el juguete de nombre “Woody”, el cual se encuentra guardado (guardado = true).*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define MAX_JUGUETES 200
#define MAX_NOMBRE 144

typedef struct jueguete{
    char nombre[MAX_NOMBRE];
    bool guardado;
} juguete_t;

void agregar_juguete(juguete_t juguetes[MAX_JUGUETES], int* tope_juguetes, char nombre[MAX_NOMBRE]){
    strcpy(juguetes[*tope_juguetes].nombre, nombre);
    juguetes[*tope_juguetes].guardado = true;
    (*tope_juguetes)++;
}