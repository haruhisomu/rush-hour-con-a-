#include <iostream>
#include"Car.h"
#include "Muros.h"
#define Arriba 1
#define Abajo 2
#define Izquierda 3
#define Derecha 4


class Estado{
  private:
      Car** lista_autos[18]; //arreglo de autos
      int op; //operacion realizada
      Estado *padre; //estado anterior a este, si no tiene padre es el estado inicial
      int numero_autos; //cantidad de autos en el tablero
      int puntuacion;
      int posicion_heap;
  public:
      // constructores
      Estado(Car** lista_autos, int op, Estado* padre, int numero_autos);
      Estado();
     //~Estado();
    //selectores
      Car** get_lista_autos();
      int get_op();
      Estado* get_padre();
      Estado* obtener_puntero_estado();
      Car** get_lista_autos_nuevo(int numero_autos);
      int get_puntuacion();
      int get_posicion_heap();
      // otros
      void imprimir_estado(int numero_autos, int numero_movimientos, Muros** lista_muros, int numero_muros); // imprime las posiciones de los autos de un estado
      bool check(int **tab, int x, int y, int orientacion, int largo, int identificador, int pasos); // revisa si el movimiento realizado en el estado puede realizarse o no
      bool Final(int num_autos, Car** autos_lista); //revisa si el estado actual es el estado final
      void Imprimir_solucion(int numero_autos, Muros** lista_muros, int numero_muros);
      void euristica(int** tablero, int posicion_heap);
      void set_posicion_heap(int posicion);
      

};