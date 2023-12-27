#include "Tablero.h"
#include <fstream> // para trabajar con archivos
#include <string> // para tener objetos de arreglos de char de largo autoincrementable
#include <sstream> // para trabajar con streams de strings

using namespace std;
// entrada int largo
// salida Tablero
// crea el objeto tablero, inicializando la matriz del tablero con ceros
Tablero::Tablero(int largo) {
    this->largo = largo;
    this->tab = new int*[largo];
    this->autos = new Car*[18];
    this->estado_inicial = nullptr;
    this->muros = new Muros *[36];
    this->numero_muros = 0;
    for (int i = 0; i< largo; i++){
        this->tab[i] = new int[largo];
        for (int y = 0; y< largo; y++){
            this->tab[i][y] = 0;
        }
    }/*
    this->op[0] = Operaciones(Horizontal,1, 0);
    this->op[1] = Operaciones(Horizontal, -1, 0);
    this->op[2] = Operaciones(Vertical, 1, 0);
    this->op[3] = Operaciones(Vertical, -1, 0);
    this->op[4] = Operaciones(Horizontal, 2, 0);
    this->op[5] = Operaciones(Horizontal, 3, 0);
    this->op[6] = Operaciones(Horizontal, -2, 0);
    this->op[7] = Operaciones(Horizontal, -3, 0);
    this->op[8] = Operaciones(Vertical, 2, 0);
    this->op[9] = Operaciones(Vertical, 3, 0);
    this->op[10] = Operaciones(Vertical, -2, 0);
    this->op[11] = Operaciones (Vertical, -3, 0);
    */
   this->op[0] = Operaciones(Horizontal, 1 , 0);
   this->op[1] = Operaciones(Horizontal, -1 , 0);
   this->op[2] = Operaciones(Horizontal, 2 , 0);
   this->op[3] = Operaciones(Horizontal, -2 , 0);
   this->op[4] = Operaciones(Horizontal, 3 , 0);
   this->op[5] = Operaciones(Horizontal, -3 , 0);
  // this->op[6] = Operaciones(Horizontal, 1 , 0);


}

// entrada: String carsFile
// salida: int 
// lee el archivo de entrada y obtiene la cantidad de autos en el
int Tablero::num_autos(std::string carsFile)
{
    ifstream file(carsFile); 
    string line; //
    int count=0; // cuenta la cantidad de autos (uno por linea)
    while (getline(file, line)) { 
        count++;
    }
    return count;
}

// entrada: String carsFile, String wallsFile
// salida: Estado*
// lee los archivos de entrada y crea los autos, para introducirlos en la matriz que debe ser creada con anterioridad
Estado* Tablero::realdFile(std::string carsFile, std::string wallsFile)
{
    
    int x, y, largo, dir;
    int **data = new int*[18]; 
    ifstream file(carsFile); 
    string line; 
    int count=0; 
    int numero =0;
    int imprimir_objetivo = 0;
    while (getline(file, line)) { // lee una linea del archivo y la guarda en "line". Si no hay mas lineas, sale del while(retorna false).
        count++;
        // cout << line << endl;
        stringstream charStream; // es un stream de "StringInput" desde un string.
        charStream << line; // guarda el string en el stream
        charStream >> x >> y >> largo >> dir; // lee los datos del stream y los guarda en las variables.
        bool objetivo = false;
        if(x==2 && dir == 0){
            objetivo = true;
        }
        Car ficha(numero+1, x, y, largo, dir, objetivo); //crea un auto
        this->autos[numero] = new Car(numero +1 , x,y, largo, dir, objetivo); //añade el auto a la lista de autos
        for (int j = 0; j<largo;j++){ //coloca los autos en la matriz
            if(objetivo == false){
                if(dir == 0){
                    tab[x][y+j] = numero + 1;
                }else{
                    tab[x+j][y] = numero + 1;
                }

            }
            if(objetivo == true){
                imprimir_objetivo = numero+1;
                if(dir == 0){
                    tab[x][y+j] =numero+1;
                }else{
                    tab[x+j][y] = numero+1;
                }
            }
        }
        numero++;
    }
    file.close(); // cerramos el archivo
  //  cout << "Cantidad de autos: " << count << endl << endl;

    cout << "el auto objetivo es: "; 
    cout << imprimir_objetivo;
    cout << endl;
 //   cout << endl;
    //imrime los autos leidos del archivo de entrada
 //     for (int i = 0; i < numero; i++) {
 //       cout << "Auto #" << i+1 << ":" << std::endl;
 //       cout << "X: " << autos[i]->get_x() << std::endl; 
 //       cout << "Y: " << autos[i]->get_y() << std::endl; 
 //       cout << "Largo: " << autos[i]->get_largo() << std::endl;
 //       cout << "Orientación: " << (autos[i]->get_orientacion() ? "Vertical" : "Orizontal") << std::endl; 
 //       cout << std::endl;
 //   }

    Estado* estado_inicial = new Estado(autos, Arriba, nullptr, numero); //crea el estado inicial
    
    // ahora leemos las paredes
    int numberWalls = 0;
   // int walls[36][36]; // 36 es el maximo de paredes. 6 filas x 6 columnas
   // for (int i=0; i<36; i++) {
   //     for (int j=0; j<36; j++) {
   //         walls[i][j] = 0; // inicializamos todo en 0
   //     }
   // }
    file.open(wallsFile);
    if (file.is_open()) {
        int X, Y;
        while (getline(file, line)) {
            cout << line << endl;
            stringstream charStream;
            charStream << line;
            charStream >> X >> Y;
            cout << "x: "<< X << " y: " << Y << endl;
            
            this->muros[numberWalls] = new Muros(X,Y);
            
            tab[X][Y] = 19;
            
            numberWalls++;
        }
        this->numero_muros = numberWalls;
    } else {
        cout << "No hay paredes" << endl;       
    }
    cout << "Cantidad de paredes: " << numero_muros << endl << endl;
    return estado_inicial;
}

Muros** Tablero::get_lista_muros(){
    return muros;
}

int Tablero::get_numero_muros(){
    return numero_muros;
}

// entrada: Estado * estado_inicial, int numero_auto
// salida: Estado*
// aplica A* para solucionar el puzzle hour rush. 
Estado* Tablero::resolver(Estado *estado_inicial, int numero_autos) 
{
    
    Pila open(10); //inicia la pila de estados posibles
    Pila closed(10); //inicia la pila de estados visitados
    Heap ayuda(10);
    open.push(estado_inicial);
    ayuda.push(estado_inicial);
    int cantidad_pasos = 0;
    int cantidad_auristica = 0;
    while(!ayuda.isEmpty()){
       for (int i = 0; i< largo; i++){ //volver a crear el tablero
        tab[i] = new int[6];
        for (int y = 0; y< 6; y++){
            tab[i][y] = 0;

             }
        }

       
        

        
        Estado *e = ayuda.pop(); //obtener el estado actual
        Estado *no_usar = open.pop();
       Car **autos2 = e->get_lista_autos(); 
        int k, x, y,dir, numero, size_auto;
        k = 0;
        while (k< numero_autos){ //añadir los autos a la matris reseteada
                
                x = autos2[k]->get_x();
                y =autos2[k]->get_y();
                numero = autos2[k]->get_numero();
                dir = autos2[k]->get_orientacion();
                size_auto = autos2[k]->get_largo();
            for (int j = 0; j<size_auto;j++){
                    if(dir == 0){
                        tab[x][y+j] = numero;
                    }else{
                        tab[x+j][y] = numero;
                    }
           }

            k++;
        }
        int rudi = 0;
         while( rudi < numero_muros){
            int X = muros[rudi]->get_x();
            int Y = muros[rudi]->get_y();
            tab[X][Y] = 19;
            rudi = rudi + 1; 
        }
        closed.push(e);
        if( e->Final(numero_autos, autos2)){  //revisar si el estado actual es el final
            return (e);
        } 
        int h;
        h = 1;
        bool verificador = false;
        Estado* estado_euristico ;
        int maxima_puntuacion = 0;
        int identificador_puntuacion = 0;
        int posicion_heap = e->get_posicion_heap();
        for(int g = 0; g< numero_autos; g++){ //para recorrer la lista de autos y ver todos los posibles movimientos de cada auto
 

            for(int i = 0; i<4; i++){
                int paso = this->op[i].get_step();
                Estado *nuevo_estado = this->op[i].operacion(e, g, numero_autos); //genera un estado con el movimiento cambiado
                Car *prueba1 = nuevo_estado->get_lista_autos()[g]; 
                int x = prueba1->get_x();
                int y = prueba1->get_y();
                int largo = prueba1->get_largo();
                int numero = prueba1->get_numero();
            
                if(!closed.contiene(nuevo_estado, numero_autos) &&  //filtra los estados para ver cual se puede utilizar y cual no
                   !open.contiene(nuevo_estado, numero_autos) &&
                    nuevo_estado->check(this->tab, x, y, largo, prueba1->get_orientacion(), numero, paso)) {
                    int nueva_posicion_heap = posicion_heap + 1;   
                    nuevo_estado->set_posicion_heap(nueva_posicion_heap); 
                    nuevo_estado->euristica(this->tab, nueva_posicion_heap);
                    ayuda.push(nuevo_estado);
                    open.push(nuevo_estado);
                }
            }
        }
    }
    // si no encuentra la solucion imprime esto y devuelve un puntero nulo
    cout << "no encontre la solucion";
    return nullptr;
}

//entrada: vacio
// salida void
// imprime el estado actual del tablero.
void Tablero::imprimir()
{
    for (int X = 0; X<this->largo; X++){
        for(int Y = 0; Y<this->largo; Y++){
            cout << this->tab[X][Y] << " ";
        }
        cout << endl;
    }
}


