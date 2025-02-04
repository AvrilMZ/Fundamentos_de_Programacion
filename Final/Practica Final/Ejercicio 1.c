#include <stdio.h>
#include <stdbool.h>

#define MAX_OCUPANTES 20
#define MAX_PISOS 10
#define MAX_COLUMNAS 10
const char ANNIE = 'A';
const char HALLIE = 'H';
const char MEREDITH = 'M';
const char NICHOLAS = 'N';
const char ELIZABETH = 'E';
const int DISTINTO_PISO = -1;

typedef struct habitacion {
    int numero;
    char ocupantes[MAX_OCUPANTES];
    int cantidad_ocupantes;
} habitacion_t;

// PRE: 'tope_pisos' y 'tope_columnas' deben estar inicializados correctamente.
// POST: Devuelve el piso en el que 'ANNIE' y 'HALLIE' se encuentran, de no estar en el mismo devuelve 'DISTINTO_PISO'.
int piso_annie_hallie(habitacion_t hotel[MAX_PISOS][MAX_COLUMNAS], int tope_pisos, int tope_columnas) {
    int piso_encontradas = DISTINTO_PISO;
    for (int i = 0; i < tope_pisos; i++) {
        bool annie_encontrada = false;
        bool hallie_encontrada = false;
        for (int j = 0; j < tope_columnas; j++) {
            for (int k = 0; k < hotel[i][j].cantidad_ocupantes; k++) {
                if (hotel[i][j].ocupantes[k] == ANNIE) annie_encontrada = true;
                if (hotel[i][j].ocupantes[k] == HALLIE) hallie_encontrada = true;
            }
        }
        if (annie_encontrada && hallie_encontrada) piso_encontradas = i;
    }
    return piso_encontradas;
}

// PRE: 'tope_pisos' y 'tope_columnas' deben estar inicializados correctamente.
// POST: Devuleve true si 'NICHOLAS' o 'ELIZABETH' se encuentran en un piso contiguo, de lo contrario, devuelve false.
bool estan_padres_cerca(habitacion_t hotel[MAX_PISOS][MAX_COLUMNAS], int tope_pisos, int tope_columnas) {
    int piso_referencia = piso_annie_hallie(hotel, tope_pisos, tope_columnas);
    if (piso_referencia == DISTINTO_PISO) return false;

    bool padre_cerca = false;
    if (piso_referencia > 0) {
        for (int i = piso_referencia - 1; i < piso_referencia + 2; i++) {
            for (int j = 0; j < tope_columnas; j++) {
                for (int k = 0; k < hotel[i][j].cantidad_ocupantes; k++) {
                    if (hotel[i][j].ocupantes[k] == NICHOLAS || hotel[i][j].ocupantes[k] == ELIZABETH) padre_cerca = true;
                }
            }
        }
    } else {
        for (int i = piso_referencia; i < piso_referencia + 2; i++) {
            for (int j = 0; j < tope_columnas; j++) {
                for (int k = 0; k < hotel[i][j].cantidad_ocupantes; k++) {
                    if (hotel[i][j].ocupantes[k] == NICHOLAS || hotel[i][j].ocupantes[k] == ELIZABETH) padre_cerca = true;
                }
            }
        }
    }
    return padre_cerca;
}

// PRE: 'tope_pisos' y 'tope_columnas' deben estar inicializados correctamente.
// POST: Devuelve true si 'NICHOLAS' y 'MEREDITH' se encuentran en la misma habitación, de lo contrario, devuelve false.
bool nicholas_meredith_misma_habitacion(habitacion_t hotel[MAX_PISOS][MAX_COLUMNAS], int tope_pisos, int tope_columnas) {
    bool misma_habitacion = false;
    for (int i = 0; i < tope_pisos; i++) {
        for (int j = 0; j < tope_columnas; j++) {
            bool n_encontrado = false;
            bool m_encontrado = false;
            for (int k = 0; k < hotel[i][j].cantidad_ocupantes; k++) {
                if (hotel[i][j].ocupantes[k] == MEREDITH) m_encontrado = true;
                if (hotel[i][j].ocupantes[k] == NICHOLAS) n_encontrado = true;
            }
            if (m_encontrado && n_encontrado) misma_habitacion = true;
        }
    }
    return misma_habitacion;
}

// PRE: 'tope_pisos' y 'tope_columnas' deben estar inicializados correctamente.
/* POST: Devuelve true si se cumple que:
            - Annie y Hallie esten en el mismo piso;
            - Nicholas y Elizabeth no estan en pisos contiguos a Annie y Hallie;
            - Nicholas y Meredith no se encuentran en la misma habitación.*/
bool es_broma_exitosa(habitacion_t hotel[MAX_PISOS][MAX_COLUMNAS], int tope_pisos, int tope_columnas) {
    return (piso_annie_hallie(hotel, tope_pisos, tope_columnas) != DISTINTO_PISO 
    && !estan_padres_cerca(hotel, tope_pisos, tope_columnas) 
    && !nicholas_meredith_misma_habitacion(hotel, tope_pisos, tope_columnas));
}

int main() {
    return 0;
}


/*
----- PARTE TEÓRICA -----
1- ¿Qué son las pre condiciones de una función? ¿Qué son las post condiciones de una función? Dar ejemplos.
2- Explicar si la siguiente afirmación es Verdadera o Falsa y por qué: "Dado un vector y sutope, al acceder al elemento  vector[tope]  estoy accediendo a basura".

1- Las pre condiciones son condiciones que deben cumplirse antes de ejecutar una función para garantizar su correcto funcionamiento.
   Por ejemplo si la funcion realiza una division con dos numeros pasados por parametro que el divisor no sea cero.
   Las post condiciones son condiciones que deben cumplirse después de ejecutar la función, asegurando que la salida es válida y consistente con lo esperado.
   Por ejemplo una funcion que suma dos numeros positivos va a devolver un resultado positivo.
2- Verdadera, ya que el tope representa la cantidad de elementos válidos en el vector y los índices comienzan en 0, entonces el último elemento accesible sería vector[tope - 1].
*/