#include "Heap.h"
int main(){

using namespace std;

Car** autos_list = new Car*[18]; 
Car** auto_lista = new Car*[18];
autos_list[0] = new Car(1, 0, 0, 3, 0, false);
autos_list[1] = new Car(2, 1, 0 ,2, 0, true);

Estado* estado_prueba = new Estado(autos_list, 2, nullptr, 2);  // Estado(autos, 2, nullptr, 2); 
auto_lista[0] = new Car(3, 1, 0 ,2, 0, false);
Estado* estado_prueba2 = new Estado(auto_lista, 2, estado_prueba, 1);
Heap arbolito(10);
arbolito.push(estado_prueba);
arbolito.push(estado_prueba2);

while(!arbolito.isEmpty()){
    Estado* auxiliar = arbolito.pop();
    int X = auxiliar->get_lista_autos()[0]->get_x();
    int Y = auxiliar->get_lista_autos()[0]->get_y();
    cout << "posicion de primer auto en cada lista :";
    cout << X;
    cout << ",";
    cout << Y;
    cout << endl;

}  
};