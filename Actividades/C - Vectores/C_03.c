#include <stdio.h>
const int MAX_HABILIDADES = 4;

int perro_mas_habilidoso(int habilidades_dodger[MAX_HABILIDADES], int habilidades_einstein[MAX_HABILIDADES], int habilidades_francis[MAX_HABILIDADES]) {
    int dodger = 0;
    int einstein = 0;
    int francis = 0;

    for (int i = 0; i < MAX_HABILIDADES; i++){
        switch (i){
            case 0:
                dodger += habilidades_dodger[i];
                einstein += habilidades_einstein[i];
                francis += habilidades_francis[i];
            break;
            case 1:
                dodger += habilidades_dodger[i] * 3;
                einstein += habilidades_einstein[i] * 3;
                francis += habilidades_francis[i] * 3;
            break;
            case 2:
                dodger += habilidades_dodger[i] * 2;
                einstein += habilidades_einstein[i] * 2;
                francis += habilidades_francis[i] * 2;
            break;
            case 3:
                dodger += habilidades_dodger[i];
                einstein += habilidades_einstein[i];
                francis += habilidades_francis[i];
            break;
        }
    }

    if (dodger > einstein && dodger > francis){
        return dodger;
    } else if (einstein > dodger && einstein > francis){
        return einstein;
    } else if (francis > dodger && francis > einstein){
        return francis;
    } else return -1;
}