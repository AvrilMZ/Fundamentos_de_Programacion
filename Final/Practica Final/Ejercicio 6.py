import csv

COBRADO = 'C'
ARCHIVO_VENTAS = "ventas.csv"
ARCHIVO_GASTOS = "gastos.csv"
ARCHIVO_GANANCIAS = "cuentas.csv"
MODO_LECTURA = 'r'
MODO_ESCRITURA = 'w'

# PRE: 'file_ventas' y 'file_gastos' deben existir.
# POST: Devuelve en un archivo las ganancias del fin de semana, restando los gastos obtenidos por dia.
def ganancia_semana(file_ventas, file_gastos):
    try:
        f_ventas = open(file_ventas, MODO_LECTURA)
    except:
        print(f"Error al abrir el archivo {file_ventas}")
        return

    try:
        f_gastos = open(file_gastos, MODO_LECTURA)
    except:
        print(f"Error al abrir el archivo {file_gastos}")
        f_ventas.close()
        return

    ventas = csv.reader(f_ventas, delimiter=';')
    gastos = csv.reader(f_gastos, delimiter=';')

    ventas_por_dia = {"viernes": 0, "sábado": 0, "domingo": 0}
    for ven in ventas:
        if ven[2] == COBRADO:
            ventas_por_dia[ven[0]] += ven[1]

    gastos_por_dia = {"viernes": 0, "sábado": 0, "domingo": 0}
    for gas in gastos:
        gastos_por_dia[gas[0]] += gas[1]

    with open(ARCHIVO_GANANCIAS, MODO_ESCRITURA) as f_ganancias:
        ganancias = csv.writer(f_ganancias)
        for dia in ventas_por_dia:
            ganancia_total = ventas_por_dia[dia] - gastos_por_dia[dia]
            ganancias.writerow([dia, ganancia_total])
    
    f_ventas.close()
    f_gastos.close()

if __name__ == "__main__":
    ganancia_semana(ARCHIVO_VENTAS, ARCHIVO_GASTOS)


'''
----- PARTE TEÓRICA -----
1- Explicar cuándo el contenido de un archivo puede guardarse en su totalidad en alguna estructura como lo es un arreglo o una lista.
2- ¿Qué son las pre y post condiciones? ¿Por qué es importante usarlas? Escribir las pre ypost condiciones para la siguiente función:
        int division (int dividendo, int divisor) {
            return dividendo / divisor;
        }

1- El contenido de un archivo puede guardarse en su totalidad cuando el tamaño del archivo es chico, por lo que la capacidad de la memoria seria suficiente.
2- Las pre condiciones son condiciones que deben cumplirse antes de ejecutar una función para garantizar su correcto funcionamiento.
   Las post condiciones son condiciones que deben cumplirse después de ejecutar la función, asegurando que la salida es válida y consistente con lo esperado.
        PRE: 'divisor' no debe ser cero.
        POST: Devuelve el resultado de la división entre 'dividendo' y 'divisor'.
'''