#include <iostream>
using namespace std;

class Calculadora {
    public:
    int sumar(int a, int b) {
        return a + b;
    }

    double sumar(double a, double b) {
        return a + b;
    }

    int sumar(int a, int b, int c) {
        return a + b + c ;
    }

    int dividir(int a, int b) {
        return a / b ;
    }
    double dividir(double a, double b) {
        return a / b;
    }
};

int main(){
    Calculadora calc;
    cout<<"Suma de enteros: "<< calc.sumar(3,5)<< endl;
    cout<<"Suma de decimales: "<< calc.sumar(3.2,5.3)<<endl;
    cout<<"Suma de tres enteros: "<< calc.sumar(3,5,2)<<endl;
    cout<<"Dividir enteros: "<< calc.dividir(2,2)<< endl;
    cout<<"Dividir decimales: "<< calc.dividir(2.3,5.0)<<endl;
    return 0;
}