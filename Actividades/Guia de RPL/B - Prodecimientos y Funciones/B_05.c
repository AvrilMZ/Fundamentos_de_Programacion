/*En la mansión de los aristogatos, el mayordomo Edgar ha estado dando vuelta el papel higiénico de los baños para evitar que los gatitos, Marie, Berlioz, y Toulouse, jueguen tirando del mismo. Como los michis no tienen patas suficientemente grandes como para dar vuelta el papel, te han pedido ayuda para revisar los baños de la mansión y dar vuelta aquellos papeles que Edgar haya puesto al revés. En caso de que no haya papel higiénico, no se debe hacer nada para evitar que Edgar, cuando vaya a colocar papel higiénico, descubra que los gatitos han estado tocando el mismo.

Se pide:
Implementar un procedimiento que dado por parámetro la orientación del papel higiénico, cambie esta misma a la posición correcta si es que no lo está. Las posiciones pueden ser:
La correcta: al frente (F).
La incorrecta: al reverso (R).
Sin papel higiénico: vacío (V).
Pensá cómo debería pasarse y recibir el parámetro de la posición al procedimiento ‘corregir_posicion_papel_higienico’ para que el cambio que hagas en este se pueda ver “por fuera” cuando termine de ejecutarse el procedimiento.*/

#include <stdio.h>

const char FRENTE = 'F';
const char REVERSO = 'R';
const char VACIO = 'V';

void corregir_posicion_papel_higienico(char* posicion) {
    if (*posicion == REVERSO){
        *posicion = FRENTE;
    }
}
