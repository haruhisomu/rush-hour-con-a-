#include "Car.h"

Car::Car(int numero, int X, int Y, int largo, int orientacion, bool objetivo)
{
this->numero = numero;
this->X = X;
this->Y = Y;
this->largo = largo;
this-> orientacion = orientacion;
this->objetivo = objetivo;
}
/*
Car::Car(){
    this->numero = 0;
    this->X = -1;
    this->Y = -1;
    this->largo = 0;
    this->orientacion = 1;
    this->objetivo = false;

}
*/
Car::~Car(){
}
// entrada: vacio
// retorno: int
// esta funcion devuelve la posicion en X de la cabecera del auto
int Car::get_x()
{
return X;
}

// entrada: vacio
// retorno: int
// esta funcion devuelve la posicion Y de la cabecera del auto
int Car::get_y()
{
    return Y;
}
// entrada: vacio
// retorno: int
// esta funcion devuelve el identificador unico de cada auto, este identificador tambien es como se representa en el tablero el auto
int Car::get_numero()
{
    return numero;
}
// entrada: vacio
// retorno: bool
// esta funcion devuelve true si es el auto que debe salir del tablero
bool Car::get_objetivo()
{
    return objetivo;
}
// entranda: vacio
// retorno: int
// esta funcion devuelve el largo de un auto
int Car::get_largo()
{
    return largo;
}
// entrada: vacio
// salida: int
// obtiene la orientacion del auto, esta se representa como un 1 o un 0
int Car::get_orientacion()
{
    return orientacion;
}
