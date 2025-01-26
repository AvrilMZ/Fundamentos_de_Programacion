'''Escribir una función, llamada rot13, que reciba un archivo de texto de origen y uno de destino, de modo que para cada línea del archivo origen, se guarde una línea cifrada en el archivo destino. 
El algoritmo de cifrado a utilizar será muy sencillo: a cada caracter comprendido entre la a y la z, se le suma 13 y luego se aplica el módulo 26, para obtener un nuevo caracter.'''

MODO_LECTURA = 'r'
MODO_ESCRITURA = 'w'
CARACTER_INICIO_MINUSCULA = 'a'
CARACTER_FIN_MINUSCULA = 'z'
CARACTER_INICIO_MAYUSCULA = 'A'
CARACTER_FIN_MAYUSCULA = 'Z'

def rot13(archivo_origen, archivo_destino):
    try:
        with open(archivo_origen, MODO_LECTURA) as entrada, open(archivo_destino, MODO_ESCRITURA) as salida:
            for linea in entrada:
                for caracter in linea:
                    if CARACTER_INICIO_MINUSCULA <= caracter <= CARACTER_FIN_MINUSCULA:
                        salida.write(chr((ord(caracter) - ord(CARACTER_INICIO_MINUSCULA) + 13) % 26 + ord(CARACTER_INICIO_MINUSCULA)))
                    elif CARACTER_INICIO_MAYUSCULA <= caracter <= CARACTER_FIN_MAYUSCULA:
                        salida.write(chr((ord(caracter) - ord(CARACTER_INICIO_MAYUSCULA) + 13) % 26 + ord(CARACTER_INICIO_MAYUSCULA)))
                    else:
                        salida.write(caracter)
    except:
        print(f"Error al abrir el archivo {archivo_origen}")

# ord(): Convierte un carácter en su valor numérico en el sistema de codificación Unicode (o ASCII).
# chr(): Convierte un valor numérico de vuelta a su carácter correspondiente.
