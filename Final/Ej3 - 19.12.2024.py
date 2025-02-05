import csv

ARCHIVO_CANCIONES = "canciones.csv"
ARCHIVO_CANCIONES_COOL = "cool.csv"
MODO_LECTURA = 'r'
MODO_ESCRITURA = 'w'
TRISTE = "triste"
DURACION_MAX = 3
GENEROS_FAV = ["pop", "rock"]
CALIFICACION_MIN = 7
ARTISTA_FAV = "María Becerra"
INDICE_TITULO = 0
INDICE_GENERO = 1
INDICE_DURACION = 2
INDICE_ARTISTA = 3
INDICE_CALIF = 4

# PRE: 'file_canciones' debe existir.
# POST: Devuelve en un archivo llamado 'ARCHIVO_CANCIONES_COOL' las canciones que cumplen con los parametros para que sea cool.
def canciones_cool(file_canciones):
    try:
        f_canciones = open(file_canciones, MODO_LECTURA)
    except:
        print(f"Error al abrir el archivo {file_canciones}")
        return

    try:
        f_cool = open(ARCHIVO_CANCIONES_COOL, MODO_ESCRITURA)
    except:
        print(f"Error al crear el archivo {ARCHIVO_CANCIONES_COOL}")
        f_canciones.close()
        return

    canciones = csv.reader(f_canciones, delimiter=';')
    cool = csv.writer(f_cool, delimiter=';')

    for can in canciones:
        titulo = can[INDICE_TITULO]
        genero = can[INDICE_GENERO]
        duracion = int(can[INDICE_DURACION])
        artista = can[INDICE_ARTISTA]
        calificacion = int(can[INDICE_CALIF])
        if artista == ARTISTA_FAV or ((TRISTE not in titulo) and (duracion < DURACION_MAX) and (genero in GENEROS_FAV) and (calificacion > CALIFICACION_MIN)):
            cool.writerow(can)

    f_canciones.close()
    f_cool.close()

if __name__ == "__main__":
    canciones_cool(ARCHIVO_CANCIONES)

'''
----- PARTE TEÓRICA -----
1- ¿Qué campos internos debería tener un struct 'vector_dinamico_t'? ¿Y un struct 'lista_enlazada_t'?
2- ¿Qué uso tiene cada campo mencionado en el punto anterior?

1 & 2-  
    El struct 'vector_dinamico_t' deberia tener:
        typedef struct vector_dinamico {
            int tope;                   // indica la cantidad de elementos que tiene reservada 'arreglo'.
            int maximo;                 // indica la cantidad maxima de elementos posibles sin que sobrepase la capacidad de la memoria.
            dato_t* arreglo;            // contiene la informacion principal del vector, estando tambien reservada en memoria.
        } vector_dinamico_t;

    El struct 'lista_enlazada_t' deberia tener:
        typedef struct nodo {
            dato_t dato;                // contiene la informacion principal del vector.
            struct nodo* siguiente;     // puntero al siguiente nodo
        } nodo_t;

        typedef struct lista_enlazada {
            nodo_t* cabeza;             // puntero al primer nodo de la lista
        } lista_enlazada_t;
'''