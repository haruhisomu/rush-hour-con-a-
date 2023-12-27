#include "Car.h"

using namespace std;

int main(){
Car autos(1, 0, 0, 3, 0, false); //crear un auto en las coordenadas 0,0 de largo 3 y horizontal
int X = autos.get_x();
int Y = autos.get_y();
int largo = autos.get_largo();
int numero = autos.get_numero();
int horientacion = autos.get_orientacion();
bool verificador = autos.get_objetivo();

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

return 0;


}