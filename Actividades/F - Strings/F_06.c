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