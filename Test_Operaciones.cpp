#include "Operaciones.h"

using namespace std;

int main(){
    Operaciones operacion_prueba(0, 2,1);
    Car** autos_list = new Car*[18]; 
    autos_list[0] = new Car(1, 0, 0, 3, 0, false);
    autos_list[1] = new Car(2, 1, 0 ,2, 0, true);

    Estado* estado_prueba = new Estado(autos_list, 2, nullptr, 2);  // Estado(autos, 2, nullptr, 2); 
    Estado* auxiliar =  operacion_prueba.operacion(estado_prueba, 0, 2);
    Car** lista_autos_movidos =  auxiliar->get_lista_autos();
    int X = lista_autos_movidos[0]->get_x();
    int Y = lista_autos_movidos[0]->get_y();

    cout << X;
    cout << ",";
    cout << Y;
}