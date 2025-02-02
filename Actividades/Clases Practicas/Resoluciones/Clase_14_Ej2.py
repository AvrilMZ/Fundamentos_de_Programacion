ARCHIVO_ANNIE = "gustos_annie.txt"
ARCHIVO_HALLIE = "gustos_hallie.txt"
ARCHIVO_EN_COMUN = "gustos_en_comun.txt"
MODO_LECUTRA = 'r'
MODO_ESCRITURA = 'w'

# PRE: 'file_annie' y 'file_hallie' deben existir.
# POST: Devuelve un archivo con todas las lineas en común entre 'file_annie' y 'file_hallie'.
def gustos_en_comun(file_annie, file_hallie):
    try:
        annie = open(file_annie, MODO_LECUTRA)
    except:
        print(f"Error al abrir el archivo {file_annie}.")
        return
    
    try:
        hallie = open(file_hallie, MODO_LECUTRA)
    except:
        print(f"Error al abrir el archivo {file_hallie}.")
        annie.close()
        return

    with open(ARCHIVO_EN_COMUN, MODO_ESCRITURA) as en_comun:
        linea_annie = annie.readline()
        while linea_annie:
            hallie.seek(0)
            linea_hallie = hallie.readline()
            while linea_hallie: 
                if (linea_annie == linea_hallie):
                    en_comun.write(linea_annie)
                linea_hallie = hallie.readline()
            linea_annie = annie.readline()

    annie.close()
    hallie.close()

if __name__ == "__main__":
    gustos_en_comun(ARCHIVO_ANNIE, ARCHIVO_HALLIE)