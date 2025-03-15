#include <iostream> 
#include <fstream> 

using namespace std;

int main() {
    long valor1 = 200000;
    long valor2;
    long* longPtr;

    longPtr = &valor1;

    ofstream archivo("punteros.txt");
    if (!archivo) {
        return 1;
    }

    archivo << *longPtr << endl;
    valor2 = *longPtr;
    archivo << valor2 << endl;
    archivo << &valor1 << endl;
    archivo << longPtr << endl;

    if (longPtr == &valor1) {
        archivo << "Iguales" << endl;
    } else {
        archivo << "Diferentes" << endl;
    }

    archivo.close();

    return 0;
}
