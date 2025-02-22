#define MAX_FIL 10
#define MAX_COL 10
const int SALIDA_X = 5;
const int SALIDA_Y = 4;
const int ENTRADA_X = 0;
const int ENTRADA_Y = 0;

typedef struct habitacion {
    int fil_sig_habitacion;
    int col_sig_habitacion;
    int cantidad_muebles;
} habitacion_t;

typedef struct coordenadas {
    int x;
    int y;
} coordenadas_t;

/*PRE:
    - 'habitaciones' no debe estar vacia, debe tener la posicion (5;4) y alguna posicion la tiene que tener como habitacion siguiente.
    - 'habitaciones_pasadas', 'fil_habitacion' y 'col_habitacion' deben ser inicialmente cero cuando se las pasa por parametro ('fil_habitacion' = 'ENTRADA_X'; 'col_habitacion' = 'ENTRADA_Y').
POST: Devuelve la cantidad de posciones recorridas hasta llegar a la posicion considerada salida.*/
int cantiadad_habitaciones_recorridas(habitacion_t habitaciones[MAX_FIL][MAX_COL], int habitaciones_pasadas, int fil_habitacion, int col_habitacion) {
    if (fil_habitacion == SALIDA_X && col_habitacion == SALIDA_Y) return habitaciones_pasadas;

    return cantiadad_habitaciones_recorridas(habitaciones, habitaciones_pasadas++, habitaciones[fil_habitacion][col_habitacion].fil_sig_habitacion, habitaciones[fil_habitacion][col_habitacion].col_sig_habitacion);
}

/*PRE:
    - 'habitaciones' no debe estar vacia, debe tener la posicion (5;4) y alguna posicion la tiene que tener como habitacion siguiente.
    - 'record_muebles', 'fil_habitacion' y 'col_habitacion' deben ser inicialmente cero cuando se las pasa por parametro ('fil_habitacion' = 'ENTRADA_X'; 'col_habitacion' = 'ENTRADA_Y').
    - 'posicion_record' debe estar correctamente inicializado en (ENTRADA_X;ENTRADA_Y).
POST: Devuelve la posicion con mas cantidad de muebles.*/
coordenadas_t posicion_mas_muebles(habitacion_t habitaciones[MAX_FIL][MAX_COL], int record_muebles, coordenadas_t posicion_record, int fil_habitacion, int col_habitacion) {
    if ((fil_habitacion == SALIDA_X && col_habitacion == SALIDA_Y) && (habitaciones[fil_habitacion][col_habitacion].cantidad_muebles < record_muebles)) return posicion_record;
    else if ((fil_habitacion == SALIDA_X && col_habitacion == SALIDA_Y) && (habitaciones[fil_habitacion][col_habitacion].cantidad_muebles > record_muebles)) {
        posicion_record.x = fil_habitacion;
        posicion_record.y = col_habitacion;
        return posicion_record;
    }

    if (habitaciones[fil_habitacion][col_habitacion].cantidad_muebles > record_muebles) {
        record_muebles = habitaciones[fil_habitacion][col_habitacion].cantidad_muebles;
        posicion_record.x = fil_habitacion;
        posicion_record.y = col_habitacion;
        return posicion_mas_muebles(habitaciones, record_muebles, posicion_record, habitaciones[fil_habitacion][col_habitacion].fil_sig_habitacion, habitaciones[fil_habitacion][col_habitacion].col_sig_habitacion);
    }

    return posicion_mas_muebles(habitaciones, record_muebles, posicion_record, habitaciones[fil_habitacion][col_habitacion].fil_sig_habitacion, habitaciones[fil_habitacion][col_habitacion].col_sig_habitacion);
}