/*Finalmente la tripulación de Barbossa logró conseguir los 882 medallones del tesoro para romper la maldición azteca. Pero luego de realizar el ritual se dieron cuenta que todavía estaban malditos. Desesperadamente los piratas empiezan a contar cuantos medallones hay en el cofre y en medio del caos, descubrieron que no todos los medallones pertenecen al tesoro azteca…

Implementar una función que dada una matriz que representa el cofre y donde cada posición es una bolsita con medallones. Devuelva la cantidad de medallones de origen “Azteca” que les falta para romper la maldición.

Aclaraciones:
Las bolsitas están representadas por un registro con los siguientes datos:
    Origen (string)
    Cantidad (int)
Los medallones aztecas van a tener como origen el string "AZTECA".
Recordar que para romper la maldición se necesitan 882 medallones.*/

#include <stdio.h>
#include <string.h>

#define MAX_FILAS 50
#define MAX_COLUMNAS 50
#define MAX_NOMBRE 125

const char* ORIGEN_CORRECTO = "AZTECA";
const int CANTIDAD_MEDALLONES_NECESARIOS = 882;

typedef struct bolsa {
    char origen[MAX_NOMBRE];
    int cantidad;
} bolsa_t;

int medallones_faltantes(bolsa_t cofre[MAX_FILAS][MAX_COLUMNAS], int tope_filas, int tope_columnas){
    int medallones_encontrados = 0;
    for (int i = 0; i < tope_filas; i++) {
        for (int j = 0; j < tope_columnas; j++) {
            if (strcmp(cofre[i][j].origen, ORIGEN_CORRECTO) == 0) medallones_encontrados += cofre[i][j].cantidad;
        }
    }
    if (CANTIDAD_MEDALLONES_NECESARIOS - medallones_encontrados >= 0) return CANTIDAD_MEDALLONES_NECESARIOS - medallones_encontrados;
    return 0;
}