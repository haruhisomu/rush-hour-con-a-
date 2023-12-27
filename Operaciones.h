#include <iostream>
#include "Estado.h"

#define Horizontal 0
#define Vertical 1

static int op[2][2] = {{Izquierda, Derecha}, {Arriba, Abajo}};

class Operaciones 
{
    private:
        int dir; //direccion del movimiento a realizar
        int step; // cantidad de casillas movidas, de momento sera solo 1 y -1
        int numero_auto; //auto que realiza el movimiento

    public: 
        // constructores
        Operaciones(int dir, int step, int numero_auto);
        Operaciones();
        // modificadores
        Estado* operacion(Estado *e, int k, int numero_autos); //permite realzar movimientos
        //selectores
        int get_step();
};