'''Sea una lista de números enteros entre -2.147.483.648 y 2.147.483.647.
a) Escribir una función 'guardar_numeros' que reciba la lista y una ruta, y guarde el contenido de la lista en el archivo, en modo texto, escribiendo un número por línea.
b) Escribir una función 'cargar_numeros' que reciba una ruta a un archivo con el formato anterior y devuelva la lista de números cargada.
c) Modificar las funciones anteriores para que almacenen el archivo en formato binario, almacenando cada número en 4 bytes. Analizar las ventajas y desventajas entre el formato de texto y binario.'''

MODO_LECTURA = 'r'
MODO_ESCRITURA = 'w'
MODO_LECTURA_BINARIO = "rb"
MODO_ESCRITURA_BINARIO = "wb"

# a)
def guardar_numeros(lista_numeros, ruta_archivo):
    with open(ruta_archivo, MODO_ESCRITURA) as salida:
        for numero in lista_numeros:
            salida.write(str(numero) + "\n")

# b)
def cargar_numeros(ruta_archivo):
    try:
        with open(ruta_archivo, MODO_LECTURA) as archivo:
            lista_numeros = []
            for linea in archivo:
                numero = int(linea.strip())
                lista_numeros.append(numero)
            return lista_numeros
    except:
        print(f"Error al abrir el archivo de la ruta {ruta_archivo}")

# c)
def guardar_numeros_binario(lista_numeros, ruta_archivo):
    with open(ruta_archivo, MODO_ESCRITURA_BINARIO) as salida:
        for numero in lista_numeros:
            salida.write(numero.to_bytes(4))

def cargar_numeros_binario(ruta_archivo):
    try:
        with open(ruta_archivo, MODO_LECTURA_BINARIO) as archivo:
            while True:
                bytes_leidos = archivo.read(4)
                if len(bytes_leidos) == 4:
                    numero = int.from_bytes(bytes_leidos)
                    lista_numeros.append(numero)
                if len(bytes_leidos) < 4:
                    return lista_numeros
        return lista_numeros
    except:
        print(f"Error al abrir el archivo de la ruta {ruta_archivo}")

# to_bytes(): Convierte un número entero en su representación en bytes.
# from_bytes(): Convierte una secuencia de bytes en su número entero correspondiente.