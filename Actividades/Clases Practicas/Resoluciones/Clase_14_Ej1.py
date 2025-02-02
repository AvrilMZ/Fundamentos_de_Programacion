import os

ARCHIVO_DISCURSO = "discurso.txt"
ARCHIVO_AUX = "auxiliar_discurso.txt"
MODO_LECTURA = "r"
MODO_ESCRITURA = "w"

# PRE: 'file_discurso' debe existir.
# POST: Devuelve un archivo con el mismo contenido unicamente que con las palabras "Hallie", "California" y "papá" reemplazadas.
def cambiar_discurso(file_discurso):
    try:
        with open(file_discurso, MODO_LECTURA) as discurso, open(ARCHIVO_AUX, MODO_ESCRITURA) as copia:
            linea = discurso.readline()
            while linea:
                linea = linea.replace("Hallie", "Annie")
                linea = linea.replace("California", "Londres")
                linea = linea.replace("papá", "mamá")
                copia.write(linea)
                linea = discurso.readline()
        
        os.rename(ARCHIVO_AUX, file_discurso)
    except:
        print(f"Error al abrir el archivo {file_discurso}.")
        return


if __name__ == "__main__":
    cambiar_discurso()