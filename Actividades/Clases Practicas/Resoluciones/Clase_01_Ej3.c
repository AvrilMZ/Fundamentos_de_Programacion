#include <stdio.h>

const char BUENO = 'B';

/* PRE: -
   POST: Imprime la frase "Micky devuélveme mi dinero que tengo que cargar la sube".*/
void frase_donald() {
    printf("Micky devuélveme mi dinero que tengo que cargar la sube\n");
}

/* PRE: 'respuesta_micky' debe estar inicializado.
   POST: Actualiza el valor de 'respuesta_micky' por el ingresado por el usuario.*/
void pregunta_micky(char* respuesta_micky) {
    printf("¿Cuál es tu respuesta Micky?\n");
    scanf(" %c", respuesta_micky);
}

int main() {
    char respuesta_micky = ' ';
    while (respuesta_micky != BUENO) {
        frase_donald();
        pregunta_micky(&respuesta_micky);
    }

    return 0;
}