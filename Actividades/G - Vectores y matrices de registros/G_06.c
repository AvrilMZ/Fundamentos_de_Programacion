/*Finalmente la tripulación de Barbossa logró conseguir los 882 medallones del tesoro para romper la maldición azteca. Pero luego de realizar el ritual se dieron cuenta que todavía estaban malditos. Desesperadamente los piratas empiezan a contar cuantos medallones hay en el cofre y en medio del caos, descubrieron que no todos los medallones pertenecen al tesoro azteca…

Implementar una función que dada una matriz que representa el cofre y donde cada posición es una bolsita con medallones. Devuelva la cantidad de medallones de origen “Azteca” que les falta para romper la maldición.

Aclaraciones:
Las bolsitas están representadas por un registro con los siguientes datos:
    Origen (string)
    Cantidad (int)
Los medallones aztecas van a tener como origen el string "AZTECA".
Recordar que para romper la maldición se necesitan 882 medallones.*/

#include <stdio.h>

#define MAX_FILAS 50
#define MAX_COLUMNAS 50
#define MAX_NOMBRE 125

typedef struct bolsa {
    char origen[MAX_NOMBRE];
    int cantidad;
} bolsa_t;

int medallones_faltantes(bolsa_t cofre[MAX_FILAS][MAX_COLUMNAS], int tope_filas, int tope_columnas){
    
}