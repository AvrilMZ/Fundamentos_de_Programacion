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