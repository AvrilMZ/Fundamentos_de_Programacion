import csv

CANTIDAD_DESADA = 100
MINIMO_DIAS_VENCER = 2
MODO_LECTURA = 'r'
MODO_ESCRITURA = 'w'
ARCHIVO_STOCK = "stock.csv"
ARCHIVO_PEDIDO = "pedido.csv"

# PRE: 'file_stock' debe existir.
# POST: Devuelve en un archivo los productos que esten a 'MINIMO_DIAS_VENCER' o menos, y que tenga menos de 'CANTIDAD_DESADA' en 'file_stock'.
def crear_pedido(file_stock):
    try:
        f_stock = open(file_stock, MODO_LECTURA)
    except:
        print(f"Error al abrir el archivo {file_stock}")
        return

    stock = csv.reader(f_stock, delimiter=';')

    with open(ARCHIVO_PEDIDO, MODO_ESCRITURA) as f_pedido:
        pedido = csv.writer(f_pedido)
        for producto in stock:
            dias_caducar = int(producto[0])
            prod = producto[1]
            cantidad = int(producto[2])
            if dias_caducar <= MINIMO_DIAS_VENCER:
                pedido.writerow([prod, CANTIDAD_DESADA])
            elif cantidad < CANTIDAD_DESADA:
                pedido.writerow([prod, CANTIDAD_DESADA - cantidad])
    
    f_stock.close()

if __name__ == "__main__":
    crear_pedido(ARCHIVO_STOCK)

'''
----- PARTE TEÓRICA -----
1- ¿Cuál es la diferencia entre un vector dinámico y una lista enlazada? Mencione una ventaja y una desventaja del uso de cada una.

1- Un vector dinámico almacena elementos en memoria contigua, mientras que una lista enlazada almacena nodos conectados.
   Ventajas:
    - Vector: Acceso rápido a elementos.
    - Lista enlazada: Inserciones/eliminaciones rápidas.
   Desventajas:
    - Vector: Inserciones/eliminaciones costosas.
    - Lista enlazada: Acceso lento a elementos.
'''