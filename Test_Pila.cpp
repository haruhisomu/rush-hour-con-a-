#include "Pila.h"

using namespace std;

int main(){
    Pila pila_prueba(10);
    Car** autos_list = new Car*[18]; 
autos_list[0] = new Car(1, 0, 0, 3, 0, false);
autos_list[1] = new Car(2, 1, 0 ,2, 0, true);

Estado* estado_prueba = new Estado(autos_list, 2, nullptr, 2);  // Estado(autos, 2, nullptr, 2); 

pila_prueba.push(estado_prueba);
if(pila_prueba.contiene(estado_prueba, 2)){
    cout <<"si se muestra este mensaje funciona todo bien";
    }

}