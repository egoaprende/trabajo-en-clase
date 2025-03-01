#include <iostream>
using namespace std;
int main() {
    int var1 = 10;
    int var2 = 20;
    int* puntero;
    cout <<"Direccion de memoria de var1:"<<&var1 <<endl;
    cout <<"Direccion de memoria de var2:"<<&var2<<endl;

    puntero =&var1;
    cout << "Contenido de la direccion apuntada por puntero (var1):" << *puntero <<endl;
    puntero = &var2;
    cout << "Contenido de la direccion apuntada por puntero (var2):" << *puntero <<endl;

    return 0;
}