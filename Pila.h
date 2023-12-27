#include <iostream>
#include "Operaciones.h"
class Pila
{
    public:
         // constructor
        Pila(int size); 
         // modificadores
         void push(Estado *valor);
         Estado* pop();
        // otros
         bool vacio();
         // void imprimir();
         bool contiene(Estado *valor, int cantidad_autos);
         void imprimir();
         Estado* encontrar_max_puntuacion(Pila pila2_0);

    private:

         Estado **pila; //pila donde se guardan estados
         int top; //el tope de la pila
         int size; //el tamaño de la pila
};