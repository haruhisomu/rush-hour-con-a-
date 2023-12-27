#include "Operaciones.h"
using namespace std;
// entrada: int direccion, int paso, int numero_de_auto
// salida: Operaciones
// crea una operacion
Operaciones::Operaciones(int dir, int step, int numero_auto)
{
    this->dir = dir;
    this->step = step;
    this->numero_auto = numero_auto;
}

// entrada: vacio
// salida operaciones
// crea una operacion
Operaciones::Operaciones()
{
    this->dir =-1;
    this->step = -1;
}
// entrada: Estado *e, int k, int numero_autos
// salida: Estado*
// esta funcion permite mover un auto de un estado a otra posicion
Estado* Operaciones::operacion(Estado *e, int k, int numero_autos) {
    int dx = 0, dy = 0;
    Car **llenar = new Car*[numero_autos]; // nueva lista de autos a la cual copiar los autos

    Car **A = e->get_lista_autos(); 
    Car *auto_operar = A[k]; //obtiene el auto a operar, esta funcion opera un auto a uno
    Car aux = *auto_operar; 

    if (aux.get_orientacion() == 0) {
        dy = this->step;
    }
    if (aux.get_orientacion() == 1) {
        dx = this->step;
    }

    int x, y, direccion, largo;
    bool objetivo;

    for (int d = 0; d < numero_autos; d++) {
        Car *auto_auxiliar = A[d];
        Car auxiliar = *auto_auxiliar;
        x = auxiliar.get_x();
        y = auxiliar.get_y();

        largo = auxiliar.get_largo();
        direccion = auxiliar.get_orientacion();
        objetivo = auxiliar.get_objetivo();

        if (d == k) {
            llenar[d] = new Car(d + 1, x + dx, y + dy, largo, direccion, objetivo); // si es el auto a mover cambia su posicion en x o en y
        } else {
            llenar[d] = new Car(d + 1, x, y, largo, direccion, objetivo); //si no es el auto a mover copia el auto tal cual esta
        }
    }

    Estado *nuevo_estado = new Estado(llenar, op[dir][(step + 1) / 2], e, numero_autos); // crea un nuevo estado hijo del estado anterior

    return nuevo_estado;
}

int Operaciones::get_step()
{
    return step;
}