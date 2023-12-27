#include "Estado.h"

using namespace std;

int main(){
Car** autos_list = new Car*[18]; 
autos_list[0] = new Car(1, 0, 0, 3, 0, false);
autos_list[1] = new Car(2, 1, 0 ,2, 0, true);

Estado estado_prueba(autos_list, 2, nullptr, 2);  // Estado(autos, 2, nullptr, 2); 
Car** autos_lista = estado_prueba.get_lista_autos();

for(int i = 0; i < 2; i++){
Car* autos = autos_lista[i];
int X = autos->get_x();
int Y = autos->get_y();
int largo = autos->get_largo();
int numero = autos->get_numero();
int horientacion = autos->get_orientacion();
bool verificador = autos->get_objetivo();

cout << "posicion en X = ";
cout << X;
cout << endl;
cout << "posicion en Y = ";
cout << Y;
cout << endl;
cout << "largo del auto = ";
cout << largo;
cout << endl;
cout << "largo del auto = ";
cout << largo;
cout << endl;
cout << "numero del auto = ";
cout << numero;
cout << endl;
cout << "orientacion  = ";
cout << horientacion;
}

return 0;
}