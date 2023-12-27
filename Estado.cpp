#include"Estado.h"

using namespace std;

// entrada: Car** lista de autos, int operacion, Estado Estado_anterior, int numero_autos
// salida: Estado
// crea un estado nuevo
Estado::Estado(Car** lista_autos, int op, Estado *padre, int numero_autos)
{
    *this->lista_autos = lista_autos;
    this->padre = padre;
    this-> op = op;
    this->numero_autos = numero_autos;
    this->puntuacion = 0;
    this->posicion_heap = 0;
}
// entrada vacio
// salida Estado
// constructor de Estado vacio
Estado::Estado()
{
    *this->lista_autos = nullptr;
    this->padre = nullptr;
    this->op = -1;
}


// entrada: int **tablero, int X, int Y, int largo, int orientacion, int identificador
// salida: bool
// revisa si el movimiento que se realiza en el estado actual es valido o no.
bool Estado::check(int **tab, int x, int y, int largo, int orientacion, int identificador, int pasos) {
    if (x < 0 || x >= 6 || y < 0 || y >= 6) {
        return false;  // Verifica los límites del tablero (x y y)
    }
    bool verificador = true;
    if (orientacion == 0) {
        if (y + largo > 6) {
            return false;  // Verifica si el auto se ajusta en la dirección horizontal
        }

        for (int i = 0; i < largo; i++) {

            if (tab[x][y+ i] != 0) {
                verificador = false;  // Verifica si hay autos en el camino
            }
            if (tab[x][y+i] == identificador){
                verificador = true; // revisa que el auto en el camino no sea el mismo auto que se esta moviendo
            }
            if(verificador == false){
                return false;
            }
        }
        if (pasos < 0){
            for (int i=0; i >  pasos; i--){
                if(tab[x][y - i] != 0){
                    verificador = false;
                }
                if(tab[x][y - i ] == identificador){
                    verificador = true;
                }
                if( verificador == false){
                    return false;
                }
            }
        }
        if(pasos > 0){
            for (int i=0; i <  pasos; i++){
                if(tab[x][y - i] != 0){
                    verificador = false;
                }
                if(tab[x][y - i ] == identificador){
                    verificador = true;
                }
                if( verificador == false){
                    return false;
                }
            }
        }

    } else if (orientacion == 1) {
        if (x + largo > 6) {
            return false;  // Verifica si el auto se ajusta en la dirección vertical
        }

        for (int i = 0; i < largo; i++) {
            if (tab[x + i][y] != 0) {
                verificador = false;  // Verifica si hay autos en el camino
            }
            if(tab[x+i][y] == identificador){
                verificador = true; // revisa que el auto camino no sea el mismo auto que se mueve
            }
            if(verificador == false){
                return false;
            }
        }
         if (pasos < 0){
            for (int i=0; i >  pasos; i--){
                if(tab[x - i][y] != 0){
                    verificador = false;
                }
                if(tab[x - i][y] == identificador){
                    verificador = true;
                }
                if( verificador == false){
                    return false;
                }
            }
        }
         if(pasos > 0){
            for (int i=0; i <  pasos; i++){
                if(tab[x - i][y] != 0){
                    verificador = false;
                }
                if(tab[x - i][y] == identificador){
                    verificador = true;
                }
                if( verificador == false){
                    return false;
                }
            }
         } 
    }
    else {
        return false;  // si la orientacion no es valida retorna false, nunca deberia llegar a este punto, pero por si acaso no esta de mas
    }

    return true; // el movimiento puede ser realizado
}
// entrada: int numero_autos, Car** autos_lista
// salida bool
// esta funcion revisa si el estado actual es el estado final.
bool Estado::Final(int num_autos, Car** autos_lista) {
    for (int i = 0; i < num_autos; i++) {
        Car *auto_p1 =  autos_lista[i];
        Car auto_p2 = *auto_p1;
        if (auto_p2.get_objetivo() == true) {
            if (auto_p2.get_x() == 2 && auto_p2.get_y() == 4) {
                return true;
            }
        }
    }
    return false;
}
// entrada: vacia
// salida Car**
// devuelve la lista de autos que hay en un estado
Car** Estado::get_lista_autos(){
    return *lista_autos;
}


// entrada: vacio
// salida: *Estado
// devuelve un puntero al estado que llama a la funcion
Estado* Estado::obtener_puntero_estado(){
    return this;
}
// entrada: vacio
// salida: Estado*
// entrega el padre del esatdo actual
Estado* Estado::get_padre(){
    return padre;
}
int Estado::get_puntuacion(){
    return puntuacion;
}

int Estado::get_op(){
    return op;
}

//entrada: int numero_autos
// salida void
// imprime el estado actual, para hacer esto imprime la matriz completa
void Estado::imprimir_estado(int numero_autos, int numero_movimientos, Muros** lista_muros, int numero_muros)
{
   Car** hola = *this->lista_autos;
   Car** autos = hola;
   int puntuacion = this->puntuacion;
   int **tablero = new int*[6];
    for (int i = 0; i< 6; i++){
        tablero[i] = new int[6];
        for (int y = 0; y< 6; y++){
            tablero[i][y] = 0;
        }
    }

    int rudi = 0;
         while( rudi < numero_muros){
            int X = lista_muros[rudi]->get_x();
            int Y = lista_muros[rudi]->get_y();
            tablero[X][Y] = 19;
            rudi = rudi + 1; 
        }

   for(int i = 0; i< numero_autos; i++){
        Car* aux = autos[i];
        Car aux2 = *aux;
        int x,y, numero, orientacion, largo;
        x = aux2.get_x();
        y = aux2.get_y();
        orientacion = aux2.get_orientacion();
        largo = aux2.get_largo();
        numero = aux2.get_numero();
        for (int j = 0; j<largo;j++){ //coloca los autos en la matriz
                if(orientacion == 0){
                    tablero[x][y+j] = numero;
                }else{
                    tablero[x+j][y] = numero;
                }
        }
   }
   cout << endl;
   cout << "movimiento numero: "; 
   cout << numero_movimientos;
   cout << endl;
   cout << "la puntuacion de este movimiento es:";
   cout << puntuacion;
   cout << endl;
   //imprimir la matriz
        for (int X = 0; X<6; X++){
            for(int Y = 0; Y<6; Y++){
                cout <<tablero[X][Y] << " ";
            }
            cout << endl;
        }
}


// entrada: int numero_autos
// salida: void
// imprime los movimientos realizados para llegar a la solucion
void Estado::Imprimir_solucion(int numero_autos, Muros** lista_muros, int numero_muros)
{
    Estado *estadoActual = this;
    int numero_movimientos = 1;
    while (estadoActual != nullptr) {
        estadoActual->imprimir_estado(numero_autos, numero_movimientos, lista_muros, numero_muros); 
        estadoActual = estadoActual->get_padre(); // cambia al esta padre.
        numero_movimientos ++;
        }
}

void Estado::euristica(int** tablero, int posicion_heap)
{
    Car** autos = *this->lista_autos;
    Car** auxiliar = autos;
    int numero_autos = this->numero_autos;
    int numero_especial = 0;
    for(int i = 0; i < numero_autos; i++){
        Car* auto1 = auxiliar[i];
        if(auto1->get_objetivo() ==true){
            numero_especial = i +1;
        }
    }

    int puntuacion_euristica = 100;
    for(int y = 0; y < 6; y++){
        if(tablero[2][y] == 0 || tablero [2][y] == numero_especial){
            puntuacion_euristica = puntuacion_euristica - 1;
        }
    }
    
    int posicion_Y = auxiliar[numero_especial -1]->get_y();
    if(posicion_Y == 4){
        puntuacion_euristica = puntuacion_euristica - 50;
    }
    if (posicion_Y == 3){
        puntuacion_euristica  = puntuacion_euristica - 25;
    }
    if (posicion_Y ==2){
        puntuacion_euristica = puntuacion_euristica - 10;
    }
    puntuacion_euristica = puntuacion_euristica + posicion_heap;
    this->puntuacion = puntuacion_euristica;
}

void Estado::set_posicion_heap(int posicion_heap){
    this->posicion_heap = posicion_heap;
}
int Estado::get_posicion_heap(){
    return this->posicion_heap;
}
