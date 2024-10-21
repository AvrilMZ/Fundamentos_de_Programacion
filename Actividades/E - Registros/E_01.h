/*Los enemigos de Disney, siguiendo con su idea de derrotar a los enemigos, decidieron que iba a ser más práctico si se ordenaban según sus habilidades. Para esto, necesitan de alguna forma tener un registro de cada uno con sus respectivas características.

Implementar un registro donde se puedan guardar los siguientes datos de los enemigos:
    nombre: máx 50 caracteres.
    edad.
    fuerza: puede ser F, M o D ((F)uerte, (M)edia, (D)ebil).
    tiene_poderes: si tiene poderes o no.
    informacion_adicional: máx 50 caracteres.

Aclaración:
Respetá el orden dado.
No utilices tíldes ni mayúsculas.
Tené en cuenta que los vectores son strings.*/

#include <stdbool.h>

#define MAX_CARACTERES_NOMBRE 50
#define MAX_CARACTERES_INFO 50

typedef struct enemigo{
	char nombre[MAX_CARACTERES_NOMBRE];
    int edad;
    char fuerza;
    bool tiene_poderes;
    char informacion_adicional[MAX_CARACTERES_INFO];
} enemigo_t;