#include <iostream>
#include <fstream> // para trabajar con archivos
#include <string> // para tener objetos de arreglos de char de largo autoincrementable
#include <sstream> // para trabajar con streams de strings

using namespace std;

/*
Asumimos que el archivo tiene la siguiente estructura:
- por cada linea terminada en "\n" se define un auto
- cada auto se define por tres numeros separados por espacio: x y largo dir
- x e y son las coordenadas del inicio del auto
- largo es la cantidad de casillas que ocupa el auto: 2 o 3
- dir es la direccion del auto: 0 (horizontal) o 1 (vertical) 

otras observaciones
- el tablero es de 6x6
- el auto rojo siempre esta en la fila 2
- las casillas que ocupa un auto comienzan en (x,y), si es horizontal terminan en (x+largo-1,y), si es vertical terminan en (x,y+largo-1).
*/


// esta funcion deberia ser un metodo de alguna clase
void readFile(string carsFile, string wallsFile) {
    int x, y, largo, dir;
    int **data = new int*[18]; // 18 es el maximo de autos. 3 por fila (de largo 2) x 6 filas
    ifstream file(carsFile); // es un stream de "FileInput" desde un archivo. 
    string line; // es un objeto que representa un arreglo de char que es auto ajustable.
    int count=0; // cuenta la cantidad de autos (uno por linea)
    while (getline(file, line)) { // lee una linea del archivo y la guarda en "line". Si no hay mas lineas, sale del while(retorna false).
        count++;
        cout << line << endl;
        stringstream charStream; // es un stream de "StringInput" desde un string.
        charStream << line; // guarda el string en el stream
        charStream >> x >> y >> largo >> dir; // lee los datos del stream y los guarda en las variables. Notar que como es un input stream se usa la operacion inversa a <<, que es >>. Automaticamente lee el tipo de dato de cada variable.
        cout << "x: "<< x << " y: " << y << " largo: " << largo << " dir: " << dir << endl; // imprimimos de vuelta todo. Aqui deben crear sus objetos de auto, y guardarlos en en State.
    }
    file.close(); // cerramos el archivo
    cout << "Cantidad de autos: " << count << endl << endl;

    // ahora leemos las paredes
    int numberWalls = 0;
    int walls[36][36]; // 36 es el maximo de paredes. 6 filas x 6 columnas
    for (int i=0; i<36; i++) {
        for (int j=0; j<36; j++) {
            walls[i][j] = 0; // inicializamos todo en 0
        }
    }
    file.open(wallsFile);
    if (file.is_open()) {
        while (getline(file, line)) {
            cout << line << endl;
            stringstream charStream;
            charStream << line;
            charStream >> x >> y;
            cout << "x: "<< x << " y: " << y << endl;
            walls[x][y] = 1; // guardamos la pared en la matriz
            numberWalls++;
        }
    } else {
        cout << "No hay paredes" << endl;       
    }
    cout << "Cantidad de paredes: " << numberWalls << endl << endl;

}


int main() {

    readFile("game1.txt","walls1.txt");

    return 0;

}