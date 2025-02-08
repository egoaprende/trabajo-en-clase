#include <iostream>
using namespace std;

class Punto{
    int x,y;

public:
   Punto(int x = 0, int y =0 ) : x(x), y(y) {}
   Punto operator+(const Punto& p){
    return Punto(x + p.x, y+ p.y);
   } 
void Mostrar() const {
    cout<< "("<<x<<","<<y<<")"<< endl;
}


};

int main(){
    Punto p1(1, 2), p2(3,4);
    Punto p3 = p1 + p2 ;
    cout<< "Resultado de la suma de puntos: ";
    p3.Mostrar();
    return 0;
}