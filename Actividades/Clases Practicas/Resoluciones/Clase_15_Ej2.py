import csv
import os

ARCHIVO_PRODUCCIONES = "todas_prods.csv"
ARCHIVO_NUEVAS_PRODUCCIONES = "nuevas_prods.csv"
ARCHIVO_AUX = "archivo_aux.csv"
MODO_LECTURA = 'r'
MODO_ESCRITURA = 'w'
POSICION_NOMBRE = 1

# PRE: 'file_producciones' y 'file_nuevas_producciones' deben existir.
# POST: Agrega todo el contenido de 'file_nuevas_producciones' en 'file_producciones' manteniendo el orden por titulo.
def agregar_nuevas_producciones(file_producciones, file_nuevas_producciones):
    try:
        f_producciones = open(file_producciones, MODO_LECTURA)
    except:
        print(f"Error al abrir el archivo {file_producciones}")
        return
    
    try:
        f_nuevas_producciones = open(file_nuevas_producciones, MODO_LECTURA)
    except:
        print(f"Error al abrir el archivo {file_nuevas_producciones}")
        f_producciones.close()
        return

    producciones = csv.reader(f_producciones, delimiter=';')
    nuevas_producciones = csv.reader(f_nuevas_producciones, delimiter=';')
    lista_nuevas_producciones = list(nuevas_producciones)

    with open(ARCHIVO_AUX, MODO_ESCRITURA) as auxiliar:
        aux = csv.writer(auxiliar, delimiter=';')
        for prod in producciones:
            prod_nueva = lista_nuevas_producciones[0]
            while prod_nueva[POSICION_NOMBRE] < prod[POSICION_NOMBRE]:
                aux.writerow(prod_nueva)
                lista_nuevas_producciones.pop(0)
                prod_nueva = lista_nuevas_producciones[0]
            aux.writerow(prod)
    
    f_producciones.close()
    f_nuevas_producciones.close()

    os.replace(ARCHIVO_AUX, file_producciones)

if __name__ == "__main__":
    agregar_nuevas_producciones(ARCHIVO_PRODUCCIONES, ARCHIVO_NUEVAS_PRODUCCIONES)