#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct papeleo {
    int id;
} papeleo_t;

// PRE: 'papeleo' debe estar creado correctamente.
// POST: Elimina los elementos de 'papeleo' verificando si estos estaban en orden descendente. Si lo estaban devuelve true, de lo contrario false.
bool es_orden_descendente_papeleo(papeleo_t *papeleo) {
    int id_actual;
    bool papeleo_eliminado = papeleo_eliminar_primero(papeleo, &id_actual);

    if (!papeleo_eliminado) {
        papeleo_destruir(papeleo);
        return true;
    }
    
    int id_anterior = id_actual;
    bool orden_descendente = true;

    while (papeleo_eliminado) {
        papeleo_eliminado = papeleo_eliminar_primero(papeleo, &id_actual);
        if(orden_descendente && id_actual > id_anterior) orden_descendente = false;
        id_anterior = id_actual;
    }

    papeleo_destruir(papeleo);
    return orden_descendente;
}

/*
----- PARTE TEÓRICA -----
1- ¿Qué es un TDA y para que sirven?
2- Crear la firma y las pre y post condiciones de una función del TDA "papeleo" que sirva para contar la cantidad de elementos que contiene. No hace falta implementarla.

1- Un TDA es un tipo de dato abstracto, este da la posibilidad al programador de crear sus propios tipos de datos definiendo su comportamiento pero no su implementación.
2- int contar_elementos(papeleo_t *papeleo);
   PRE: 'papeleo' debe estar creada correctamente.
   POST: Devuelve la cantidad de elementos que tiene 'papeleo'.
*/