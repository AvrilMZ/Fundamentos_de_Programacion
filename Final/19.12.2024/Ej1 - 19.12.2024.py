import csv

ARCHIVO_PARTICIPANTES = "participantes.csv"
ARCHIVOS_PUNTOS = "puntos.csv"
MODO_LECTURA = 'r'
INDICE_ID = 0
INDICE_NOMBRE = 1
INDICE_PUNTOS = 1

# PRE: 'file_participantes' y 'file_puntos' deben existir.
# POST: Devuelve el nombre del participante cuyo id en 'file_puntos' tenga la mayor cantidad de puntos.
def ganador(file_participantes, file_puntos):
    try:
        f_participantes = open(file_participantes, MODO_LECTURA)
    except:
        print(f"Error al abrir el archivo {file_participantes}")
        return

    try:
        f_puntos = open(file_puntos, MODO_LECTURA)
    except:
        print(f"Error al abrir el archivo {file_puntos}")
        f_participantes.close()
        return

    participantes = csv.reader(f_participantes, delimiter=';')
    puntos = csv.reader(f_puntos, delimiter=';')

    record_puntos = -1
    id_record = -1
    for punt in puntos:
        id_puntos = int(punt[INDICE_ID])
        cant_puntos = int(punt[INDICE_PUNTOS])
        if cant_puntos > record_puntos:
            record_puntos = cant_puntos
            id_record = id_puntos
    
    nombre_ganador = ""
    for persona in participantes:
        id_part = int(persona[INDICE_ID])
        nombre = persona[INDICE_NOMBRE]
        if id_part == id_record:
            nombre_ganador = nombre
    
    f_participantes.close()
    f_puntos.close()

    return nombre_ganador

if __name__ == "__main__":
    ganador(ARCHIVO_PARTICIPANTES, ARCHIVOS_PUNTOS)

'''
----- PARTE TEÓRICA -----
1-
    a- menu.platos[0].ingredientes
        El acceso es correcto si se esta buscando el arreglo de 'ingredientes_t' dentro del primer elemento de 'platos' en 'menu'.
    b- menu.platos.ingredientes[0].tipo
        El acceso es incorrecto ya que no se especifica que elemento del arreglo 'platos' se busca.
    c- &(menu.platos[0].ingredientes[0])
        El acceso es correcto si se quiere devolver la direccion de memoria del primer elemento del arreglo 'ingredientes', del primer elemento de 'platos', en 'menu'.
    d- menu.platos[0].ingredientes[0].nombre
        El acceso es correcto si se quiere devolver el string (arreglo de caracteres) del nombre del primer elemento de 'ingredientes', del primer elemento de 'platos', en 'menu'.
'''