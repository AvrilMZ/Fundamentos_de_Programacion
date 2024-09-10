#include <stdio.h>

#define ENERO 'E'
#define FEBRERO 'F'
#define MARZO 'X'
#define MONTAÑA 'M'
#define PLAYA 'P'
#define LAGUNA 'L'

int main(){
    char epoca = '.';
    char paisaje = '.';
    scanf(" %c", &epoca);
    scanf(" %c", &paisaje);
    
    switch (epoca){
        case ENERO:
            switch (paisaje){
                case LAGUNA:
                    printf("%s", "Chip \n");
                break;
            
                case MONTAÑA:
                    printf("%s", "Dale \n");
                break;

                case PLAYA:
                    printf("%s", "Gadget \n");
                break;
            }
            break;
        
        case FEBRERO:
            switch (paisaje){
                case LAGUNA:
                    printf("%s", "Gadget \n");
                break;
            
                case MONTAÑA:
                    printf("%s", "Chip \n");
                break;

                case PLAYA:
                    printf("%s", "Dale \n");
                break;
            }
            break;
        
        case MARZO:
            switch (paisaje){
                case LAGUNA:
                    printf("%s", "Dale \n");
                break;
            
                case MONTAÑA:
                    printf("%s", "Gadget \n");
                break;

                case PLAYA:
                    printf("%s", "Chip \n");
                break;
            }
            break;
    }

	return 0;
}