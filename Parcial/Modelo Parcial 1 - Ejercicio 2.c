#define MAX_ENANITO 20
#define MAX_ENANOS 5

const int ULTIMO_ENANO = -1;

typedef struct enanito {
char nombre[MAX_ENANITO];
int proximo_enanito;
int fuerza;
} enanito_t;

/*PRE: 
    - El vector 'enanos' no debe estar vacio.
    - 'enano_siguiente' y 'posicion_fuerza_minima' deberia ser cero inicialmente para recorrer correctamente el vector 'enanos'.
    - 'fuerza_minima' debe ser mayor o igual a cero.
    - Debe haber un elemento dentro del vector cuyo 'proximo_enanito' sea -1.
  POST: Devuelve la posicion en 'enanos' con menos fuerza.*/
int enanito_mas_debil(enanito_t enanos[MAX_ENANOS], int enano_siguiente, int fuerza_minima, int posicion_fuerza_minima) {
    if (enano_siguiente == ULTIMO_ENANO) {
        return posicion_fuerza_minima;
    }

    if (enanos[enano_siguiente].fuerza < fuerza_minima) {
        posicion_fuerza_minima = enano_siguiente;
        fuerza_minima = enanos[enano_siguiente].fuerza;
    } 
    
    enanito_mas_debil(enanos, enanos[enano_siguiente].proximo_enanito, fuerza_minima, posicion_fuerza_minima);
}