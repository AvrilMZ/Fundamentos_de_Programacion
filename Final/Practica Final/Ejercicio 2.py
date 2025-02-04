import csv

MODO_LECTURA = 'r'
MODO_ESCRITURA = 'w'
ARCHIVO_LISTA = "lista_compras.csv"
ARCHIVO_TICKET = "ticket.csv"
ARCHIVO_FALTANTES = "faltantes.csv"
INDICE_PRODUCTO = 0
INDICE_CANTIDAD = 1

# PRE: 'file_lista' y 'file_ticket' deben existir.
# POST: Devuelve en un archivo los elementos faltantes de 'file_lista' en 'file_ticket'.
def productos_faltantes(file_lista, file_ticket):
    try:
        f_lista = open(file_lista, MODO_LECTURA)
    except:
        print(f"Error al abrir el archivo {file_lista}")
        return

    try:
        f_ticket = open(file_ticket, MODO_LECTURA)
    except:
        print(f"Error al abrir el archivo {file_ticket}")
        f_lista.close()
        return

    lista = list(csv.reader(f_lista, delimiter=';'))
    ticket = list(csv.reader(f_ticket, delimiter=';'))

    with open(ARCHIVO_FALTANTES, MODO_ESCRITURA) as f_faltantes:
        faltantes = csv.writer(f_faltantes, delimiter=';')
        for producto in lista:
            encontrado = False
            cantidad_faltante = int(producto[INDICE_CANTIDAD])  

            for comprado in ticket:
                if producto[INDICE_PRODUCTO] == comprado[INDICE_PRODUCTO]:
                    encontrado = True
                    cantidad_faltante -= int(comprado[INDICE_CANTIDAD])

            if cantidad_faltante > 0:
                faltantes.writerow([producto[INDICE_PRODUCTO], cantidad_faltante])
            elif not encontrado:
                faltantes.writerow(producto)
    
    f_lista.close()
    f_ticket.close()

if __name__ == "__main__":
    productos_faltantes(ARCHIVO_LISTA, ARCHIVO_TICKET)



''' 
----- PARTE TEÓRICA -----
1- ¿Cuáles son las operaciones con vectores que vimos en clase? ¿Cómo se diferencian entre sí?

1- Inserción: Agregar un nuevo elemento al vector. Si el vector está ordenado, se debe insertar en la posición correcta, lo que puede requerir mover otros elementos.
   Eliminación: Quitar un elemento del vector. Si no es el último, es necesario desplazar los elementos siguientes para mantener la continuidad del arreglo.
   Ordenación: Reorganizar los elementos del vector según un criterio (ascendente o descendente). Se pueden usar algoritmos como burbujeo, selección y inserción.
   Mezcla: Combinar dos vectores ordenados en uno solo (por lo que su tope es tope_uno + tope_dos), manteniendo el orden.
   Unión: Crear un nuevo vector con los elementos de dos vectores, eliminando duplicados si es necesario.
   Diferencia: Generar un vector con los elementos que están en un vector pero no en el otro.
   Búsqueda: Encontrar un elemento dentro del vector. Puede ser lineal o binaria (requiere un vector ordenado).
'''