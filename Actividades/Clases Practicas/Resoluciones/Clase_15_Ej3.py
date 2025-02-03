import csv

MODO_LECTURA = 'r'
MODO_ESCRITURA = 'w'
ARCHIVO_ANNIE = "hobbies_annie.csv"
ARCHIVO_HALLIE = "hobbies_hallie.csv"
ARCHIVO_SALIDA = "nuevos_hobbies.csv"
DISFRUTE_MINIMO = 8
INDICE_DISFRUTE = 1
INDICE_HOBBIE = 0

# PRE: 'file' debe existir.
# POST: Devuelve una lista con las actividades cuyo puntaje sea mayor a 7.
def hobbies_con_disfrute_minimo(file):
    try: 
        hobbies_puntaje_alto = []
        with open(file, MODO_LECTURA) as f_hobbies:
            hobbies = csv.reader(f_hobbies, delimiter=',')
            for hob in hobbies:
                if hob[INDICE_DISFRUTE] >= DISFRUTE_MINIMO:
                    hobbies_puntaje_alto.append(hob)
        return hobbies_puntaje_alto
    except:
        print(f"Error al abrir el archivo {file}")
        return

# PRE: 'file_annie' y 'file_hallie' deben existir.
# POST: Devuelve en un archivo las actividades que no comparten los archivos y cuyo puntaje sea mayor a 7.
def hobbies_no_en_comun(file_annie, file_hallie):
    try:
        f_annie = open(file_annie, MODO_LECTURA)
    except:
        print(f"Error al abrir el archivo {file_annie}")
        return

    try:
        f_hallie = open(file_hallie, MODO_LECTURA)
    except:
        print(f"Error al abrir el archivo {file_hallie}")
        f_annie.close()
        return

    hobbies_annie = hobbies_con_disfrute_minimo(file_annie)
    hobbies_hallie = hobbies_con_disfrute_minimo(file_hallie)

    with open(ARCHIVO_SALIDA, MODO_ESCRITURA) as salida:
        en_comun = csv.writer(salida)
        for hobbie in hobbies_annie:
            if hobbie[INDICE_HOBBIE] not in hobbies_hallie:
                en_comun.writerow(hobbie)
        for hobbie in hobbies_hallie:
            if hobbie[INDICE_HOBBIE] not in hobbies_annie:
                en_comun.writerow(hobbie)
    
    f_annie.close()
    f_hallie.close()

if __name__ == "__main__":
    hobbies_no_en_comun(ARCHIVO_ANNIE, ARCHIVO_HALLIE)
