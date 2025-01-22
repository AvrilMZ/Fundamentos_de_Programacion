/*Mate estaba planeando su última operación como espía, hasta que se dio cuenta que el teléfono por donde se comunica la agencia, estaba pinchado, por lo que todos sus enemigos estaban escuchando su plan.
Para evitar que tengan más información, decidieron comenzar a hablar sólo con las vocales. De esta forma, el plan sería secreto y sólo ellas podían entenderlo.

Implementar un procedimiento que, dado un plan, elimine todas las consonantes existentes en él.

Ejemplo:
Si el plan es “Entrar de incognito”, debe quedar “Ea e ioio”.*/

#include <string.h>
#define MAX_PLAN 50

const char* VOCALES = "aeiouAEIOU";

void cifrar_plan(char plan[MAX_PLAN]) {
	size_t tope_plan = strlen(plan);
    char frase_enigma[MAX_PLAN];
    int j = 0;

    for (int i = 0; i < tope_plan; i++) {
        for (int k = 0; VOCALES[k] != '\0'; k++) {
            if (plan[i] == VOCALES[k]) frase_enigma[j++] = plan[i];
        }
        if (plan[i] == ' ') frase_enigma[j++] = ' ';
    }

    frase_enigma[j] = '\0';
    strcpy(plan, frase_enigma);
}