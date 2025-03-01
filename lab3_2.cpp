#include <iostream>
using namespace std;
int main() {
    int array[5] = {1, 2, 3, 4, 5};
    int* puntero;

    puntero =array;
    cout <<"Direccion de comienzo del array: "<< array <<endl;
    cout <<"Direccion almacenada en el puntero: "<< puntero << endl;
    if (array == puntero) {
        cout <<"La direccion de comienzo del array coincide con el puntero."<<endl;
    } else {
        cout <<"La direccion de comienzo del array NO coincide con el puntero."<<endl;
    }

    return 0;
}