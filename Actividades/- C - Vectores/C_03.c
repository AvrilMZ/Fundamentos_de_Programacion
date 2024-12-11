/*Oliver y su pandilla se tienen que enfrentar a Sykes y sus dobermans, quienes secuestraron a Jenny. Es por esto que deciden organizarse para poder hacerles frente. Considerando que solo Dodger, Einstein, y Francis son aptos para pelear, deciden averiguar quién es el más hábil para que, en caso de que haya una pelea, éste luche primero.

Considerando que las habilidades de los perros se dividen en inteligencia (posición 0), resistencia física (posición 1), agilidad (posición 2), y fuerza (posición 3), y que la capacidad de pelea se calcula como la suma de la inteligencia, el triple de la resistencia física, el doble de la agilidad, y la fuerza, se pide:
Implementar una función que calcule la capacidad de pelea de cada perro, y devuelva la habilidad del que peleará primero.

Ejemplo:
Si se reciben los vectores Dodger: [4,3,8,2], Einstein: [5,1,9,3] y Francis: [4,8,7,1], siendo el resultado de cada uno 31, 29 y 43 respectivamente, se debe devolver 43.*/

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