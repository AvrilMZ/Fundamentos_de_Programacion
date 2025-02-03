import csv

ARCHIVO_RECETAS = "recetas.csv"
ARCHIVO_SOPAS = "sopas.csv"
MODO_LECTURA = 'r'
MODO_ESCRITURA = 'w'
VEGETARIANO = 'V'
NO_VEGETARIANO = "NV"
INGREDIENTE_SOPA = "CALDO"
CARNES = ["MARISCOS", "CARNE", "POLLO"]

# PRE: -
# POST: Devuelve si es 'VEGETARIANO' o 'NO_VEGETARIANO' evaluando si hay algún elemento de 'CARNES' en 'receta'.
def es_sopa_vegetariana(receta):
    for ingrediente in receta:
        if ingrediente in CARNES:
            return NO_VEGETARIANO
    return VEGETARIANO

# PRE: 'file_recetas' debe existir.
# POST: Devuelve las recetas que sean sopas en un archivo aparte, todas clasificadas si son aptas o no para vegetarianos.
def detectar_sopas(file_recetas):
    try:
        with open(file_recetas, MODO_LECTURA,) as recetas_file:
            recetas = csv.reader(recetas_file, delimiter=';')
            with open(ARCHIVO_SOPAS, MODO_ESCRITURA, delimiter=';') as sopas_file:
                sopas = csv.writer(sopas_file, delimiter=';')
                for receta in recetas:
                    if INGREDIENTE_SOPA in receta:
                        receta.append(es_sopa_vegetariana(receta))
                        sopas.writerow(receta)
    except:
        print(f"Error abriendo el archivo {file_recetas}")
        return

if __name__ == "__main__":
    detectar_sopas(ARCHIVO_RECETAS)