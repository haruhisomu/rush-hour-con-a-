#include <iostream>
#include "Tablero.h"
#include <fstream> // para trabajar con archivos
#include <string> // para tener objetos de arreglos de char de largo autoincrementable
#include <sstream> // para trabajar con streams de stringsusar clock para medir el tiempo de ejecucion
#include <ctime>
using namespace std;

int main() {
clock_t inicio = clock();    
Tablero tablero(6);
Estado *solucion;
int numero_autos;
std::string carsFile, wallsFile;
cout << "por favor introdusca el nombre del archivo con los autos: ";
cin >> carsFile;
cout << "por favor introdusca el nombre del archivo de los muros: ";
cin >> wallsFile;
numero_autos = tablero.num_autos(carsFile); //obtiene la cantidad de autos totales, util para recorrer la lista de autos de los estados
Estado *algo;
algo =  tablero.realdFile(carsFile, wallsFile); //lee los archivos de entrada, y pobla la matriz del tablero y crear y retorna el estado inicial
solucion =  tablero.resolver(algo, numero_autos); //aplica A*
//cout << endl;
//cout << "encontre la solucion";
//cout << endl;
Muros** lista_muros = tablero.get_lista_muros();
int numero_muros = tablero.get_numero_muros();
clock_t fin = clock();
double tiempo_transcurrido = double(fin - inicio) / CLOCKS_PER_SEC;
solucion->Imprimir_solucion(numero_autos, lista_muros, numero_muros);
std::cout << "Tiempo de ejecución: " << tiempo_transcurrido << " segundos" << std::endl;
//cout << endl;
//cout << "desde aqui para arriba se muestran los movimientos a realizar";
//cout << endl;

    return 0;
}