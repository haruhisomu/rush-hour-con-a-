#include "Muros.h"

using namespace std;

int main(){
    Muros muros_prueba(2, 4);
    int X = muros_prueba.get_x();
    int Y = muros_prueba.get_y();

    cout << X;
    cout << Y;
}