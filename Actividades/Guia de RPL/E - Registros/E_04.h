/*El renombrado profesor Derek Knight dicta clases en la gran Monster University. Gracias a la llegada de la virtualidad y a un gran incremento de notas por parte de sus estudiantes de forma sospechosa, sospecha que estos se están copiando. Por lo que usando sus contactos en Whatsapp Inc. ha interceptado los mensajes que se envían por un grupo de estudiantes.

Estos mensajes contienen la siguiente información:
Si tiene palabras relacionadas con el colegio (bool).
Cantidad de palabras que contiene (int).
Cantidad de respuestas al mensaje (int).
Si el autor es sospechoso (bool).

Dado un mensaje del tipo mensaje_t, calcular y devolver el índice de probabilidad de que sea un mensaje con la intención de copiarse.

Aclaración:
Sabemos la probabilidad de copiarse según las siguientes reglas:
Todo mensaje empieza con una probabilidad de copia de 5 puntos.
Si el mensaje tiene palabras relacionadas al colegio, la probabilidad aumenta 2 puntos, sino disminuye 2 puntos.
Si el mensaje es muy largo (tiene más de 50 palabras, estricto) la probabilidad aumenta 2 puntos, sino disminuye 1 punto.
Si el mensaje tiene una alta cantidad de respuestas (más que 3, estricto) la probabilidad aumenta 2 puntos, sino se mantiene igual.
Si el mensaje fue escrito por un alumno cuyas calificaciones aumentaron (aka: autor sospechoso), la probabilidad aumenta 3 puntos, sino disminuye 1 punto.

Ejemplo:
Si tenemos la siguiente información del mensaje:
tiene_palabras_de_colegio = true. (aumenta 2).
cantidad_de_palabras = 50. (disminuye 1).
cantidad_de_respuestas = 2. (mantiene).
autor_sospechoso = true. (aumenta 3).
La probabilidad nos quedaría:
5 + 2 - 1 + 0 + 3 = 9
Y por lo tanto, nuestra función devolvería 9.*/

#include <stdio.h>
#include "solucion.h"

const int PROBABILIDAD_INICIAL = 5;
const int MENSAJE_LARGO = 50;
const int MUCHAS_RESPUESTAS = 3;

typedef struct mensaje {
    bool tiene_palabras_de_colegio;
    int cantidad_de_palabras;
    int cantidad_de_respuestas;
    bool autor_sospechoso;
} mensaje_t;

int indice_de_probabilidad_de_copia(mensaje_t mensaje){
    int probabilidad_copia = PROBABILIDAD_INICIAL;
    if (mensaje.tiene_palabras_de_colegio == true) probabilidad_copia += 2;
    else probabilidad_copia -= 2;

    if (mensaje.cantidad_de_palabras > MENSAJE_LARGO) probabilidad_copia += 2;
    else probabilidad_copia--;

    if (mensaje.cantidad_de_respuestas > 3) probabilidad_copia += 2;

    if (mensaje.autor_sospechoso == true) probabilidad_copia += 3;
    else probabilidad_copia--;

    return probabilidad_copia;
}