#include <iostream>
using namespace std;

class Figura{
    public:
    virtual void dibujar()=0;
};

class Circulo : public Figura {
    public:
    void dibujar()override {
        cout<<"Dibujando circulo"<< endl;
    }
};

class Cuadrado : public figura{
    void dibujar() override {
        cout<<"Dibujando cuadrado"<< endl;
    }
};

int main(){
    Figura* f1 = new Circulo();
    Figura* f2 = new Cuadrado();

    f1-> dibujar();
    f2-> dibujar();

    delete f1;
    delete f2;

    return 0;
}