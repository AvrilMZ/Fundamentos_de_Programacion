'''Escribir una función, llamada wc, que dado un archivo de texto, lo procese e imprima por pantalla cuántas líneas, cuantas palabras y cuántos caracteres contiene el archivo.'''

MODO_LECTURA = 'r'

def wc(nombre_archivo):
    cantidad_lineas = 0
    cantidad_palabras = 0
    cantidad_caracteres = 0
    try:
        with open(nombre_archivo, MODO_LECTURA) as archivo:
            for linea in archivo:
                cantidad_lineas += 1
                cantidad_palabras += len(linea.split())
                cantidad_caracteres += len(cantidad_lineas)
    except:
        print(f"Error al abrir el archivo {nombre_archivo}")
    print(f"Cantidad de lineas: {cantidad_lineas}\n Cantidad de palabras: {cantidad_palabras}\n Cantidad de caracteres: {cantidad_caracteres}")
