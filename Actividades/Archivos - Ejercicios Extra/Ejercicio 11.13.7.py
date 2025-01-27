'''Sea un diccionario cuyas claves y valores son cadenas.
a) Escribir una función 'guardar_diccionario' que reciba un diccionario y una ruta, y guarde el contenido del diccionario en el archivo, en modo texto, escribiendo un par clave-valor por línea con el formato clave,valor.
b) Escribir una función 'cargar_diccionario' que reciba una ruta a un archivo con el formato anterior y devuelva el diccionario cargado.'''

MODO_LECTURA = 'r'
MODO_ESCRITURA = 'w'

# a)
def guardar_diccionario(diccionario_entrada, ruta_salida):
    with open(ruta_salida, MODO_ESCRITURA) as archivo:
        for clave, valor in diccionario_entrada.items():
            archivo.write(f"{clave},{valor}\n")

# b)
def cargar_diccionario(ruta_salida):
    diccionario_salida = {}
    try:
        with open(ruta_salida, MODO_LECTURA) as archivo:
            for linea in archivo:
                clave, valor = linea.strip().split(',')
                diccionario_salida[clave] = valor
        return diccionario_salida
    except:
        print(f"Error al abrir el archivo de la ruta {ruta_archivo}")

# items(): Devuelve una vista de todos los pares clave-valor de un diccionario como tuplas, permitiendo recorrerlos fácilmente en un bucle.