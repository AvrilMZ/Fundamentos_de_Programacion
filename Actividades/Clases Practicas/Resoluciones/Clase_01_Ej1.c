#include <stdio.h>

const int CHOCOLATE = 2000;
const int GOMITAS = 1000;

/* PRE: -
   POST: Devuelve la suma de las variables.*/
int calcular_total_dinero(int dinero_mickey, int dinero_goofy, int dinero_donald) {
    return dinero_mickey + dinero_goofy + dinero_donald;
}

/* PRE: -
   POST: Imprime el mensaje correspondiente según la cantidad de 'dinero'.*/
void mensaje_productos_en_presupuesto(int dinero) {
    if (dinero < GOMITAS) printf("Ufaaa no nos alcanza pa naaa :( ¿Y si pedimos un préstamo en m#Q*$?\n");
    else if (dinero >= GOMITAS && dinero < CHOCOLATE) printf("Buee, por lo menos nos alcanzó para las gomitas\n");
    else if (dinero >= CHOCOLATE && dinero < (CHOCOLATE + GOMITAS)) printf("Que bien, nos alcanzó para el chocolate\n");
    else printf("¡Wii nos alcanza para el choco y las gomitas!\n");
}

/* PRE: 'dinero_mickey', 'dinero_goofy' y 'dinero_donald' deben estar inicializadas.
   POST: Actualiza el valor de las variables según lo ingresado por el usuario.*/
void pedido_usuario(int* dinero_mickey, int* dinero_goofy, int* dinero_donald) {
    printf("¿Cuanta plata tiene Mickey?\n");
    scanf("%i", dinero_mickey);

    printf("¿Cuanta plata tiene Goofy?\n");
    scanf("%i", dinero_goofy);

    printf("¿Cuanta plata tiene Donald?\n");
    scanf("%i", dinero_donald);
}

int main() {
    int dinero_mickey = 0;
    int dinero_goofy = 0;
    int dinero_donald = 0;

    pedido_usuario(&dinero_mickey, &dinero_goofy, &dinero_donald);
    int total_dinero = calcular_total_dinero(dinero_mickey, dinero_goofy, dinero_donald);
    mensaje_productos_en_presupuesto(total_dinero);

    return 0;
}