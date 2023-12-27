#include "Pila.h"
//por completar devido a que falta la clase esatdo:
//imrpimir(), contiene()

using namespace std;

// entrada int size
// salida Pila
// construye la pila
Pila::Pila(int size){
    this->size = size;
    this->pila = new Estado*[size];
    this->top = -1;

}
// entrada: Estado * valor
// salida: void
// introduce un estado a la pila
void Pila::push(Estado *valor){
    //aumentar la capacidad de la pila si esta se llena
    if(this->top == this->size -1){
        Estado **newEstado = new Estado*[this->size * 2];
        for (int i = 0; i< this->size; i++){
            //mantener los elementos de la pila al duplicar memoria
            newEstado[i] = this->pila[i];
        }
        delete[] this->pila;
        this->pila = newEstado;
        this->size = size * 2; //duplica el tamaño de la pila
    }
    this->top++;
    this->pila[this->top] = valor;
}
// entrada: vacio
// salida Estado*
// saca el primer elemento de la pila 
Estado* Pila::pop(){
    if(this->vacio()){
        throw "la pila esat vacia";
    }
    Estado *valor = this->pila[this->top];
    this->top--;
    return valor;
}
// entrada: vacio
// salida void
// verifica si la pila esta vacia o no
bool Pila::vacio(){
    //por como esta inicializada la pila esto retornara verdadero si la pila esta vacia y falso si no lo esta
    return this->top == -1;
}
// entrada: Estado *valor, int cantidad_autos
// salida bool
// revisa si un estado ingresado esat dentro de la pila o no
bool Pila::contiene(Estado *valor, int cantidad_autos)
{
    bool verificador;
    Estado ayuda = *valor;
    Car **valor_autos = ayuda.get_lista_autos();
    for(int i = 0; i<= this->top; i++){ //ciclo para recorrer toda la pila
        verificador = true;
        Estado pasador = *pila[i]; 
        Car **salvador = pasador.get_lista_autos();
        for( int j = 0; j<cantidad_autos; j++){ //ciclo para revisar todos los autos
            if (salvador[j]->get_x() != valor_autos[j]->get_x() || salvador[j]->get_y() != valor_autos[j]->get_y()){ // revisa que los valores de la lista de autos del valor actual de la pila sea distinto al del estado
                verificador = false; 
                j = 19;
            }
             if(j == cantidad_autos -1 && verificador == true){ //si recorre todos los autos del estado de la pila y el verificador sigue siendo verdadero, el estado si esta en la pila
                 return true;
              }

        
        }
    }
    return false;
}

Estado* Pila::encontrar_max_puntuacion(Pila pila2_0){
 Estado* maximo = pila2_0.pop();
    
    while (!pila2_0.vacio()) {
        Estado* estadoActual = pila2_0.pop();
        if (estadoActual->get_puntuacion() > maximo->get_puntuacion()) {
            maximo = estadoActual;
           }

    }
    return maximo;
}

