#include <stdio.h>

/* PRE: 'dinero' debe estar inicializado.
   POST: Actualiza el valor de 'dinero' por el ingresado por el usuario.*/
void objetivo_dinero(int* dinero) {
    printf("¿Cual es el objetivo de dinero de Goofy?\n");
    scanf("%i", dinero);
}

/* PRE: 'donacion' debe estar inicializado.
   POST: Actualiza el valor de 'donacion' por el ingresado por el usuario.*/
void donacion_abuelita(int* donacion) {
    printf("¿Cuanta plata le va a dar por cada cántico?\n");
    scanf("%i", donacion);
}

/* PRE: 'donacion' debe ser distinto de cero.
   POST: Devuelve la división entre 'objetivo' y 'donacion', en caso de no ser exacta, se le suma uno.*/
int veces_cantar(int objetivo, int donacion) {
    if ((objetivo % donacion) != 0) return (objetivo / donacion) + 1;
    else return (objetivo / donacion);
}

/* PRE: -
   POST: Imprime el cántico la cantidad de 'veces' pasadas por parámetro.*/
void cantar(int veces) {
    for (int i = 0; i < veces; i++) {
        printf("Yo sé que algunas veces me equivoco demasiado ¡HYUCK!\n");
        printf("Yo sé que estás cansada de mirarme de costado ¡HYUCK!\n\n");
    }
}

int main() {
    int objetivo_goofy = 0;
    int donacion_por_cantico = 0;

    objetivo_dinero(&objetivo_goofy);
    donacion_abuelita(&donacion_por_cantico);

    if (donacion_por_cantico == 0) printf("No dona nada la abuelita :(\n");
    else {
        int veces = veces_cantar(objetivo_goofy, donacion_por_cantico);
        cantar(veces);
    }

    return 0;
}