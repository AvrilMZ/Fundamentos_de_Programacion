import csv
import os

ARCHIVO_HERRAMIENTAS = "mouskeherramientas.csv"
ARCHIVO_HERRAMIENTAS_USADAS = "ultima_aventura.csv"
ARCHIVO_AUXILIAR = "auxiliar_herramientas.csv"
MODO_LECTURA = 'r'
MODO_ESCRITURA = 'w'
USADA = 1

# PRE: 'file_herramientas' y 'file_usados' deben existir.
# POST: Actualiza 'file_herramientas' con las herrmaientas no marcadas como usadas en 'file_usados', sin cargar los archivos en memoria.
def eliminar_herramientas_usadas(file_herramientas, file_usados):
    try:
        herramientas_file = open(file_herramientas, MODO_LECTURA)
    except:
        print(f"Error al abrir el archivo {file_herramientas}")
        return

    try:
        usados_file = open(file_usados, MODO_LECTURA)
    except:
        print(f"Error al abrir el archivo {file_usados}")
        herramientas_file.close()
        return

    herramientas = csv.reader(herramientas_file, delimiter='-')
    usados = csv.reader(usados_file, delimiter='-')
    
    herramientas_usadas = []
    for fila in usados:
        if int(fila[1]) == USADA:
            herramientas_usadas.append(fila[0])

    with open(ARCHIVO_AUXILIAR, MODO_ESCRITURA) as aux_file:
        escritor = csv.writer(aux_file, delimiter='-')
        for herramienta in herramientas:
            if herramienta[0] not in herramientas_usadas:
                escritor.writerow(herramienta)
        
    herramientas_file.close()
    usados_file.close()

    os.replace(ARCHIVO_AUXILIAR, file_herramientas)

if __name__ == "__main__":
    eliminar_herramientas_usadas(ARCHIVO_HERRAMIENTAS, ARCHIVO_HERRAMIENTAS_USADAS)
