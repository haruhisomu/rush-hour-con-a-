#include <iostream>
#include <fstream> // para trabajar con archivos
#include <string> // para tener objetos de arreglos de char de largo autoincrementable
#include <sstream> // para trabajar con streams de strings
// #include "Pila.h"
#include "Heap.h"
class Tablero{

    public:
        //constructor
        Tablero(int largo); 
        // otros
        void imprimir();
        Estado* realdFile(std::string carsFile, std::string wallsFile);
        int num_autos(std::string carsFile);
        Estado* resolver(Estado *estado_inicial, int num_autos);
        Muros** get_lista_muros();
        int get_numero_muros();

    private:
        int **tab; //tablero dinamico para el juego
        int largo; //largo del tablero
        int numero_muros;
        Car** autos; //lista de autos dentro del tablero
        Estado* estado_inicial; //estado inicial de autos
        Operaciones op[12]; //posibles operaciones a realizar
        Muros** muros;
};