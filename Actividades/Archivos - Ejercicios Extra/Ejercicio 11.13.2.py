'''Escribir una función, llamada cp, que copie todo el contenido de un archivo (sea de texto o binario) a otro, de modo que quede exactamente igual.
Nota: Tener en cuenta que el contenido completo del archivo puede ser más grande que la memoria de la computadora. 
Utilizar archivo.read(bytes) para leer como máximo una cantidad determinada de bytes.'''

MODO_LECTURA_TEXTO = 'r'
MODO_ESCRITURA_TEXTO = 'w'
MODO_LECTURA_BINARIO = "rb"
MODO_ESCRITURA_BINARIO = "wb"

def cp(nombre_archivo, archivo_copia, es_binario):
    kilobyte = 1024
    
    if es_binario:
            modo_lectura = MODO_LECTURA_BINARIO
            modo_escritura = MODO_ESCRITURA_BINARIO
    else:
        modo_lectura = MODO_LECTURA_TEXTO
        modo_escritura = MODO_ESCRITURA_TEXTO

    try:
        with open(nombre_archivo, modo_lectura) as archivo, open(archivo_copia, modo_escritura) as copia:
            bloque = archivo.read(kilobyte)
            while bloque:
                copia.write(bloque)
                bloque = archivo.read(kilobyte)
    except:
        print(f"Error al abrir el archivo {nombre_archivo}")


''' 
------ SIN USAR READ() ------
No es adecuado porque los archivos binarios no se pueden tratar como cadenas de texto, por lo que no se puede usar "for" y habria que usar funciones como iter().
'''
