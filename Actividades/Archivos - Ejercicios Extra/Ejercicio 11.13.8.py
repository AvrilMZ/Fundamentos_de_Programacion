'''Sea una imagen de 8x8 pixels, en el que cada pixel puede ser blanco o negro.
La imagen se representa en Python como una matriz de 8x8 valores bool, donde un valor True o False representa un pixel blanco o negro respectivamente.
a) Escribir funciones para leer y escribir una imagen en un formato de texto. En este formato, el archivo contiene 8 líneas de 8 caracteres, y cada caracter representa un pixel. Un pixel blanco o negro se representa con un caracter ASCII B o N respectivamente.
b) Escribir funciones para leer y escribir una imagen en un formato binario. En este formato, la imagen se almacena en un archivo que contiene exactamente 64 bits (8 bytes), donde cada bit representa un pixel, y un pixel blanco o negro se representa con un bit 1 o 0, respectivamente.'''

MODO_LECTURA = 'r'
MODO_ESCRITURA = 'w'
MODO_LECTURA_BINARIO = "rb"
MODO_ESCRITURA_BINARIO = "wb"
BLANCO = 'B'
NEGRO = 'N'

# a)
def leer_imagen_texto(nombre_archivo):
    imagen = []
    try:
        with open(nombre_archivo, MODO_LECTURA) as archivo:
            for linea in archivo:
                fila = []
                for char in linea.strip():
                    if char == BLANCO:
                        fila.append(True)
                    else:
                        fila.append(False)
                imagen.append(fila)
        return imagen
    except:
        print(f"Error al abrir el archivo de la ruta {nombre_archivo}")

def escribir_imagen_texto(nombre_archivo, imagen):
    with open(nombre_archivo, MODO_ESCRITURA) as archivo:
        for fila in imagen:
            linea = ""
            for pixel in fila:
                if pixel:
                    linea += BLANCO
                else:
                    linea += NEGRO
            archivo.write(linea + '\n')

# b)
def leer_imagen_binario(nombre_archivo):
    imagen = []
    try:
        with open(nombre_archivo, MODO_LECTURA_BINARIO) as archivo:
            byte = archivo.read(1)
            while byte:
                fila = []
                for i in range(8):  # Recorremos los 8 bits del byte
                    fila.append((byte[0] >> (7 - i)) & 1 == 1)  # Ponemos True si el bit es 1, False si es 0
                imagen.append(fila)
                byte = archivo.read(1)
    except:
        print(f"Error al abrir el archivo de la ruta {nombre_archivo}")
    return imagen

def escribir_imagen_binario(nombre_archivo, imagen):
    with open(nombre_archivo, MODO_ESCRITURA_BINARIO) as archivo:
        for fila in imagen:
            byte = 0
            for i in range(8):  # Recorremos los 8 píxeles de la fila
                if fila[i]:  # Si el píxel es True (blanco)
                    byte |= (1 << (7 - i))  # Establecemos el bit correspondiente a 1
            archivo.write(bytes([byte]))
