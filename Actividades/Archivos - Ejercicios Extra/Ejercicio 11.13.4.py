'''Escribir una función, llamada grep, que reciba una cadena y un archivo de texto, e imprima las líneas del archivo que contienen la cadena recibida.'''

MODO_LECTURA = 'r'

def grep(palabra_buscada, nombre_archivo):
    lineas_contenedoras = []
    try:
        with open(nombre_archivo, MODO_LECTURA) as archivo:
            for linea in archivo:
                if palabra_buscada in linea:
                    lineas_contenedoras.append(linea)
    except:
        print(f"Error al abrir el archivo {nombre_archivo}")

    if lineas_contenedoras:
        print(lineas_contenedoras)
    else:
        print(f"No se encontraron lineas con el string '{palabra_buscada}'")