import os

ARCHIVO_DISCURSO = "discurso.txt"
ARCHIVO_AUX = "auxiliar_discurso.txt"
MODO_LECTURA = "r"
MODO_ESCRITURA = "w"

def cambiar_discurso():
    try:
        with open(ARCHIVO_DISCURSO, MODO_LECTURA) as discurso, open(ARCHIVO_AUX, MODO_ESCRITURA) as copia:
            linea = discurso.readline()
            while linea:
                linea = linea.replace("Hallie", "Annie")
                linea = linea.replace("California", "Londres")
                linea = linea.replace("papá", "mamá")
                copia.write(linea)
                linea = discurso.readline()
        
        os.rename(ARCHIVO_AUX, ARCHIVO_DISCURSO)
    except:
        print(f"Error al abrir el archivo {ARCHIVO_DISCURSO}.")
        return


if __name__ == "__main__":
    cambiar_discurso()