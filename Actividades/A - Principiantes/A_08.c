/*En la fábrica Monster S.A. los monstruos se dedican a viajar al mundo de los humanos para asustar a los niños y así obtener la energía que abastece el mundo de los monstruos.

Para ello es importante que cada empleado lleve un registro de la cantidad de niños asustados durante sus jornadas. Sin embargo, hay un monstruo llamado Mike Wazowski que siempre olvida hacerlo.
Cansada de esta situación, la secretaria Roz decidió contar la cantidad de veces que Mike no hizo su papeleo.

Imprimir por pantalla “Wazowski no ordenaste tu papeleo anoche”, sabiendo la cantidad de veces que contó Roz.

Si se recibe 4, debe imprimirse:
Wazowski no ordenaste tu papeleo anoche.
Wazowski no ordenaste tu papeleo anoche.
Wazowski no ordenaste tu papeleo anoche.
Wazowski no ordenaste tu papeleo anoche.*/

#include <stdio.h>

int main(){
	int veces_contadas = -1;
	scanf("%i", &veces_contadas);
	
    while (veces_contadas > 0){
        printf("%s", "Wazowski no ordenaste tu papeleo anoche.\n");
        veces_contadas -= 1;
    }

	return 0;
}