#include <iostream>
using namespace std;

int main(){
    int valor =10;
    int* puntero = &valor;
    cout<<"Valor de la variable:"<<valor<< endl;
    cout<<"Direccion de memoria de la variable:"<<&valor<< endl;
    cout<<"Valor almacenado en el puntero:"<<*puntero<< endl;
    cout<<"Direccion de memoria almacenada en el puntero:"<<puntero<< endl;
    *puntero=20;
    cout<<"Valor modificado de la variable:"<<valor<< endl;

    return 0;
}