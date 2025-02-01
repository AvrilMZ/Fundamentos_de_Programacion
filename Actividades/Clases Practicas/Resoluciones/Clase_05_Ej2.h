#ifndef CLASE_05_EJ2_H
#define CLASE_05_EJ2_H

#define MAX_TIPO 20
#define MAX_JUGUETES 100
#define MAX_NOMBRE 50
#define MAX_BAULES 30

typedef struct juguete {
    char nombre[MAX_NOMBRE];
    int anio_comprado;
    int valor;
    char tipo[MAX_TIPO];
} juguete_t;

typedef struct baul{
    juguete_t juguetes[MAX_JUGUETES];
    char etiqueta[MAX_NOMBRE];
    int tope_juguetes;
} baul_t;

typedef struct inventario{
    baul_t baules[MAX_BAULES];
    int tope_baules;
} inventario_t;

/* PRE: 'nuevo_juguete' debe ser un juguete inicializado. 'inventario' está correctamente inicializado.
   POST: Se va a agregar el juguete al baul que tenga menos juguetes y se muestra un mensaje con la etiqueta del baúl al que fue agregado. Si el 'inventario' está lleno, no se agrega el juguete y se muestra un mensaje indicando que no hay espacio.*/
void agregar_juguete(inventario_t* inventario, juguete_t nuevo_juguete);

/* PRE: 'inventario' debe estar inicializado y los tipos de los juguetes deben ser “Electrónico", "Peluche", o "Plástico"
   POST: Se cuentan y muestran la cantidad de cada tipo de peluche por pantalla.*/
void contar_juguetes_por_tipo(inventario_t inventario);

/* PRE: 'inventario' debe estar correctamente inicializado.
   POST: Crea un nuevo baúl vacío para guardar juguetes con la etiqueta que recibe.*/
void agregar_baul(inventario_t* inventario, char etiqueta[MAX_NOMBRE]);

/* PRE: 'inventario' debe estar correctamente inicializado, así como también el vector de 'juguetes_a_vender' vacío con su tope inicializado correctamente.
   POST: Guarda en el vector de juguetes aquellos que pueden ser vendidos, se tiene en cuenta que se quieren vender los que no son peluches y los que tienen más de 10 años de antigüedad.*/
void calcular_valor_total(inventario_t inventario, juguete_t jueguetes_a_vender[MAX_JUGUETES], int* tope_juguetes_a_vender);

#endif