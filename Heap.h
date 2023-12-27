#include <iostream>
#include "Pila.h"


using namespace std;

class Heap {
    public:
    Estado **heap; // Aqui es doble puntero porque es un arreglo de punteros a State
    int size; // cuantos hay almacenado aqui
    int capacity; // cuantos caben aqui

    Heap(int capacity);
    ~Heap();
    void push(Estado *state);
    Estado *pop();
    bool isEmpty();

    void swap(int i, int j); 
    void bubbleUp(int index); // desde abajo asegura que el padre sea menor que el hijo 
    void heapify(int index); // desde arriba asegura que el padre sea menor que el hijo

};