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

class Cuadrado : public Figura{
    void dibujar() override {
        cout<<"Dibujando cuadrado"<< endl;
    }
};

class Triangulo : public Figura{
    void dibujar() override {
        cout<<"Dibujando Triangulo"<< endl;
    }
};

int main(){
    Figura* f1 = new Circulo();
    Figura* f2 = new Cuadrado();
    Figura* f3 = new Triangulo();

    f1-> dibujar();
    f2-> dibujar();
    f3-> dibujar();

    delete f1;
    delete f2;
    delete f3;

    return 0;
}