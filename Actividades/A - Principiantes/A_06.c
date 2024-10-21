/*Chip y Dale tienen ganas de irse de vacaciones, pero no se deciden ni cuándo ni a dónde ir. Por esta razón, acordaron sortear la época en la que irán (Enero (E) o febrero (F)), y el paisaje que tendrán a la vista (Montaña (M) o playa (P)). De acuerdo a lo que salga, uno de los dos elegirá el destino.

-Crear un programa que a partir de los resultados del sorteo, imprima por pantalla “Dale” si le toca elegir a él, o “Chip ” en caso contrario.
Dale elige cuando el mes es Enero y la vista es Montaña o cuando el mes es Febrero y la vista Playa. En otro caso, elige Chip.

Ejemplo:
enero
si es montaña elige Dale
si es playa elige Chip*/

#include <stdio.h>

const char ENERO = 'E';
const char FEBRERO = 'F';
const char MONTAÑA = 'M';
const char PLAYA = 'P';

int main(){
	char epoca = '.';
	char paisaje = '.';
	scanf(" %c", &epoca);
	scanf(" %c", &paisaje);
	
    if ((epoca == ENERO && paisaje == MONTAÑA) || (epoca == FEBRERO && paisaje == PLAYA)){
        printf("%s", "Dale \n");
    } else printf("%s", "Chip \n");

	return 0;
}