/*Todos los enemigos de Disney se juntaron para finalmente derrotar a sus oponentes.
Ya tenían hasta formaciones hechas y todo, el tema es que ahora con la pandemia tienen que redistribuirse en sus formaciones para así lograr respetar el distanciamiento social.
Para poder organizarse pusieron sus formaciones en una matriz, donde en cada posición puede haber un enemigo (E) o un espacio vacío (-). Ahora solo necesitan reacomodarse, pero como no tienen mucho tiempo decidieron respetar el distanciamiento solo en las filas, por lo que no les importará si quedan dos enemigos aledaños en alguna columna (no entendieron nada me parece, pero bueno).

Implementar una función que por fila separe a los enemigos. Esto quiere decir agregar un espacio vacío (-) entre cada par de enemigos que se encuentren aledaños. Por lo que si se tiene EE se debe distanciar dejandolos E-E. Es posible que el distanciamiento agrande la matriz de la formación, por lo que también hay que actualizar los topes según corresponda.

Tener en cuenta:
Si es necesario hay que actualizar los topes de la matriz, siempre respetando los máximos.
Si no es posible respetar el distanciamiento social porque se va de los máximos de la matriz, entonces todos los enemigos que al distanciar queden por afuera de los máximos son matados. Eehh… Digo… Se los saca de la formación.
Si un par de enemigos ya está distanciado con uno o más lugares vacíos entre ellos, no hace falta agregar distancia.
Si sobran lugares en una fila se rellena con vacíos al final de esta misma.

Ejemplo:
Teniendo una matriz de topes 3x4 con máximos 3x5:
EE-E
--E-
EEEE
Al aplicar el distanciamiento debería quedar una matriz de 3x5:
E-E-E
--E--
E-E-E
Notar que:
A la segunda fila se la rellenó con un vacío al final.
En la última fila se "mató" al ultimo enemigo porque no entraba, ups.*/

#define MAX_FILAS 4
#define MAX_COLUMNAS 5

const char ENEMIGO = 'E';
const char VACIO = '-';

void distanciar_formacion(char formacion[MAX_FILAS][MAX_COLUMNAS], int* tope_filas, int* tope_columnas) {
    for (int i = 0; i < *tope_filas; i++) {
        int posicion = 0; 
        int enemigos_count = 0; 

        for (int j = 0; j < *tope_columnas; j++) {
            if (formacion[i][j] == ENEMIGO) enemigos_count++;
        }

        int nuevo_tamano = enemigos_count + (enemigos_count - 1);
        
        if (nuevo_tamano > MAX_COLUMNAS) nuevo_tamano = MAX_COLUMNAS;

        for (int j = 0; j < *tope_columnas && posicion < nuevo_tamano; j++) {
            if (formacion[i][j] == ENEMIGO) {
                formacion[i][posicion++] = ENEMIGO;
                if (posicion < nuevo_tamano) {
                    formacion[i][posicion++] = VACIO; 
                }
            }
        }

        if (nuevo_tamano < *tope_columnas) *tope_columnas = nuevo_tamano;

        while (posicion < *tope_columnas) {
            formacion[i][posicion++] = VACIO;
        }

        if (nuevo_tamano > MAX_COLUMNAS) {
            for (int j = nuevo_tamano; j < *tope_columnas; j++) formacion[i][j] = VACIO;
        }
    }
}