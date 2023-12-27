#include <iostream>

//clase auto, donde se deben construir los autos a utilizar y poder obtener sus valores
class Car{
    private:
      int numero; //identificador del auto .
      int X; //posicion en X del auto.
      int Y; //posicion en Y del auto.
      int largo; //largo que posee el auto.
      int orientacion; //si es es 0 es horizontal si es 1 es vertical.
      bool objetivo; //denotara si es el auto que debe salir del tablero.
    public:
      //constructor
      Car(int numero, int X, int Y, int largo, int orientacion, bool objetivo);
      //  Car();
      // destructor
      ~Car();
      //selectores
      int get_x(); //obtener posicion en x de la cabecera
      int get_y(); //obtener posicion y de la cabecera
      int get_numero(); //obtener el identificador del auto
      int get_largo(); //obtener el largo del auto
      int get_orientacion(); //obtener la orientacion del auto
      bool get_objetivo(); //obtener si el auto es el objetivo
};