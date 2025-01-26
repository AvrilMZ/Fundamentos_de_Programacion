'''Escribir una función, llamada head que reciba un archivo y un número N e imprima las primeras N líneas del archivo.'''

MODO_LECTURA = 'r'

def head(nombre_archivo, cantidad_lineas):
    lineas_leidas = []
    with open(nombre_archivo, MODO_LECTURA) as archivo: 
        for i in range(cantidad_lineas):
            lineas_leidas.append(archivo.readline())
    print(lineas_leidas)