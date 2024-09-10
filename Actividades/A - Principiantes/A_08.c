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