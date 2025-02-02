#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

const char SI = 'S';
const char NO = 'N';
const int NO_TIENE_MASCOTAS = 0;
const char PERRO = 'P';
const char GATO  = 'G';
const char OTRO = 'O';

typedef struct mascota {
    char animal;
    int edad;
} mascota_t;

typedef struct hogar {
    int cant_mascotas;
    mascota_t *mascotas;
} hogar_t;

/* PRE: 'cantidad_hogares' debe ser positivo.
   POST: Reserva memoria para un vector dinámico de tipo 'hogar_t' del tamaño 'cantidad_hogares'.*/
hogar_t* crear_vector_hogares(int cantidad_hogares) {
    hogar_t* vector_hogares = malloc(sizeof(hogar_t) * (size_t)cantidad_hogares);
    if (vector_hogares == NULL) {
        printf("Error reservando memoria\n");
        return NULL;
    }
    return vector_hogares;
}

/* PRE: 'cantidad_hogares' debe ser cero o positivo.
   POST: Redimenciona el vector dinámico 'vector_hogares' agregando un elemento de tipo 'hogar_t'.*/
hogar_t* agregar_hogar(hogar_t** vector_hogares, int* cantidad_hogares) {
    hogar_t* nuevos_hogares = realloc(*vector_hogares, sizeof(hogar_t) * (size_t)(*cantidad_hogares + 1));
    if (nuevos_hogares == NULL) {
        printf("Error reservando memoria\n");
        free(*vector_hogares);
        *vector_hogares = NULL;
        return NULL;
    }
    *vector_hogares = nuevos_hogares;
    (*cantidad_hogares)++;
    return nuevos_hogares;
}

/* PRE: 'cantidad_mascotas' debe ser positivo.
   POST: Reserva memoria para un vector dinámico de tipo 'mascota_t' del tamaño 'cantidad_mascotas'.*/
mascota_t* crear_vector_mascotas(int cantidad_mascotas) {
    mascota_t* vector_mascotas = malloc(sizeof(mascota_t) * (size_t)cantidad_mascotas);
    if (vector_mascotas == NULL) {
        printf("Error reservando memoria\n");
        return NULL;
    }
    return vector_mascotas;
}

/* PRE: 'cantidad_mascotas' debe ser cero o positivo.
   POST: Redimenciona el vector dinámico 'vector_mascotas' agregando un elemento de tipo 'mascota_t'.*/
mascota_t* agregar_mascota(mascota_t** vector_mascotas, int* cantidad_mascotas) {
    mascota_t* nuevas_mascotas = realloc(*vector_mascotas, sizeof(mascota_t) * (size_t)(*cantidad_mascotas + 1));
    if (nuevas_mascotas == NULL) {
        printf("Error reservando memoria\n");
        free(*vector_mascotas);
        *vector_mascotas = NULL;
        return NULL;
    }
    *vector_mascotas = nuevas_mascotas;
    (*cantidad_mascotas)++;
    return nuevas_mascotas;
}

/* PRE: -
   POST: Actualiza el valor de cantidad_hogares por el ingresado por el usuario, si este es positivo.*/
void consultar_hogares(int* cantidad_hogares) {
    bool cantidad_valida = false;
    while (!cantidad_valida) {
        printf("¿Cuantos hogares hay?\n");
        scanf("%i", cantidad_hogares);
        if (*cantidad_hogares > 0) cantidad_valida = true;
    }
}

/* PRE: -
   POST: Consulta al usuario si tiene mascotas, en caso de ser afirmativo le pregunta cuantas y devuelve esa cantidad.*/
int consulta_mascotas() {
    char tiene_mascotas = ' ';
    int cantidad_mascotas = 0;
    bool caracter_valido = false;
    bool cantidad_valida = false;
    
    while (!caracter_valido) {
        printf("¿Tiene mascotas en su hogar? (Ingrese 'S' o 'N')\n");
        scanf(" %c", &tiene_mascotas);
        if (tiene_mascotas == SI || tiene_mascotas == NO) caracter_valido = true;
    }
    
    if (tiene_mascotas == SI) {
        while (!cantidad_valida) {
            printf("¿Cuantas mascotas tenes?\n");
            scanf("%i", &cantidad_mascotas);
            if (cantidad_mascotas > 0) cantidad_valida = true;
        }
        return cantidad_mascotas;
    }

    return NO_TIENE_MASCOTAS;
}

/* PRE: -
   POST: Actualiza los datos 'edad' y 'animal' del struct 'mascota_t' con los datos ingresados por el usuario.*/
void datos_mascota(mascota_t* mascota) {
    bool animal_valido = false;
    bool edad_valida = false;

    while (!animal_valido) {
        printf("¿Qué animal es? (Perro = 'P', Gato = 'G' u Otro = 'O')\n");
        scanf(" %c", &mascota->animal);
        if (mascota->animal == PERRO || mascota->animal == GATO || mascota->animal == OTRO) animal_valido = true;
    }

    while (!edad_valida) {
        printf("¿Que edad tiene?\n");
        scanf("%i", &mascota->edad);
        if (mascota->edad >= 0) edad_valida = true;
    }
    
}

/* PRE: 'cantidad_mascotas' debe ser cero o positivo.
   POST: Inicializa los campos del vector 'mascotas'.*/
void inicializar_mascotas(mascota_t* mascotas, int cantidad_mascotas) {
    for (int i = 0; i < cantidad_mascotas; i++) {
        datos_mascota(&mascotas[i]);
    }
}

/* PRE: -
   POST: Inicializa el vector 'hogares', asi mismo el vector 'mascotas' que contiene su tipo de dato 'hogar_t'.*/
void inicializar_hogares(hogar_t** hogares, int* cantidad_hogares) {
    consultar_hogares(cantidad_hogares);

    *hogares = crear_vector_hogares(*cantidad_hogares);
    for (int i = 0; i < *cantidad_hogares; i++) {
        printf("Hogar número %i:\n", i + 1);
        int cantidad_mascotas = consulta_mascotas();
        (*hogares)[i].cant_mascotas = cantidad_mascotas;
        (*hogares)[i].mascotas = crear_vector_mascotas(cantidad_mascotas);
        inicializar_mascotas((*hogares)[i].mascotas, cantidad_mascotas);
    }
}

/* PRE: El vector 'hogares' debe estar inicializado y su tope 'cantidad_hogares' debe ser positivo.
   POST: Libera toda la memoria reservada para un vector de tipo 'hogar_t'.*/
void liberar_memoria(hogar_t** hogares, int cantidad_hogares) {
    for (int i = 0; i < cantidad_hogares; i++) {
        free((*hogares)[i].mascotas);
    }
    free(*hogares);
    *hogares = NULL;
}

/* PRE: 'cantidad_hogares' debe ser positivo.
   POST: Calcula y devuelve el promedio de mascotas por hogar en el vector 'hogares'.*/
float cantidad_promedio_mascotas(hogar_t* hogares, int cantidad_hogares) {
    float suma_mascotas = 0;
    for (int i = 0; i < cantidad_hogares; i++) {
        suma_mascotas += hogares[i].cant_mascotas;
    }
    if (suma_mascotas == 0 && cantidad_hogares == 0) return 0;
    else return (suma_mascotas / cantidad_hogares);
}

/* PRE: -
   POST: Calcula y devuelve el promedio de edad de las mascotas en el vector 'hogares'.*/
float edad_promedio_mascotas(hogar_t* hogares, int cantidad_hogares) {
    float suma_edades = 0;
    int suma_mascotas = 0;
    for (int i = 0; i < cantidad_hogares; i++) {
        suma_mascotas += hogares[i].cant_mascotas;
        for (int j = 0; j < hogares[i].cant_mascotas; j++) {
            suma_edades += hogares[i].mascotas[j].edad;
        }
    }
    if (suma_edades == 0 && suma_mascotas == 0) return 0;
    else return (suma_edades / suma_mascotas);
}

int main() {
    hogar_t* hogares = NULL;
    int cantidad_hogares = 0;

    inicializar_hogares(&hogares, &cantidad_hogares);

    printf("La cantidad promedio de mascotas es %f.\n", cantidad_promedio_mascotas(hogares, cantidad_hogares));
    printf("La edad promedio de las mascotas es %f.\n", edad_promedio_mascotas(hogares, cantidad_hogares));

    liberar_memoria(&hogares, cantidad_hogares);

    return 0;
}