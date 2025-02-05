import os

ARCHIVO_BROMAS = "bromas_no_realizadas.txt"
ARCHIVO_BROMAS_HECHAS = "bromas_del_dia.txt"
ARCHIVO_AUXILIAR = "archivo_aux.txt"
MODO_LECTURA = 'r'
MODO_ESCRITURA = 'w'

# PRE: 'file_bromas' y 'file_bromas_hechas' deben existir.
# POST: Actualiza 'file_bromas' eliminando las lineas que aparecen en 'file_bromas_hechas'.
def bromas_a_hacer(file_bromas, file_bromas_hechas):
    try:
        f_bromas = open(file_bromas, MODO_LECTURA)
    except:
        print(f"Error al abrir el archivo {file_bromas}")
        return
    
    try:
        f_bromas_hechas = open(file_bromas_hechas, MODO_LECTURA)
    except:
        print(f"Error al abrir el archivo {file_bromas_hechas}")
        f_bromas.close()
        return

    try: 
        f_aux = open(ARCHIVO_AUXILIAR, MODO_ESCRITURA)
    except:
        print(f"Error al crear el archivo {ARCHIVO_AUXILIAR}")
        f_bromas.close()
        f_bromas_hechas()
        return

    bromas = f_bromas.readline()
    while bromas:
        hecha = False
        bromas_hechas = f_bromas_hechas.readline()
        while bromas_hechas and not hecha:
            if bromas_hechas == bromas:
                hecha = True

            bromas_hechas = f_bromas_hechas.readline()
        f_bromas_hechas.seek(0)

        if not hecha:
            f_aux.write(bromas)

        bromas = f_bromas.readline()
    
    f_bromas.close()
    f_bromas_hechas.close()
    f_aux.close()

    os.replace(ARCHIVO_AUXILIAR, file_bromas)

if __name__ == "__main__":
    bromas_a_hacer(ARCHIVO_BROMAS, ARCHIVO_BROMAS_HECHAS)

'''
----- PARTE TEÓRICA -----
1- Nombrar y explicar brevemente los tres métodos de ordenamientos dictados en la cátedra. ¿A qué debe cada uno su nombre?

1- Tenemos tres métodos de ordenamiento:
    - Inserción: Toma el primer elemento como referencia, itera por todo el arreglo hasta encontrar uno mayor a él, cuando lo encuentra se coloca una posicion anterior, moviendo la posicion del resto.
    - Selección: Itera por el arreglo buscando el elemento de menor valor, al encontrarlo lo coloca en la primer posición, donde luego la primer posicion pasaria a ser la segunda.
    - Bubblesort: Toma el primer elemento como referencia y se compara con el elemento siguiente, si este es menor a él intercambia posiciones, asi hasta encontrar un elemento mayor o llegar al final.
'''